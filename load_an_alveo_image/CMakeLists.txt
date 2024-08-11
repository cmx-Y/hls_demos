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
  src/event_timer.cpp
  src/xilinx_ocl_helper.cpp
)

target_include_directories(example_utils PUBLIC
  ${XRT_INCLUDE_DIRS}
  ${OpenCL_INCLUDE_DIRS}
)

# Basic kernel load/unload example
add_executable(00_load_kernels
  src/00_load_kernels.cpp)

target_include_directories(00_load_kernels PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${XRT_INCLUDE_DIRS}
  ${OpenCL_INCLUDE_DIRS}
  )

target_link_libraries(00_load_kernels PRIVATE
  ${XRT_LIBS}
  ${OpenCL_LIBRARIES}
  pthread
  uuid
  ${CMAKE_DL_LIBS}
  example_utils
  )
