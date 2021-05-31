CXXFLAGS = -Wall --std=c++17 `wx-config --libs --cxxflags` -Wextra
BUILD_DIR = build
CXX = g++
SRC_DIR = src


All : gui

clean : 
	rm -rf $(BUILD_DIR)

gui: $(SRC_DIR)/*
	g++ src/*  -std=c++17 `wx-config --cxxflags --libs` -o gui   
	./gui

test: $(SRC_DIR)/*.cpp
	g++ $(SRC_DIR)/ConnectionFrame.cpp $(SRC_DIR)/futils.cpp $(SRC_DIR)/cApp.cpp $(SRC_DIR)/events.cpp $(SRC_DIR)/MyFrame.cpp  -std=c++17 `wx-config --cxxflags --libs` -o gui 
