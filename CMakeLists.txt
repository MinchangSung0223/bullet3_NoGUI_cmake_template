cmake_minimum_required(VERSION 3.0)
PROJECT(test_bullet)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(FindPkgConfig)
include(modules/CMakeFunctions.cmake)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(PROJ_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/bin/inc)
set(PROJ_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(PROJ_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_DEBUG_POSTFIX "d")
set(CMAKE_MODULE_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/modules)
set(BUILD_SHARED_LIBS TRUE)

SET(RobotSimulator_NoGUI_SRCS
  src/test.cpp
)
ADD_EXECUTABLE(hello_bullet_cmake  ${RobotSimulator_NoGUI_SRCS})

# Bullet
find_package(Bullet)
if (BULLET_FOUND)
	MESSAGE(STATUS "BULLET_INCLUDE_DIRS = ${BULLET_INCLUDE_DIRS}")
	MESSAGE(STATUS "BULLET_LIBRARIES = ${BULLET_LIBRARIES}")
	target_include_directories(hello_bullet_cmake PUBLIC ${BULLET_INCLUDE_DIRS})
	target_link_libraries(hello_bullet_cmake ${BULLET_LIBRARIES})
endif()

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

