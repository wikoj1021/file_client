cmake_minimum_required(VERSION 3.12)
project(file_client)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -g3")

set(SOURCE_FILES main.cpp controller.cpp includes/controller.h includes/utilities.h)

add_executable(file_client ${SOURCE_FILES})

add_compile_definitions(DEBUG)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "F:\\SFML-2.5.1\\lib\\cmake\\SFML")
find_package(SFML COMPONENTS network)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} sfml-window sfml-graphics)
endif()