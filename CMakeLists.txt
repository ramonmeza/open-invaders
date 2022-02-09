cmake_minimum_required(VERSION 3.12)
project(open_invaders VERSION 0.1)

# set compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# setup cmake
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

# set default build type to debug
if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build type." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

# find SFML
if(NOT SFML_ROOT)
  set(SFML_ROOT CACHE STRING FORCE)
endif()

set(SFML_STATIC_LIBRARIES FALSE)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

if(NOT SFML_FOUND)
  message(FATAL_ERROR "SFML couldn't be located!")
endif()

# set directory variables
set(GAME_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(GAME_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third-party)
set(LEKSYS_INI_DIR ${THIRD_PARTY_DIR}/LeksysINI)

# add config file
configure_file(${GAME_INCLUDES}/config/config.h.in ${GAME_INCLUDES}/config/config.h)

# include directories
include_directories(${GAME_SRC})
include_directories(${GAME_INCLUDES})

include_directories(${SFML_INCLUDE_DIR})
include_directories(${LEKSYS_INI_DIR})

# list of files needed to compile
set(SOURCE_FILES
  src/main.cc
  src/core/game.cc
)


# create the executable
add_executable(open_invaders ${SOURCE_FILES})

# link
target_include_directories(open_invaders PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(open_invaders ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# install executable
install(TARGETS  open_invaders
  RUNTIME DESTINATION .
)

# install game data
install(DIRECTORY data
  DESTINATION .
)
