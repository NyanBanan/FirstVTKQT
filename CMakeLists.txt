cmake_minimum_required(VERSION 3.27)
project(FirstVTKQT)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/usr/local/Qt-6.6.3/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets OpenGL)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(VTK 9.3 REQUIRED COMPONENTS
        CommonCore
        CommonColor
        CommonDataModel
        IOImage
        IOXML
        ImagingCore
        InteractionStyle
        FiltersSources
        RenderingContextOpenGL2
        RenderingCore
        RenderingFreeType
        RenderingGL2PSOpenGL2
        RenderingOpenGL2
        RenderingVolumeOpenGL2
        GUISupportQt
        RenderingQt)

add_executable(FirstVTKQT main.cpp
        MyGodWidget.cpp
        DicomWidget.cpp)
target_link_libraries(FirstVTKQT PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui Qt6::OpenGL ${VTK_LIBRARIES} OpenGL::OpenGL GLEW::GLEW)

vtk_module_autoinit(TARGETS FirstVTKQT MODULES ${VTK_LIBRARIES})