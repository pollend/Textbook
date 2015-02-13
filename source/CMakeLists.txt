cmake_minimum_required (VERSION 2.6)
project (pilotage)
set(CMAKE_EXECUTABLE_SUFFIX .wt)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../release)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/cmake")


list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

#########################################################################################
#Main Source
#########################################################################################

FILE(GLOB SOURCE  
	#source/cgi_defs.c 
	#source/put_gen.c 
	#source/put_funs.c 
	#source/document.cpp
  #source/table.cpp
  #source/page_dynamic.cpp
  #source/page.cpp
  #source/page_template.cpp
  #source/table_entry.cpp
  #source/messenger.cpp
  #source/basic_document_pair.cpp
  #source/airport_data.cpp
  #source/address_data.cpp
  3source/loop_document_pair.cpp
  3source/data.cpp
  3source/business_data.cpp
  #source/database.cpp
  #source/base_page.cpp
  #airports.cpp
  "source/*.cpp"
  )

  MESSAGE(source files:"${SOURCE}")


#########################################################################################
#BOOST
#########################################################################################

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(BOOST_INCLUDEDIR "${CMAKE_SOURCE_DIR}/lib/boost/include")
set(BOOST_LIBRARYDIR "${CMAKE_SOURCE_DIR}/lib/boost/lib")

set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/lib/boost")

find_package(Boost COMPONENTS regex system filesystem REQUIRED)


#########################################################################################
#FAST CGI
#########################################################################################
FIND_PATH(FCGI_INCLUDE_DIR
  fcgio.h
  PATHS
  /usr/include
  /usr/local/include
  /usr/include/fastcgi
  "$ENV{LIB_DIR}/include"
  $ENV{INCLUDE}
  )
FIND_LIBRARY(FCGI_LIBRARY NAMES fcgi libfcgi PATHS 
  /usr/local/lib 
  /usr/lib 
  "$ENV{LIB_DIR}/lib"
  "$ENV{LIB}"
  )

IF (FCGI_INCLUDE_DIR AND FCGI_LIBRARY)
   SET(FCGI_FOUND TRUE)
ENDIF (FCGI_INCLUDE_DIR AND FCGI_LIBRARY)

IF (FCGI_FOUND)
   IF (NOT FCGI_FIND_QUIETLY)
      MESSAGE(STATUS "Found FCGI: ${FCGI_LIBRARY}")
   ENDIF (NOT FCGI_FIND_QUIETLY)
ELSE (FCGI_FOUND)
   IF (FCGI_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find FCGI")
   ENDIF (FCGI_FIND_REQUIRED)
ENDIF (FCGI_FOUND)


#########################################################################################
#Wt
#########################################################################################

find_library(MARIA_LIB NAMES mariadb PATHS
/usr/local/lib
/usr/local/lib/mariadb
/usr/lib 
"$ENV{LIB_DIR}/lib"
"$ENV{LIB}")

FIND_PACKAGE( Wt REQUIRED )

#########################################################################################

include_directories(header)
include_directories(${FCGI_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})
include_directories( ${Wt_INCLUDE_DIR} )

macro(add_executable _name)
	_add_executable(${ARGV} ${SOURCE})
    target_link_libraries(${_name} ${MARIA_LIB}) 
	target_link_libraries(${_name} ${Boost_LIBRARIES}) 
  #target_link_libraries(${_name} ${Wt_HTTP_LIBRARY})
  target_link_libraries(${_name} ${Wt_LIBRARY} wt wtfcgi wtdbo wtdbomysql )
	target_link_libraries(${_name} ${FCGI_LIBRARY}) 
	if(TARGET${_name})
	target_link_libraries(${_name} source)
	endif()
endmacro()

add_executable(generate generate.cpp)
add_executable(main main.cpp)