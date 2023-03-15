project(AHashCxx LANGUAGES CXX)
cmake_minimum_required(VERSION 3.20)
add_library(AHashCxx STATIC src/ahash-cxx.cpp)
set_property(TARGET AHashCxx PROPERTY CXX_STANDARD 17)
target_include_directories(AHashCxx PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

add_executable(AHashCxxShuffleTest src/shuffle-test.cpp)
set_property(TARGET AHashCxxShuffleTest PROPERTY CXX_STANDARD 17)
target_include_directories(AHashCxxShuffleTest PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

add_executable(AHashCxxExtraInfoTest src/extra-info-test.cpp)
set_property(TARGET AHashCxxExtraInfoTest PROPERTY CXX_STANDARD 17)
target_include_directories(AHashCxxExtraInfoTest PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
