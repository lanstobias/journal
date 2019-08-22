cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(journal_project)
set(CMAKE_CXX_STANDARD 17)

###############################################################################
## File globbing
file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE includes includes/*.hpp)
file(GLOB_RECURSE tests test/*.cpp)

###############################################################################
## Target definitions

# Add the data to the target, so it becomes visible in some IDE
add_executable(journal ${sources})

# Compiler flags
target_compile_options(journal PUBLIC -Wall -Wfloat-conversion)

###############################################################################
## Dependencies

# Boost
find_package(Boost 1.70.0 COMPONENTS filesystem system REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

# Catch2
add_subdirectory(third_party/catch2)

## Link targets
target_link_libraries(journal
    PUBLIC
        ${Boost_LIBRARIES}
)

#############################################
## Unit tests
enable_testing()
add_executable(unit_tests ${tests})
target_link_libraries(unit_tests Catch2::Test)

add_test(test_all unit_tests)
