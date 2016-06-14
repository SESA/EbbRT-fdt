cmake_minimum_required(VERSION 2.6)

# This must be before the project() command so cmake finds our platform
# definition
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")

# This skips compiler verification which will fail because we haven't finished
# installing the necessary libraries
set(CMAKE_C_COMPILER_WORKS 1)

project(Fdt C)

# Initialize CFLAGS.
set(CMAKE_C_FLAGS                "-Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG          "-O0 -g3")
set(CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_C_FLAGS_RELEASE        "-O4 -flto -DNDEBUG")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g3")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(fdt STATIC
  ${CMAKE_SOURCE_DIR}/fdt_sw.c
  ${CMAKE_SOURCE_DIR}/fdt_strerror.c
  ${CMAKE_SOURCE_DIR}/fdt.c
  ${CMAKE_SOURCE_DIR}/fdt_wip.c
  ${CMAKE_SOURCE_DIR}/fdt_rw.c
  ${CMAKE_SOURCE_DIR}/fdt_ro.c
  )

install(TARGETS fdt
  ARCHIVE DESTINATION lib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include
  FILES_MATCHING PATTERN "*.h")
