# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

add_library(cdso-lib
             SHARED
             src/main/cpp/Wxr.cpp
             )
find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )
target_link_libraries(cdso-lib log)
ADD_SUBDIRECTORY(src/main/cpp/inshow)
ADD_SUBDIRECTORY(src/main/cpp/native)
#设置生成的so动态库最后输出的路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})