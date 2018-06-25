CXX = g++ -std=c++11
CXXFLAGS = -shared -g -Wall -Wno-unknown-pragmas -fPIC -Wno-unused-function
ATOMFLAGS = -L./src/atom/lib -I./src/atom/include -latomengine

SRC_DIR := src/classes
OBJ_DIR := obj
SRC_LIST = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

OBJS := $(wildcard $(OBJ_DIR:=/*.o))

build: $(OBJS)
	@echo Building ...
	@echo
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) $(OBJS) -o main.exe
	@echo

compile: $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(wildcard $(SRC_DIR)/*.cpp)))))
	@echo

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(ATOMFLAGS) -c $^ -o $@

clean:
	@echo Cleaning binary files ...
	rm -f $(OBJ_DIR)/*.o *~