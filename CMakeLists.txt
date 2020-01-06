cmake_minimum_required(VERSION 3.11)

project(AdventOfCode2019)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(common)
link_directories(lib)

# Create test for the common directory
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

# Create test and executable for december four
add_executable(04-December 04-december/main 04-december/PasswordGenerator)
add_executable(04-DecemberTest 04-december/test 04-december/PasswordGenerator)

# Create test and  executable for december five
add_executable(05-December 05-december/main 05-december/IntcodeComputer common/FileLoader)
add_executable(05-DecemberTest 05-december/test 05-december/IntcodeComputer)

# Create test and  executable for december six
add_executable(06-December 06-december/main 06-december/SpaceNavigation common/FileLoader)
add_executable(06-DecemberTest 06-december/test 06-december/SpaceNavigation)

# Create test and  executable for december seven
add_executable(07-December 07-december/main 07-december/IntcodeComputer 07-december/AmplificationComputers common/FileLoader)
add_executable(07-DecemberTest 07-december/test 07-december/IntcodeComputer 07-december/AmplificationComputers)

# Create test and executable for december eight
add_executable(08-December 08-december/main 08-december/Picture common/FileLoader)
add_executable(08-DecemberTest 08-december/test 08-december/Picture)

# Create test and executable for december nine
add_executable(09-December 09-december/main 09-december/IntcodeComputer common/FileLoader)
add_executable(09-DecemberTest 09-december/test 09-december/IntcodeComputer)

# Create test and executable for december ten
add_executable(10-December 10-december/main 10-december/MonitorStationLocation common/FileLoader)
add_executable(10-DecemberTest 10-december/test 10-december/MonitorStationLocation)

# Create test and executable for december eleven
add_executable(11-December 11-december/main 11-december/IntcodeComputer 11-december/EmergencyHullPaintingRobot common/FileLoader)
add_executable(11-DecemberTest 11-december/test 11-december/IntcodeComputer 11-december/EmergencyHullPaintingRobot)

# Create test and executable for december twelve
add_executable(12-December 12-december/main 12-december/MoonPositionCalculator common/FileLoader)
add_executable(12-DecemberTest 12-december/test 12-december/MoonPositionCalculator)

# Create test and executable for december thirteen
add_executable(13-December 13-december/main 13-december/IntcodeComputer 13-december/ArcadeCabinet common/FileLoader)
add_executable(13-DecemberTest 13-december/test 13-december/IntcodeComputer 13-december/ArcadeCabinet)

# Create test and executable for december fourteen
add_executable(14-December 14-december/main 14-december/NanoFactory common/FileLoader)
add_executable(14-DecemberTest 14-december/test 14-december/NanoFactory)

target_link_libraries(01-DecemberTest gtest gtest_main)
target_link_libraries(02-DecemberTest gtest gtest_main)
target_link_libraries(03-DecemberTest gtest gtest_main)
target_link_libraries(04-DecemberTest gtest gtest_main)
target_link_libraries(05-DecemberTest gtest gtest_main)
target_link_libraries(06-DecemberTest gtest gtest_main)
target_link_libraries(07-DecemberTest gtest gtest_main)
target_link_libraries(08-DecemberTest gtest gtest_main)
target_link_libraries(09-DecemberTest gtest gtest_main)
target_link_libraries(10-DecemberTest gtest gtest_main)
target_link_libraries(11-DecemberTest gtest gtest_main)
target_link_libraries(12-DecemberTest gtest gtest_main)
target_link_libraries(13-DecemberTest gtest gtest_main)
target_link_libraries(14-DecemberTest gtest gtest_main)

include(GoogleTest)
enable_testing()
gtest_discover_tests(01-DecemberTest)
gtest_discover_tests(02-DecemberTest)
gtest_discover_tests(03-DecemberTest)
gtest_discover_tests(04-DecemberTest)
gtest_discover_tests(05-DecemberTest)
gtest_discover_tests(06-DecemberTest)
gtest_discover_tests(07-DecemberTest)
gtest_discover_tests(08-DecemberTest)
gtest_discover_tests(09-DecemberTest)
gtest_discover_tests(10-DecemberTest)
gtest_discover_tests(11-DecemberTest)
gtest_discover_tests(12-DecemberTest)
gtest_discover_tests(13-DecemberTest)
gtest_discover_tests(14-DecemberTest)
