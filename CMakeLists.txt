cmake_minimum_required(VERSION 3.0)
project(file_client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp controller.cpp includes/controller.h includes/utilities.h requestListener.h requestListenerTCP.cpp requestListenerTCP.h fileUtils.cpp fileUtils.h)

add_executable(file_client ${SOURCE_FILES})

add_compile_definitions(DEBUG)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "G:\\SFML-2.5.1-x64\\lib\\cmake\\SFML")
find_package(SFML COMPONENTS system network)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} sfml-system sfml-network -static-libgcc -static-libstdc++)
endif()

set(CMAKE_INSTALL_PREFIX "C:/")
install(TARGETS file_client EXPORT file_client DESTINATION file_client_install)