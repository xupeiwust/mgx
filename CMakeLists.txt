#======================================================================================================================
cmake_minimum_required (VERSION 3.15)

project(MGX CXX C)

set (Magix3D_VERSION ${MAGIX3D_VERSION})

set (CMAKE_VERBOSE_MAKEFILE ON)
#======================================================================================================================
# Options that are proposed to build the project using Cmake Build system
#======================================================================================================================
option (BUILD_SHARED_LIBS "create dynamic libraries (default : ON)" ON)
option (BUILD_MAGIX3D "Build the whole MGX Application, including Gui and python binding (default : ON)" ON)
option (USE_TRITON "Build the TRITON component (default : ON)" ON)
#Next options are only available on-site. Default value is so OFF.
option (USE_DKOC "On-site. Build the DKOC component to read Catia files (on-site, default : OFF)" OFF)
option (USE_MDLPARSER "Build the mdl parser to read the 2D mdl format (on-site, default : OFF)" OFF)
option (USE_MESHGEMS "Build the MeshGems component to access tri/tet meshing functionalities (on-site, default : OFF)" OFF)
option (USE_SEPA3D "Build the SEPA3D component (on-site, default : OFF)" OFF)
option (USE_SMOOTH3D "Build the SMOOTH3D component (on-site, default : OFF)" OFF)
#======================================================================================================================
#tell cmake to generate the configure file that will be used to activate the previous option C++ balise in the code
configure_file(
		${PROJECT_SOURCE_DIR}/cmake/config.h.in
		${PROJECT_BINARY_DIR}/mgx_config.h
)
include_directories(${PROJECT_BINARY_DIR})
#======================================================================================================================
include (GNUInstallDirs)
include (cmake/version.cmake)
include (cmake/common.cmake)
#======================================================================================================================
#Source directories
message (STATUS "===============> MGX utilities")
add_subdirectory (VtkComponents)
add_subdirectory (Utils)
add_subdirectory (GMSH)
message (STATUS "===============> MGX Kernel")
add_subdirectory (Core)
message (STATUS "===============> MGX Python binding")
add_subdirectory (pyMagix3D)
message (STATUS "===============> PGX GUI")
add_subdirectory (QtComponents)
add_subdirectory (QtVtkComponents)
if (BUILD_MAGIX3D)
	message (STATUS "===============> Full MGX interactive application")
	add_subdirectory (Magix3D)
endif ( )
message (STATUS "===============> End of compiling stage")
