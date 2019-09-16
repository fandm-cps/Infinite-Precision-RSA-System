CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g  #-D means to define a macro name
COVERAGE = --coverage 

all: main 

debug: ReallyLongInt.cpp
	$(CC) $(CFLAGE) ReallyLongInt.cpp -o debug

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o
	$(CC) $(CFLAGS) $(CATCHINC) -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.o

coverage: ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) ReallyLongInt.cpp

clean:
	rm *.o;

#gcov ReallyLongInt.cpp 
