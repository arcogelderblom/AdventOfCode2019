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
add_executable(01-DecemberTest 01-december/test 01-december/FuelRequirementCalculator)

# Create test and executable for december second
add_executable(02-December 02-december/main 02-december/IntcodeComputer common/FileLoader)
add_executable(02-DecemberTest 02-december/test 02-december/IntcodeComputer)

# Create test and executable for december third
add_executable(03-December 03-december/main 03-december/WirePath 03-december/ManhattanDistanceCalculator common/FileLoader)
add_executable(03-DecemberTest 03-december/test 03-december/WirePath 03-december/ManhattanDistanceCalculator)

# Create executable for december four
add_executable(04-December 04-december/main 04-december/PasswordGenerator)
add_executable(04-DecemberTest 04-december/test 04-december/PasswordGenerator)

# Create executable for december five
add_executable(05-December 05-december/main 05-december/IntcodeComputer common/FileLoader)
add_executable(05-DecemberTest 05-december/test 05-december/IntcodeComputer)

target_link_libraries(01-DecemberTest gtest gtest_main)
target_link_libraries(02-DecemberTest gtest gtest_main)
target_link_libraries(03-DecemberTest gtest gtest_main)
target_link_libraries(04-DecemberTest gtest gtest_main)
target_link_libraries(05-DecemberTest gtest gtest_main)

include(GoogleTest)
enable_testing()
gtest_discover_tests(01-DecemberTest)
gtest_discover_tests(02-DecemberTest)
gtest_discover_tests(03-DecemberTest)
gtest_discover_tests(04-DecemberTest)
gtest_discover_tests(05-DecemberTest)
