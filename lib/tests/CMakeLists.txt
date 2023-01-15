set(CMAKE_AUTOMOC ON)

enable_testing()

function(SETUP_TESTS)
       foreach(_testname ${ARGN})
           add_executable(${_testname} tst_${_testname}.cpp)
           set_target_properties(${_testname} PROPERTIES
                WIN32_EXECUTABLE TRUE
                MACOSX_BUNDLE TRUE
           )
           add_test(NAME ${_testname} COMMAND ${_testname})
           target_link_libraries(${_testname} Qt${QT_MAJOR_VERISION}::Test vyom-gs-lib)
       endforeach()
endfunction()

SETUP_TESTS(
    device_file
)

file(COPY test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})