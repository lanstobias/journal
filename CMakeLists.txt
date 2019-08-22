cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(journal_project)
set(CMAKE_CXX_STANDARD 17)

###############################################################################
## Dependencies

# Boost
find_package(Boost 1.70.0 COMPONENTS filesystem system REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

# Catch2
add_subdirectory(third_party/catch2)

# Libraries
add_library(Libs SHARED
    src/Menu.cpp
    src/UserInput.cpp
    src/Helpers.cpp
)

#############################################
## Unit tests
enable_testing()
add_test(test_all unit_tests)

###############################################################################
## Create executables

# Main program
add_executable(journal
    src/Date.cpp
    src/Entry.cpp
    src/FileHandler.cpp
    src/Helpers.cpp
    src/Journal.cpp
    src/Menu.cpp
    src/UserInput.cpp
    src/main.cpp
)
target_compile_options(journal PUBLIC -Wall -Wfloat-conversion)
target_include_directories(journal PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Test program
add_executable(unit_tests
    test/test.cpp    
    test/testMenu.cpp
)

#############################################
## Link
target_link_libraries(journal
    Libs
    ${Boost_LIBRARIES}
)

# TODO: Fix linking of header files for tests
target_link_libraries(unit_tests
    Libs
    Catch2::Test
)
