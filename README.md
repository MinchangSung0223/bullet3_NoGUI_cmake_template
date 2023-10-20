# bullet3_NoGUI_cmake_template
# bullet3 install
```bash
  git clone https://github.com/bulletphysics/bullet3.git
  cd bullet3
  export BULLET_PHYSICS_SOURCE_DIR=${PWD}
  ./build_cmake_pybullet_double.sh
  cd build_cmake
  sudo make install
```
```bash
mkdir build
cd build
cmake .. -DBULLET_PHYSICS_SOURCE_DIR=/path/to/bullet3 -DBULLET_PHYSICS_LIB=/usr/lib
```
