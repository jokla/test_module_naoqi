# In CMakeLists.txt

cmake_minimum_required(VERSION 2.8)
project(test_module)
find_package(qibuild)

include_directories(".")
qi_create_bin(myservice main.cpp myservice.hpp myservice.cpp)
qi_use_lib(myservice QI)
