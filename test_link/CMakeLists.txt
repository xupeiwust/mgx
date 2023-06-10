#==============================================================================
enable_testing()
find_package(GTest REQUIRED)
find_package(Python COMPONENTS Interpreter REQUIRED)

add_test(NAME test_link
        COMMAND ${Python_EXECUTABLE} -m pytest ${CMAKE_CURRENT_SOURCE_DIR} ${TEST_SAMPLES_DIR}
 )
set_tests_properties(test_link
        PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_BINARY_DIR}/pyMagix3D:$ENV{PYTHONPATH}")


#==============================================================================
