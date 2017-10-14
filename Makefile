

CC = g++
# CFLAGS = -std=c++11



all: leapfrog

leapfrog: Vector.h leapfrog.cpp
	$(CC) -o $@ $(CFLAGS) $@.cpp $(LIBS)
