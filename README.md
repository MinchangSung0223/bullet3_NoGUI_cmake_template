# bullet3_NoGUI_cmake_template
# bullet3 install
```bash
  git clone https://github.com/bulletphysics/bullet3.git
  cd bullet3  
  echo 'export BULLET_PHYSICS_SOURCE_DIR=' echo ${PWD} >> ~/.bashrc
  ./build_cmake_pybullet_double.sh
  cd build_cmake
  cmake  -DUSE_DOUBLE_PRECISION=ON -DCMAKE_DEBUG_POSTFIX="" -DINSTALL_LIBS=ON -DCMAKE_BUILD_TYPE=Release  -DCMAKE_INSTALL_PREFIX:PATH=local_install  ..
  make -j$(nproc)
  sudo make install
  cd local_install/lib
  echo 'export BULLET_PHYSICS_LIB=' echo ${PWD} >> ~/.bashrc
```
```bash
mkdir build
cd build
cmake .. -DBULLET_PHYSICS_SOURCE_DIR=${BULLET_PHYSICS_SOURCE_DIR} -DBULLET_PHYSICS_LIB=${BULLET_PHYSICS_LIB}
```
