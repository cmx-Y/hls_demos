cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCL REQUIRED)
find_package(XRT REQUIRED)

message("yes" ${OpenCL_LIBRARIES})

if(NOT XRT_FOUND)
  MESSAGE(FATAL_ERROR "XRT not found, please source XRT setup script before building")
endif()


# Library of utility functions common to all applications
add_library(example_utils STATIC
  sw_src/event_timer.cpp
  sw_src/xilinx_ocl_helper.cpp
)

target_include_directories(example_utils PUBLIC
  ${XRT_INCLUDE_DIRS}
  ${OpenCL_INCLUDE_DIRS}
)

# Simple malloc example
add_executable(01_simple_malloc
  sw_src/01_simple_malloc.cpp)

target_include_directories(01_simple_malloc PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/sw_src
  ${XRT_INCLUDE_DIRS}
  ${OpenCL_INCLUDE_DIRS}
  )

target_link_libraries(01_simple_malloc PRIVATE
  ${XRT_LIBS}
  ${OpenCL_LIBRARIES}
  pthread
  uuid
  ${CMAKE_DL_LIBS}
  example_utils
  )
