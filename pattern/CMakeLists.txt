cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

set(CODE_CH8
    Command.hpp
    ObjectPool.hpp
    test.cpp # require at least one cpp file
)

add_library(pattern SHARED ${CODE_CH8})
find_package(OpenMP REQUIRED)
target_link_libraries(pattern PUBLIC OpenMP::OpenMP_CXX)
# target_compile_options(pattern PRIVATE ${OpenMP_CXX_FLAGS})

# find_package(TBB REQUIRED)
# target_link_libraries(main PUBLIC TBB::tbb)
