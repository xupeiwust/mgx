#==============================================================================
cmake_minimum_required(VERSION 3.15)
#==============================================================================
enable_testing()
find_package(Python COMPONENTS Interpreter REQUIRED)
#==============================================================================
add_test(NAME test_link
        COMMAND ${Python_EXECUTABLE} -m pytest ${CMAKE_CURRENT_SOURCE_DIR} -v
 )
set_tests_properties(test_link
        PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_INSTALL_LIBDIR}:$ENV{PYTHONPATH}")
#==============================================================================
