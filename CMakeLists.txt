cmake_minimum_required(VERSION 3.1)

project(atum)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(external/glm)
include_directories(external/glm)



#-------------------------------------------------------------------------------
#	SOURCE CODE
#-------------------------------------------------------------------------------

include_directories(src)

# .h files
list(APPEND HEADER_FILES
src/utils/Math.h
src/intersection/Ray.h
src/shapes/Shape.h
src/shapes/Sphere.h
src/shapes/Triangle.h
src/intersection/Interaction.h
)

# .cpp files
list(APPEND SOURCE_FILES
src/utils/Math.cpp
src/intersection/Ray.cpp
src/shapes/Sphere.cpp
src/shapes/Triangle.cpp
src/intersection/Interaction.cpp
src/main.cpp
)



# on windows, append headers to source so they show up in visual studio
# We need to check what happens in QT creator
#if(WIN32)
        LIST(APPEND SOURCE_FILES ${HEADER_FILES})
#endif()

add_library(atum STATIC ${SOURCE_FILES})

#-------------------------------------------------------------------------------
#	TESTING using Google Test
#-------------------------------------------------------------------------------

# If windows just fix the linking problem
if (WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif (WIN32)

add_subdirectory(external/google-test)

enable_testing()

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(test/Shapes)

add_executable("${PROJECT_NAME}_main" src/main.cpp ${RESOURCES})
# Standard linking to gtest stuff.
target_link_libraries("${PROJECT_NAME}_main" atum)
