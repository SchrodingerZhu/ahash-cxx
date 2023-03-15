project(AHashCxx LANGUAGES CXX)
cmake_minimum_required(VERSION 3.20)
add_library(AHashCxx STATIC src/ahash-cxx.cpp)
set_property(TARGET AHashCxx PROPERTY CXX_STANDARD 17)
target_include_directories(AHashCxx PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

function(ahash_cxx_add_test TEST_NAME TEST_FILE)
    add_executable(${TEST_NAME} src/${TEST_FILE})
    set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 17)
    target_include_directories(${TEST_NAME} PRIVATE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
            )
    add_test(${TEST_NAME} ${TEST_NAME})
endfunction()

ahash_cxx_add_test(AHashShuffleTest shuffle-test.cpp)
ahash_cxx_add_test(AHashCxxExtraInfoTest extra-info-test.cpp)
ahash_cxx_add_test(AHashStabilityTest stability-test.cpp)
