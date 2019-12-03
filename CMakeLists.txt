cmake_minimum_required(VERSION 3.11)

project(AdventOfCode2019)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(common)
link_directories(lib)

# Create test executable for the common directory
add_executable(CommonTest common/test common/FileLoader)
target_link_libraries(CommonTest gtest gtest_main)
add_test(CommonTest CommonTest)

# Create test and executable for december first
add_executable(01-December 01-december/main 01-december/FuelRequirementCalculator common/FileLoader)
add_executable(01-DecemberTest 01-december/test 01-december/FuelRequirementCalculator common/FileLoader)
target_link_libraries(01-DecemberTest gtest gtest_main)
add_test(01-DecemberTest 01-DecemberTest)

# Create test and executable for december second
add_executable(02-December 02-december/main 02-december/IntcodeComputer common/FileLoader)
add_executable(02-DecemberTest 02-december/test 02-december/IntcodeComputer common/FileLoader)
target_link_libraries(02-DecemberTest gtest gtest_main)
add_test(02-DecemberTest 02-DecemberTest)
