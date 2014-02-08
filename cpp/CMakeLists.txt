CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FILE(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}" d)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${d}/CMake")
FIND_PACKAGE(Imagine)

find_package(SDL REQUIRED)
find_package(SDL_mixer REQUIRED)

add_subdirectory(editor)
ImagineAddExecutable(doom 
						main.cpp		headers/constants.h
						player.cpp		headers/player.h
						utils.cpp		headers/utils.h
						events.cpp		headers/events.h
						graphics.cpp	headers/graphics.h
						hud.cpp			headers/hud.h
						map.cpp			headers/map.h
						sound.cpp       headers/sound.h)
ImagineUseModules(doom Graphics)
target_link_libraries(doom SDL pthread)
target_link_libraries(doom SDL_mixer pthread)