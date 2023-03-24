add_subdirectory(cmake)

glad_add_library(glad_static_lib STATIC
                LOCATION ${CMAKE_PREFIX_PATH}
                LANGUAGE CXX
)
