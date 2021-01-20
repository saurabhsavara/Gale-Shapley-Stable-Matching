OBJS    = main.o GaleShapley.o readfiles.o
SOURCE  = main.cpp GaleShapley.cpp readfiles.cpp
HEADER  = GaleShapley.h
OUT     = matchmaking
CC       = g++
FLAGS    = -g -c -Wall
LFLAGS   =

all: $(OBJS)
        $(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
        $(CC) $(FLAGS) main.cpp

GaleShapley.o: GaleShapley.cpp
        $(CC) $(FLAGS) GaleShapley.cpp

readfiles.o: readfiles.cpp
        $(CC) $(FLAGS) readfiles.cpp


clean:
        rm -f $(OBJS) $(OUT)
