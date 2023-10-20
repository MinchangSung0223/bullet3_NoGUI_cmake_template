cmake_minimum_required(VERSION 3.0)
PROJECT(test_bullet)

#set(BULLET_PHYSICS_SOURCE_DIR  "/home/robot/libraries/bullet3")
#set(BULLET_PHYSICS_LIB "/home/robot/libraries/bullet3/build_cmake/local_install/lib")

add_executable(hello_bullet_cmake src/test.cpp )
target_include_directories(hello_bullet_cmake PUBLIC 
		${BULLET_PHYSICS_SOURCE_DIR}/src
		${BULLET_PHYSICS_SOURCE_DIR}/examples
		${BULLET_PHYSICS_SOURCE_DIR}/examples/SharedMemory
                ${BULLET_INCLUDE_DIR}
                )
target_compile_definitions(hello_bullet_cmake PUBLIC ${BULLET_DEFINITIONS})
target_link_directories(hello_bullet_cmake PUBLIC ${BULLET_PHYSICS_LIB})
target_link_libraries(hello_bullet_cmake PUBLIC BulletDynamics BulletCollision LinearMath BulletRobotics BulletFileLoader BulletWorldImporter BulletSoftBody BulletDynamics BulletCollision BulletInverseDynamicsUtils BulletInverseDynamics LinearMath Bullet3Common)
