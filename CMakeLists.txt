cmake_minimum_required(VERSION 3.7.2)
project(WireMag)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-souce builds are not allowed.
           You should creat a seperate directory for build files.
	   ")
endif()
	 
include_directories(include)
file(GLOB SOURCES src/*.cc)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

add_executable(run ${SOURCES})


set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/testInstall)
message("CMAKE_INSTALL_PREFIX setted to ${CMAKE_INSTALL_PREFIX}")

install(TARGETS run DESTINATION ${CMAKE_INSTALL_PREFIX})
