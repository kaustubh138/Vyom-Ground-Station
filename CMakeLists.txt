cmake_minimum_required(VERSION 3.8.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Vyom-Ground-Station VERSION 1.0.0 LANGUAGES C CXX)

add_subdirectory(lib)
add_subdirectory(ui-qml)
