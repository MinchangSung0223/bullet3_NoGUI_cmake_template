#include "SharedMemory/b3RobotSimulatorClientAPI_NoGUI.h"
#include "Utils/b3Clock.h"
#include "LinearMath/btVector3.h"
#include "btBulletDynamicsCommon.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <thread>
#define ASSERT_EQ(a, b) assert((a) == (b));

int main(int argc, char* argv[])
{

	b3RobotSimulatorClientAPI_NoGUI* sim = new b3RobotSimulatorClientAPI_NoGUI();
	bool isConnected = sim->connect(eCONNECT_DIRECT);
	if (!isConnected)
	{
		printf("Cannot connect\n");
		return -1;
	}
	sim->configureDebugVisualizer(COV_ENABLE_GUI, 0);
	sim->setTimeOut(10);
	sim->syncBodies();	
	double CONTROL_RATE = 240.0;
	btScalar fixedTimeStep = 1. / CONTROL_RATE;
	sim->setTimeStep(fixedTimeStep);

	
	btQuaternion q = sim->getQuaternionFromEuler(btVector3(0.1, 0.2, 0.3));
	//btVector3 rpy;
	//rpy = sim->getEulerFromQuaternion(q);

	sim->setGravity(btVector3(0, 0, -9.8));
	//b3RobotSimulatorSetPhysicsEngineParameters args;
	
	//btScalar fixedTimeStep = 1. / CONTROL_RATE;
	//sim->setTimeStep(fixedTimeStep);	
	//sim->getPhysicsEngineParameters(args);
	int robotId = sim->loadURDF("../urdf/satellite/arm.urdf");
	sim->setRealTimeSimulation(false);
	
	
	printf("robotId = %d\n", robotId);	
	printf("robotId #joints = %d\n",sim->getNumJoints(robotId));
	printf("isconnected : %d\n",sim->isConnected());
	double time = 0.0;
	double dt = fixedTimeStep;

	static int print_cnt =0;
	while (sim->canSubmitCommand())
	{

    	b3JointSensorState jointStates;
	    bool isState = sim->getJointState(robotId,1, &jointStates);
    

		time+=dt;
		if (++print_cnt>=60){
				printf("%.3f\n",time);
				std::cout<<isState<<","<<jointStates.m_jointPosition<<std::endl;

				print_cnt = 0;
		}
		sim->stepSimulation();
		b3Clock::usleep(1000. * 1000. * fixedTimeStep);
	}	
	printf("exit\n");
	delete sim;
}

