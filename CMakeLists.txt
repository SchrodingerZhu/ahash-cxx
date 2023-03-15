project(AHashCxx LANGUAGES CXX)
cmake_minimum_required(VERSION 3.20)
add_library(AHashCxx STATIC src/ahash-cxx.cpp)
set_property(TARGET AHashCxx PROPERTY CXX_STANDARD 17)
target_include_directories(AHashCxx PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
option(AHASH_CXX_ENABLE_TESTS OFF)

function(ahash_cxx_add_test TEST_NAME TEST_FILE)
    add_executable(${TEST_NAME} src/${TEST_FILE})
    set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 17)
    target_include_directories(${TEST_NAME} PRIVATE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
            )
    add_test(${TEST_NAME} ${TEST_NAME})
endfunction()

if (AHASH_CXX_ENABLE_TESTS)
    ahash_cxx_add_test(AHashCxxShuffleTest shuffle-test.cpp)
    ahash_cxx_add_test(AHashCxxExtraInfoTest extra-info-test.cpp)
    ahash_cxx_add_test(AHashCxxStabilityTest stability-test.cpp)
endif()
