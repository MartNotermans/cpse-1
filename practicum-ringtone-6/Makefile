#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

HEADERS += note.hpp
HEADERS += melody.hpp
HEADERS += note_player.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

HEADERS += song.hpp


# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)..
include $(RELATIVE)/Makefile.due



song.hpp: generator
	./generator

generator: generator.o rtttl_player.o note_generator.o
	g++ -std=c++17 generator.o rtttl_player.o note_generator.o -o generator

generator.o: generator.cpp rtttl_player.hpp note_generator.hpp
	g++ -std=c++17 -c generator.cpp -o generator.o

rtttl_player.o: rtttl_player.cpp rtttl_player.hpp note_player.hpp
	g++ -std=c++17 -c rtttl_player.cpp -o rtttl_player.o

note_generator.o: note_generator.cpp note_generator.hpp
	g++ -std=c++17 -c note_generator.cpp -o note_generator.o