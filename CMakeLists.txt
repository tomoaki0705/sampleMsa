# minimum requirement of cmake
cmake_minimum_required(VERSION 2.8)

# set solution name
project(msaSample)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=mips32r5 -mmsa")

# make executable from source file
add_executable(msaSample01HelloWorld   sample01.cpp)
add_executable(msaSample02LoadAndStore sample02.cpp)
add_executable(msaSample03HalfConvert  sample03.cpp)
add_executable(msaSample04Cast         sample04.cpp)
add_executable(msaSample05Fill         sample05.cpp)

