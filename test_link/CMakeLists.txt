#==============================================================================
project(mgx_python_testing)
cmake_minimum_required(VERSION 3.15)
#==============================================================================
enable_testing()
find_package(Python COMPONENTS Interpreter REQUIRED)
#==============================================================================
add_test(NAME test_link
        COMMAND ${Python_EXECUTABLE} -m pytest ${CMAKE_CURRENT_SOURCE_DIR}
 )
set_tests_properties(test_link
        PROPERTIES ENVIRONMENT "PYTHONPATH=$ENV{PYTHONPATH}:${CMAKE_INSTALL_PREFIX}/${PYTHON_BINDING_DIR}")

#==============================================================================
