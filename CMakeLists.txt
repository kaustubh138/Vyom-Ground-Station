cmake_minimum_required(VERSION 3.8.2)

project(Vyom-Ground-Station VERSION 1.0.0 LANGUAGES C CXX)

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release;RelWithDebInfo;MinSizeRel;Coverage")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Qt version: ${QT_VERSION}")

set(COMPANY "Team Vyom Space")
set(COPYRIGHT "Copyright (c) 2023 Team Vyom Space. All rights reserved.")

add_definitions(
	-DVGS_APPLICATION="Vyom-Ground-Station"
	-DORG_NAME="Team Vyom Space"
)

message(STATUS "Vyom-Ground-Station version: 1.0.0")

add_subdirectory(lib)
add_subdirectory(ui-qml)

###########################
# Dependencies

find_package(Qt6 COMPONENTS Core Gui Qml Quick QuickControls2 Widgets REQUIRED)

###########################
# Targets

add_executable(${PROJECT_NAME}
    "main.cpp"
    "ui-qml/res.qrc"
)

target_include_directories(${PROJECT_NAME}
  PUBLIC src
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    vyom-gs-lib
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_20
)


include_directories(lib/public/)