cmake_minimum_required(VERSION 3.28)
project(MathG)

set(CMAKE_CXX_STANDARD 20)

# Include directories for MathG library
include_directories(include)

# Add source files
set(SOURCES
        src/main.cpp
)

# Create MathG library
add_library(MathG ${SOURCES})

# Set the library output properties
set_target_properties(MathG PROPERTIES
        OUTPUT_NAME "MathG"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Platform-specific settings
if(WIN32)
    target_compile_definitions(MathG PRIVATE -DWIN32)
elseif(APPLE)
    target_compile_definitions(MathG PRIVATE -DAPPLE)
endif()

# Link MathG library with the main executable
add_executable(main src/main.cpp)

target_link_libraries(main MathG)
