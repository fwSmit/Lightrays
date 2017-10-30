cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project (lightrays)

file(GLOB lightRay_SRC
    "src/*.cpp"
	"include/*.h"
)
set (CMAKE_CXX_STANDARD 11)

#set(IS_LIBRARY CACHE)
option(IS_LIBRARY "Should lightrays be compiled as library?")

if(IS_LIBRARY)
#when used as library
message("setting lightrays up as library")
include_directories(${CMAKE_SOURCE_DIR}/dependencies/include)
include_directories(${CMAKE_SOURCE_DIR}/projects/lightrays/include)
add_library(lightrays SHARED ${lightRay_SRC})
else()
#when used as standalone executable
message("setting lightrays up as executable")
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(lightrays ${lightRay_SRC})
endif()

#include the necessary libraries
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(TGUI 0.7 REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif()

if(NOT TGUI_FOUND)
    message(FATAL_ERROR "Could not find TGUI")
endif()

#include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(lightrays ${SFML_LIBRARIES} ${TGUI_LIBRARY})
