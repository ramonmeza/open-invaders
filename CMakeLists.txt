cmake_minimum_required(VERSION 3.12)
project(open-invaders)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Set default build type explicitly to Release
if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build type." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

if(NOT SFML_ROOT)
  set(SFML_ROOT CACHE "" FORCE)
endif()

# Find SFML
set(SFML_STATIC_LIBRARIES FALSE)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

if(NOT SFML_FOUND)
  message(FATAL_ERROR "SFML couldn't be located!")
endif()

include_directories(${SFML_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
  src/main.cc
  src/core/game.cc
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(open-invaders ${SOURCE_FILES})

target_link_libraries(open-invaders ${THOR_LIBRARY} ${SFGUI_LIBRARY} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Install executable
install(TARGETS  open-invaders
  RUNTIME DESTINATION .
)

# Install game data
install(DIRECTORY bin/res
  DESTINATION .
)
