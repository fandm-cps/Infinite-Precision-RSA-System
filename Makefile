CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g  #-D means to define a macro name
COVERAGE = --coverage 

all: main 

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(CFLAGS) $(CATCHINC) -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.o

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp