# CMakeLists.txt in the "Class" directory

# Add source files
set(SOURCE_FILES
    splay_tree.cpp
)

# Create a library
add_library(ClassLib ${SOURCE_FILES})

# Include directories
target_include_directories(ClassLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
