cmake_minimum_required(VERSION 3.8)

project(qt-tutorial)
set(CMAKE_CXX_STANDARD 11)

# setup qt5 ----------
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
set(PRJ_INCLUDE_DIRS "")
list(APPEND PRJ_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/Include")
list(APPEND PRJ_INCLUDE_DIRS ${Qt5Core_INCLUDE_DIRS})
list(APPEND PRJ_INCLUDE_DIRS ${Qt5Widgets_INCLUDE_DIRS})
list(REMOVE_DUPLICATES PRJ_INCLUDE_DIRS)
include_directories(${PRJ_INCLUDE_DIRS})
# ---------- set the include dirs

# set the libs ----------
set(PRJ_LIBS "")
list(APPEND PRJ_LIBS ${Qt5Core_LIBRARIES})
list(APPEND PRJ_LIBS ${Qt5Widgets_LIBRARIES})
message(STATUS ${PRJ_LIBS})
# ---------- set the libs

# set the sources ----------
set(PRJ_SOURCES "")
file(GLOB_RECURSE Sources "${CMAKE_CURRENT_SOURCE_DIR}/PlayGround")
list(APPEND PRJ_SOURCES Sources)
# ---------- set the sources

# build the playground executables ----------
file(GLOB_RECURSE PlayGround "${CMAKE_CURRENT_SOURCE_DIR}/PlayGround/*.cpp")
foreach (exec_source ${PlayGround})
    get_filename_component(exec_name ${exec_source} NAME_WE)
    add_executable(${exec_name} ${exec_source})
    target_link_libraries(${exec_name} ${PRJ_LIBS})
endforeach ()
# ---------- build the playground executables