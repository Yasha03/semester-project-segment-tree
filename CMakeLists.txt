cmake_minimum_required(VERSION 3.21)
project(semestrovka)

set(CMAKE_CXX_STANDARD 14)

add_executable(semestrovka main.cpp src/node.h src/segment_tree.cpp src/segment_tree.h src/test_generator.cpp src/test_generator.h src/tester.cpp src/tester.h)
