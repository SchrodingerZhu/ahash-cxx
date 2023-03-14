project(AHashCxx LANGUAGES CXX)
add_library(AHashCxx STATIC src/ahash-cxx.cpp)
target_compile_options(AHashCxx PRIVATE "-march=armv9-a+aes+sve2-aes")
set_property(TARGET AHashCxx PROPERTY CXX_STANDARD 17)
target_include_directories(AHashCxx PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

add_executable(AHashCxxShuffleTest src/shuffle-test.cpp)
target_compile_options(AHashCxxShuffleTest PRIVATE "-march=armv8-a+aes")
set_property(TARGET AHashCxxShuffleTest PROPERTY CXX_STANDARD 17)
target_include_directories(AHashCxxShuffleTest PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
