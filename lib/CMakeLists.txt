cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
set (CMAKE_CXX_STANDARD 17)
project(vyom-gs-lib VERSION 1.0.0 LANGUAGES C CXX)

###########################
# Dependencies
find_package(Qt6 COMPONENTS Core Gui Test REQUIRED)

###########################
# Targets
add_library(${PROJECT_NAME} STATIC
  src/models/DummyData.cpp
  public/models/DummyData.hpp
  "src/devices/CSVFile.cpp"
 "src/utils/CSVHandler.cpp")

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:
      public
      public/controllers
      public/models
     >
    $<BUILD_INTERFACE:
      ${CMAKE_CURRENT_SOURCE_DIR}/public
      ${CMAKE_CURRENT_SOURCE_DIR}/public/controllers
      ${CMAKE_CURRENT_SOURCE_DIR}/public/models
     >
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/rapidcsv/src
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    VYOM_GS_LIBRARY
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt6::Core
    Qt6::Gui
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_17
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_subdirectory(tests)
