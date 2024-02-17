cmake_minimum_required(VERSION 3.27)
project(FirstVTKQT)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(VTK 9.3 REQUIRED)

add_executable(FirstVTKQT main.cpp)
target_link_libraries(FirstVTKQT PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui)
