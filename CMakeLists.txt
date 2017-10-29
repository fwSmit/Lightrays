cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project (lightrays)

file(GLOB lightRay_SRC
    "src/*.cpp"
	"include/*.h"
)
set (CMAKE_CXX_STANDARD 11)

#when used as library
#include_directories(${CMAKE_SOURCE_DIR}/dependencies/include)
#include_directories(${CMAKE_SOURCE_DIR}/projects/lightrays/include)

#when used as standalone executable
include_directories(${CMAKE_SOURCE_DIR}/include)

#add_library(lightrays_lib SHARED ${lightRay_SRC})

add_executable(lightrays_lib ${lightRay_SRC})

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
target_link_libraries(lightrays_lib ${SFML_LIBRARIES} ${TGUI_LIBRARY})
