# FindStb.cmake
# Try to locate the stb headers
find_path(STB_INCLUDE_DIRS "stb.h")

if (STB_INCLUDE_DIRS)
    set(STB_FOUND TRUE)
    message(STATUS "Found stb at ${STB_INCLUDE_DIRS}")
else()
    set(STB_FOUND FALSE)
    message(WARNING "Could not find stb")
endif()

# Set STB_INCLUDE_DIRS to be accessible from other parts
mark_as_advanced(STB_INCLUDE_DIRS)
