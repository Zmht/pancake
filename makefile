CXXFLAGS = -Wall --std=c++17 `wx-config --libs --cxxflags` -Wextra
BUILD_DIR = build
CXX = g++
SRC_DIR = src


All : gui

clean : 
	rm -rf $(BUILD_DIR)

gui: $(SRC_DIR)/*
	g++ src/* `wx-config --cxxflags --libs` -o gui   
	./gui

