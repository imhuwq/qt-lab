cmake_minimum_required(VERSION 3.8)

project(qt-tutorial)
set(CMAKE_CXX_STANDARD 11)

# things to be gathered ----------
set(PRJ_INCLUDES "")                # include directories
set(PRJ_LIBRARIES "")               # libraries
set(PRJ_LIBRARIES_DEBUG "")         # libraries only needed for debug purpose
set(PRJ_SOURCES "")                 # source files
# things to be gathered ----------


# for debug ----------
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
find_package(Gperftools REQUIRED)
list(APPEND PRJ_INCLUDES ${GPERFTOOLS_INCLUDE_DIR})
list(APPEND PRJ_LIBRARIES_DEBUG ${GPERFTOOLS_LIBRARIES})
message(STATUS ${GPERFTOOLS_LIBRARIES})
# ---------- for debug


# setup qt5 ----------
# notice for developer: Qt5 must be installed in home directory
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(Qt5Dir "$ENV{HOME}/Qt/5.10.0")
file(GLOB Qt5Modules "${Qt5Dir}/gcc_64/lib/cmake/*")
foreach (Qt5Module ${Qt5Modules})
    if (IS_DIRECTORY ${Qt5Module})
        get_filename_component(ModuleName ${Qt5Module} NAME_WE)
        set("${ModuleName}_DIR" ${Qt5Module})
    endif ()
endforeach ()
# ---------- setup qt5


# the packages required ----------
find_package(Qt5Core)
find_package(Qt5Widgets)
# ---------- the packages required


# set the include dirs ----------
list(APPEND PRJ_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/Include")
list(APPEND PRJ_INCLUDES ${Qt5Core_INCLUDE_DIRS})
list(APPEND PRJ_INCLUDES ${Qt5Widgets_INCLUDE_DIRS})
list(REMOVE_DUPLICATES PRJ_INCLUDES)
include_directories(${PRJ_INCLUDES})
# ---------- set the include dirs


# set the libs ----------
list(APPEND PRJ_LIBRARIES ${Qt5Core_LIBRARIES})
list(APPEND PRJ_LIBRARIES ${Qt5Widgets_LIBRARIES})
# ---------- set the libs


# set the sources ----------
file(GLOB_RECURSE Sources "${CMAKE_CURRENT_SOURCE_DIR}/Sources/*.cpp")
list(APPEND PRJ_SOURCES Sources)
# ---------- set the sources


# build the playground executables ----------
file(GLOB_RECURSE PlayGround "${CMAKE_CURRENT_SOURCE_DIR}/PlayGround/*.cpp")
foreach (exec_source ${PlayGround})
    get_filename_component(exec_name ${exec_source} NAME_WE)
    add_executable(${exec_name} ${exec_source})
    target_link_libraries(${exec_name} ${PRJ_LIBRARIES})
    target_link_libraries(${exec_name} debug ${PRJ_LIBRARIES})
endforeach ()
# ---------- build the playground executables
