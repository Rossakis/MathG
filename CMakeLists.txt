cmake_minimum_required(VERSION 3.28)
project(MathG)

set(CMAKE_CXX_STANDARD 20)

# Include directories for MathG library
include_directories(include)

# Add source files
set(SOURCES
        src/main.cpp
        include/matrix.h
        include/vector.h
)

# Create MathG library
add_library(MathG ${SOURCES})

# Link MathG library with the main executable
add_executable(main src/main.cpp)

target_link_libraries(main MathG)
