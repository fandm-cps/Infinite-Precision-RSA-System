CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g  #-D means to define a macro name
COVERAGE = --coverage 

all: main 

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(CFLAGE) $(CATCHINC) -DCATCH_CONFIG_MAIN ReallyLongInt_TEST.cpp ReallyLongInt.o -o ReallyLongInt_TEST

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) -DCATCH_CONFIG_MAIN ReallyLongInt_TEST.cpp ReallyLongInt.cpp -o ReallyLongInt_COVERAGE
