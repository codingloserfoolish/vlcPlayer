cmake_minimum_required(VERSION 3.10)
project(vlcPlayer)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(PROJECT_SOURCES 
"MainWindow.h" 
"VideoPlayWidget.h"
"VlcInstance.h"
"VlcMedia.h"
"VlcMediaPlayer.h"
"VideoControlWidget.h"
"StyleApplication.h"
"ExtraMenu.h"

"MainWindow.cpp"  
"VideoPlayWidget.cpp"
"VlcInstance.cpp"
"VlcMedia.cpp"
"VlcMediaPlayer.cpp"
"VideoControlWidget.cpp"
"StyleApplication.cpp"
"ExtraMenu.cpp"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)


find_package(Qt5 COMPONENTS Widgets)

add_executable(${PROJECT_NAME} "main.cpp" ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} libvlc libvlccore Qt5::Widgets)