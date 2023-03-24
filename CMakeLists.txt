cmake_minimum_required(VERSION 3.26)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
add_subdirectory(cmake)

glad_add_library(glad_gl_core_32 SHARED API gl:core=3.2)

#glad_add_library(glad_static_lib STATIC
#                LOCATION ${CMAKE_PREFIX_PATH}
#                LANGUAGE CXX
#)
