project(AHashCxx LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_library(AHashCxx INTERFACE include/ahash-cxx/arch/ssse3.h)
target_include_directories(AHashCxx INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
