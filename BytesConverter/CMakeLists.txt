cmake_minimum_required(VERSION 3.2)

project(bytesconverter CXX)

#set (BOOST_ROOT "C:/libs/boost/mingw1120_64/") # Путь к библиотеке Boost
set (BOOST_ROOT "C:/Boost/") # Путь к библиотеке Boost (установить, если путь нестандартный - не "C:/Boost/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


# === Boost Library ===
#set(Boost_USE_STATIC_RUNTIME    OFF)
#set(Boost_USE_STATIC_LIBS       OFF)

set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)

find_package(Boost COMPONENTS system program_options)

# === Application ===
file(GLOB_RECURSE Proj_Src "src/*.cpp" "src/*.h")

message(${Boost_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
add_executable(bytesconverter ${Proj_Src})
target_link_libraries(bytesconverter ${Boost_LIBRARIES})
