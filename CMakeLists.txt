cmake_minimum_required(VERSION 3.10)


project(CosMain LANGUAGES C CXX)
# project(CosMos)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-fPIC")
set(CMAKE_BUILD_TYPE Release)

# ch8
add_subdirectory(pattern)

set(CODE_CH9
    ThreadPool.hpp
    SyncQueue.hpp
)
source_group("ThreadPool" FILES ${CODE_CH9})

set(CODE_CH10
    Aspect.hpp
)
source_group("AOP" FILES ${CODE_CH10})

set(CODE_CH11
    Ioc.hpp
)
source_group("IOC" FILES ${CODE_CH11})

set(CODE_MAIN
    ${CODE_CH9}
    ${CODE_CH10}
    ${CODE_CH11}
    main.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}") 


file(GLOB sources CONFIGURE_DEPENDS *.hpp *.h *.c *.cpp)
add_executable(CosMain ${CODE_MAIN} ${sources})

find_package(OpenMP REQUIRED)
# target_link_libraries(CosMain PUBLIC OpenMP::OpenMP_CXX)

# find_package(TBB REQUIRED)
# target_link_libraries(main PUBLIC TBB::tbb)
