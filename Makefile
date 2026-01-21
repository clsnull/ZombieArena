APP_NAME = sfml-app
SFML_ROOT = /usr/local/sfml
SFML_INCLUDE = $(SFML_ROOT)/include
SFML_LIB = $(SFML_ROOT)/lib
SRC_DIR = ./src
DIST_DIR = ./dist

CXX = g++
CXXFLAGS = -std=c++17 -I$(SFML_INCLUDE)

run.sh: $(APP_NAME)
	echo '#!/bin/bash' > $(DIST_DIR)/run.sh
	echo 'export LD_LIBRARY_PATH=./' > $(DIST_DIR)/run.sh
	echo './$(APP_NAME)' >> $(DIST_DIR)/run.sh
	chmod +x $(DIST_DIR)/run.sh

$(APP_NAME): main.o Player.o
	g++ $(DIST_DIR)/main.o $(DIST_DIR)/Player.o -o $(DIST_DIR)/$(APP_NAME) \
	-L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

main.o: clean cp
	g++ $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(DIST_DIR)/main.o

Player.o:
	g++ $(CXXFLAGS) -c $(SRC_DIR)/Player.cpp -o $(DIST_DIR)/Player.o

cp: 
	mkdir $(DIST_DIR)
	cp $(SFML_LIB)/libsfml-graphics.so* $(DIST_DIR)
	cp $(SFML_LIB)/libsfml-window.so* $(DIST_DIR)
	cp $(SFML_LIB)/libsfml-system.so* $(DIST_DIR)
	cp $(SFML_LIB)/libsfml-audio.so* $(DIST_DIR)
	cp $(SFML_LIB)/libsfml-network.so* $(DIST_DIR)
	cp -r $(SRC_DIR)/fonts/ $(DIST_DIR)/fonts/
	cp -r $(SRC_DIR)/graphics/ $(DIST_DIR)/graphics/
	cp -r $(SRC_DIR)/sound/ $(DIST_DIR)/sound/

.PHONY: clean
clean:
	rm -rf $(DIST_DIR)