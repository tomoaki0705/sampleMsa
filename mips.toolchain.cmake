# this one is important
SET(CMAKE_SYSTEM_NAME Linux)

# specify the cross compiler
SET(CMAKE_C_COMPILER   /opt/cross/bin/mipsel-linux-gcc-7.1.0)
SET(CMAKE_CXX_COMPILER /opt/cross/bin/mipsel-linux-g++)

# where is the target environment 
#SET(CMAKE_FIND_ROOT_PATH  /opt/cross /opt/cross/mips-linux)
SET(CMAKE_FIND_ROOT_PATH  /opt/cross/mipsel-linux)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

