cmake_minimum_required(VERSION 3.0)
PROJECT(test_bullet)

set(BULLET_PHYSICS_SOURCE_DIR  "/opt/bullet3")
set(BULLET_PHYSICS_LIB  "/opt/bullet3/build_cmake/local_install/lib")


INCLUDE_DIRECTORIES( 
		${BULLET_PHYSICS_SOURCE_DIR}/src
		${BULLET_PHYSICS_SOURCE_DIR}/examples
		${BULLET_PHYSICS_SOURCE_DIR}/examples/SharedMemory
		${BULLET_PHYSICS_SOURCE_DIR}/examples/ThirdPartyLibs
		${BULLET_PHYSICS_SOURCE_DIR}/examples/ThirdPartyLibs/enet/include
		${BULLET_PHYSICS_SOURCE_DIR}/examples/ThirdPartyLibs/clsocket/src
  )
SET(RobotSimulator_NoGUI_SRCS
  src/test.cpp
)
ADD_EXECUTABLE(hello_bullet_cmake  ${RobotSimulator_NoGUI_SRCS})
#SET_TARGET_PROPERTIES(hello_bullet_cmake PROPERTIES VERSION ${BULLET_VERSION})
#SET_TARGET_PROPERTIES(hello_bullet_cmake PROPERTIES DEBUG_POSTFIX "_d")

TARGET_LINK_LIBRARIES(hello_bullet_cmake BulletRobotics BulletFileLoader BulletWorldImporter BulletSoftBody BulletDynamics BulletCollision BulletInverseDynamicsUtils BulletInverseDynamics LinearMath Bullet3Common)
target_compile_definitions(hello_bullet_cmake PUBLIC -DBT_USE_DOUBLE_PRECISION)
IF(WIN32)
	IF(BUILD_ENET OR BUILD_CLSOCKET)
		TARGET_LINK_LIBRARIES(App_RobotSimulator_NoGUI ws2_32 Winmm)
	ENDIF(BUILD_ENET OR BUILD_CLSOCKET)
ELSE()
	IF(APPLE)
	ELSE(APPLE)
		FIND_PACKAGE(Threads)
		LINK_LIBRARIES( ${CMAKE_THREAD_LIBS_INIT} ${DL} )
	ENDIF(APPLE)
ENDIF(WIN32)
# target_include_directories(hello_bullet_cmake PUBLIC 
# 		${BULLET_PHYSICS_SOURCE_DIR}
# 		${BULLET_PHYSICS_SOURCE_DIR}/src
# 		${BULLET_PHYSICS_SOURCE_DIR}/examples
# 		${BULLET_PHYSICS_SOURCE_DIR}/examples/SharedMemory
# 		${BULLET_PHYSICS_SOURCE_DIR}/examples/RobotSimulator
# 		${BULLET_PHYSICS_SOURCE_DIR}/examples/ThirdPartyLibs
# 		${BULLET_PHYSICS_SOURCE_DIR}/examples/ThirdPartyLibs/enet/include
# 		${BULLET_PHYSICS_SOURCE_DIR}/examples/ThirdPartyLibs/clsocket/src		
#                 ${BULLET_INCLUDE_DIR}
#                 )
# target_compile_definitions(hello_bullet_cmake PUBLIC ${BULLET_DEFINITIONS})
# #target_link_directories(hello_bullet_cmake PUBLIC ${BULLET_PHYSICS_LIB})
# find_package(Threads)
# target_link_libraries(hello_bullet_cmake  BulletRobotics BulletFileLoader BulletWorldImporter BulletSoftBody BulletDynamics BulletCollision BulletInverseDynamicsUtils BulletInverseDynamics LinearMath Bullet3Common ${CMAKE_THREAD_LIBS_INIT} ${DL})

