CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
FILE(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}" d)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${d}/CMake")
FIND_PACKAGE(Imagine)

ImagineAddExecutable(doom 
                        main.cpp
                        player.cpp
                        utils.cpp
                        events.cpp
                        graphics.cpp
                        hud.cpp
                        map.cpp)
ImagineUseModules(doom Graphics)
