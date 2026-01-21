APP_NAME = sfml-app
SFML_ROOT = /user/local/sfml
SFML_INCLUDE = $(SFML_ROOT)/include
SFML_LIB = $(SFML_ROOT)/lib

CXX = g++
CXXFLAGS = -std=c++17 -I$(SFML_INCLUDE)

run.sh: sfml-app
	echo '#!/bin/bash' > ./run.sh
	echo 'export LD_LIBRARY_PATH=./' > ./run.sh
	echo './sfml-app' >> ./run.sh
	chmod +x ./run.sh

sfml-app: main.o cp
	g++ main.o -o sfml-app \
	-L/usr/local/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system
main.o:
	g++ -std=c++17 -I/usr/local/sfml/include -c main.cpp

cp:
	cp /usr/local/sfml/lib/libsfml-graphics.so* ./
	cp /usr/local/sfml/lib/libsfml-window.so* ./
	cp /usr/local/sfml/lib/libsfml-system.so* ./
	cp /usr/local/sfml/lib/libsfml-audio.so* ./
	cp /usr/local/sfml/lib/libsfml-network.so* ./
