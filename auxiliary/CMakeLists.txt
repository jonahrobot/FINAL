cmake_minimum_required(VERSION 3.14)

project(createRandomImage)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

# Add executables
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/random_image.cpp
)
target_link_libraries(createRandomImage ${PNG_LIBRARY})