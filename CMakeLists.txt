cmake_minimum_required(VERSION 3.12)
project(file_client)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

add_executable(file_client ${SOURCE_FILES})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR )
find_package(SFML COMPONENTS network)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} sfml-window sfml-graphics)
endif()