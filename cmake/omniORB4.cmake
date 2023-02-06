#
# Charge le pkgconfig omniORB4 et propose la macro OMNIORB4_IDL_COMPILATION qui
# gère les compilations %.idl -> %_stub.cpp %.hh
#

# Répertoire proposé pour héberger les fichiers idl :
set (CMAKE_INSTALL_IDLDIR "idl")

# Chargement du package pkgconfig omniORB4. Requiert qu'il soit accessible via
# la variable d'environnement PKG_CONFIG_PATH :
include(FindPkgConfig)
pkg_check_modules (omniORB4 REQUIRED omniORB4)
pkg_get_variable(omniORB4_OMNI_IDL omniORB4 omniidl)
pkg_get_variable(omniORB4_DATA_DIR omniORB4 datadir)
pkg_get_variable(omniORB4_IDL_DIR omniORB4 idldir)
pkg_get_variable(omniORB4_LIB_DIR omniORB4 libdir)
pkg_get_variable(omniORB4_PREFIX omniORB4 prefix)
pkg_get_variable(omniORB4_VERSION omniORB4 version)
pkg_get_variable(omniORB4_EXEC_PREFIX omniORB4 exec_prefix)
MESSAGE ("========================== Module omniORB4 ========================== ")
# Variables spécifiques à omniORB4 :
MESSAGE ("omniORB4_OMNI_IDL      = ${omniORB4_OMNI_IDL}")
MESSAGE ("omniORB4_IDL_DIRS      = ${omniORB4_IDL_DIR}")
# Variables CMake prédéfinies :
MESSAGE ("omniORB4_FOUND         = ${omniORB4_FOUND}")
MESSAGE ("omniORB4_VERSION       = ${omniORB4_VERSION}")
MESSAGE ("omniORB4_PREFIX        = ${omniORB4_PREFIX}")
MESSAGE ("omniORB4_EXEC_PREFIX   = ${omniORB4_EXEC_PREFIX}")
MESSAGE ("omniORB4_INCLUDE_DIRS  = ${omniORB4_INCLUDE_DIRS}")
MESSAGE ("omniORB4_LIB_DIR       = ${omniORB4_LIB_DIR}")
MESSAGE ("omniORB4_LIBRARY_DIRS  = ${omniORB4_LIBRARY_DIRS}")
MESSAGE ("omniORB4_LIBRARIES     = ${omniORB4_LIBRARIES}")
MESSAGE ("omniORB4_LINK_LIBRARIES= ${omniORB4_LINK_LIBRARIES}")
MESSAGE ("omniORB4_CFLAGS        = ${omniORB4_CFLAGS}")
MESSAGE ("omniORB4_LDFLAGS       = ${omniORB4_LDFLAGS}")
MESSAGE ("========================== Module omniORB4 ========================== ")
if (omniORB4_IDL_DIRS)
	set (omniORB4_IDL_FLAGS -I${omniORB4_IDL_DIR} -bcxx -Wbuse_quotes -Wba -Wbh=.hh -Wbs=_stub.cpp)
else (omniORB4_IDL_DIRS)
	set (omniORB4_IDL_FLAGS -bcxx -Wbuse_quotes -Wba -Wbh=.hh -Wbs=_stub.cpp)
endif (omniORB4_IDL_DIRS)
#
# Macro OMNIORB4_IDL_COMPILATION.
# Entrée idlfiles : liste de fichiers idl.
# Sortie OMNIORB4_GENERATED_IDL_SOURCES : liste de sources racines (%_stub.cpp) 
#      correspondant aux fichiers idl,
# Sortie OMNIORB4_GENERATED_IDL_HEADERS : liste de fichiers entêtes (%.hh) 
#      correspondant aux fichiers idl
#
MACRO(OMNIORB4_IDL_COMPILATION idlfiles)
	SET(OMNIORB4_GENERATED_IDL_SOURCES "")
	SET(OMNIORB4_GENERATED_IDL_HEADERS "")
    FOREACH (idlfile IN LISTS ${idlfiles})
        GET_FILENAME_COMPONENT(fullfilename ${idlfile} ABSOLUTE)
        GET_FILENAME_COMPONENT(basename ${fullfilename} NAME_WE)
        GET_FILENAME_COMPONENT(directory ${fullfilename} PATH)
#        ADD_CUSTOM_COMMAND (OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${basename}_stub.cpp ${basename}.hh  COMMAND ${omniORB4_OMNI_IDL} -I${omniORB4_IDL_DIR} -bcxx -Wbuse_quotes -Wba -Wbh=.hh -Wbs=_stub.cpp ${OMNIORB4_ADDITIONAL_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR} ${idlfile})
#        ADD_CUSTOM_COMMAND (OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${basename}_stub.cpp ${basename}.hh  COMMAND ${omniORB4_OMNI_IDL} ${omniORB4_IDL_FLAGS} ${OMNIORB4_ADDITIONAL_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR} ${idlfile})
        ADD_CUSTOM_COMMAND (OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${basename}_stub.cpp ${basename}.hh  COMMAND ${omniORB4_OMNI_IDL} ${omniORB4_IDL_FLAGS} ${OMNIORB4_ADDITIONAL_FLAGS} -I${directory}/.. ${idlfile})
        LIST(APPEND OMNIORB4_GENERATED_IDL_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/${basename}_stub.cpp)
        LIST(APPEND OMNIORB4_GENERATED_IDL_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/${basename}.hh)
    ENDFOREACH (idlfile)
ENDMACRO (OMNIORB4_IDL_COMPILATION)

