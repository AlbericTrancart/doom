CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FILE(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}" d)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${d}/CMake")
FIND_PACKAGE(Imagine)

find_package(SDL REQUIRED)
find_package(SDL_mixer REQUIRED)

ImagineAddExecutable(doom 
                        main.cpp        headers/constants.h
                        player.cpp      headers/player.h
                        utils.cpp       headers/utils.h
                        events.cpp      headers/events.h
                        graphics.cpp    headers/graphics.h
                        hud.cpp         headers/hud.h
                        map.cpp         headers/map.h
                        sound.cpp       headers/sound.h
                        chicken.cpp     headers/chicken.h)
ImagineUseModules(doom Graphics)
target_link_libraries(doom SDL SDL_mixer pthread)