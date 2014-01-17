CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FILE(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}" d)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${d}/CMake")
FIND_PACKAGE(Imagine)

ImagineAddExecutable(doom 
						main.cpp		headers/constants.h
						player.cpp		headers/player.h
						utils.cpp		headers/utils.h
						events.cpp		headers/events.h
						graphics.cpp	headers/graphics.h
						hud.cpp			headers/hud.h
						map.cpp			headers/map.h)

ImagineUseModules(doom Graphics)