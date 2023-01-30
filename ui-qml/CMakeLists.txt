cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(vyom-gs-ui VERSION 1.0.0 LANGUAGES C CXX)

###########################
# Dependencies

find_package(Qt6 COMPONENTS Core Gui Qml Quick QuickControls2 Widgets REQUIRED)

###########################
# Targets

add_executable(${PROJECT_NAME}
    src/main.cpp
    res.qrc
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

target_compile_options(${PROJECT_NAME}
  PUBLIC
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_17
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    AUTORCC ON
)

include_directories(${CMAKE_SOURCE_DIR}/lib/public/)
