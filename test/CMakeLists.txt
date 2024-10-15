cmake_minimum_required(VERSION 3.10)

project(test LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-fPIC")
#set(CMAKE_BUILD_TYPE Debug) #Release

# MD
# MDd
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_executable(${PROJECT_NAME} 
		AspectTest.cpp
		IocTest.cpp
		main.cpp)
target_link_libraries(${PROJECT_NAME} gtest)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

# message(STATUS "includeDir = ${includeDir}") 