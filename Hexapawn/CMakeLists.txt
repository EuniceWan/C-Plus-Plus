cmake_minimum_required(VERSION 3.3)
project(hexapawn CXX)
include(.ipd/CMakeLists.txt)

add_test_program(hexapawn
        test/test.cpp
        src/hexapawn.h
        src/hexapawn.cpp )


add_program(hexapawn_without_test
        src/hexapawn.h
        src/hexapawn.cpp
        src/main.cpp)