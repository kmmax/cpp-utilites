cmake_minimum_required(VERSION 3.5)

project(regcalculater LANGUAGES CXX)

find_package(GTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#target_link_libraries(mbutility GTEST_LIBRARY)

# === Application ===
file(GLOB_RECURSE Proj_Src "src/*.cpp" "src/*.h")
add_executable(regcalculater ${Proj_Src})
