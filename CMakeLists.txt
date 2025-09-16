cmake_minimum_required(VERSION 3.15)
project(KasperskyTask LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(scannerlib SHARED
    lib/logger.cpp
    lib/md5.cpp
    lib/parser.cpp
    lib/scanner.cpp
)

target_compile_definitions(scannerlib PRIVATE SCANNERLIB_EXPORTS)
target_include_directories(scannerlib PUBLIC include)

add_executable(scannerapp app/main.cpp)

add_custom_command(TARGET scannerapp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:scannerlib>
    $<TARGET_FILE_DIR:scannerapp>
)

target_link_libraries(scannerapp PRIVATE scannerlib)


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TEST_SOURCES tests/*.cpp)

if (TEST_SOURCES)
    add_executable(scanner_tests ${TEST_SOURCES})
    target_link_libraries(scanner_tests
        PRIVATE
            scannerlib
            gtest_main
    )
    include(GoogleTest)
    gtest_discover_tests(scanner_tests)
endif()

