
#include "b3RobotSimulatorClientAPI_NoGUI.h"
#include "b3RobotSimulatorClientAPI_InternalData.h"
#include "../Utils/b3Clock.h"

#include <string.h>
#include <stdio.h>
#include <assert.h>
#define ASSERT_EQ(a, b) assert((a) == (b));

int main(int argc, char* argv[])
{

	b3RobotSimulatorClientAPI_NoGUI* sim = new b3RobotSimulatorClientAPI_NoGUI();
	bool isConnected = sim->connect(eCONNECT_DIRECT);
	sim->resetSimulation();
	sim->setGravity(btVector3(0, 0, -9.8));
	sim->setNumSolverIterations(100);
	b3RobotSimulatorSetPhysicsEngineParameters args;
	double CONTROL_RATE = 1000.0;
	btScalar fixedTimeStep = 1. / CONTROL_RATE;
	sim->setTimeStep(fixedTimeStep);	
	sim->getPhysicsEngineParameters(args);

	int planeUid = sim->loadURDF("../urdf/plane/plane.urdf");
	printf("planeUid = %d\n", planeUid);	
	
	double time = 0.0;
	double dt = fixedTimeStep;

	static int print_cnt =0;
	while (sim->isConnected())
	{
		time+=dt;
		if (++print_cnt>=1000){
				printf("%.3f\n",time);
				print_cnt = 0;
		}
		sim->stepSimulation();
		b3Clock::usleep(1000. * 1000. * fixedTimeStep);
	}	
	printf("exit\n");
	delete sim;
}

