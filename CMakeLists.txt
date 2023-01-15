cmake_minimum_required(VERSION 3.8.2)
set (CMAKE_CXX_STANDARD 17)
cmake_policy(SET CMP0048 NEW)
project(Vyom-Ground-Station VERSION 1.0.0 LANGUAGES C CXX)

add_subdirectory(lib)
add_subdirectory(ui-qml)