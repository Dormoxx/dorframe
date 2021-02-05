#OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp

#complier
CC = g++

SPDLOG = vendor/spdlog/include/

#compiler flags -w suppresses warnings
COMPILER_FLAGS = -w -I$(SPDLOG)

LINKER_FLAGS = -lSDL2 -lGLEW -lGL

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = build.app

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o build/$(OBJ_NAME)

clean:
	-rm -f build/*
