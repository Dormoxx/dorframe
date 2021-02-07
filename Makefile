#OBJS specifies which files to compile as part of the project
PC_OBJS = $(PWD)/src/*.cpp $(PWD)/src/platform/SDL/*.cpp

#complier
CC = g++

SPDLOG = vendor/spdlog/include/

#compiler flags -w suppresses warnings
COMPILER_FLAGS = -w -I$(SPDLOG)

LINKER_FLAGS = -lSDL2 -lGLEW -lGL

#OBJ_NAME specifies the name of our exectuable
PC_TARGET = build.app

#This is the target that compiles our executable (pc only for now)
all : $(PC_OBJS)
	$(CC) $(PC_OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o build/$(PC_TARGET)

clean:
	-rm -f build/*

DC_TARGET = build.elf
DC_OBJS = $(PWD)/src/main.o $(PWD)/src/platform/KOS/KOSWindow.o
include $(KOS_BASE)/Makefile.rules
dc: $(DC_OBJS)
	kos-c++ -std=c++11 $(KOS_CFLAGS) -o build/$(DC_TARGET) $(KOS_START) \
		$(DC_OBJS) $(OBJEXTRA) -L$(KOS_BASE)/lib -lGL -lm $(KOS_LIBS)
