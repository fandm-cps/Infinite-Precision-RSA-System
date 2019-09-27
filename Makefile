CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g  #-D means to define a macro name
COVERAGE = --coverage 

all: main 

test: catchdebug catchEuclid catchKeyGen

ReallyLongInt.o: ReallyLongInt.cpp
	$(CC) -c ReallyLongInt.cpp

numberTheory.o: numberTheory.cpp
	$(CC) -c numberTheory.cpp

keygen.o: keygen.cpp
	$(CC) -c keygen.cpp

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o 
	$(CC) $(CFLAGE) $(CATCHINC) -DCATCH_CONFIG_MAIN ReallyLongInt_TEST.cpp ReallyLongInt.o -o ReallyLongInt_TEST

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) -DCATCH_CONFIG_MAIN ReallyLongInt_TEST.cpp ReallyLongInt.cpp -o ReallyLongInt_COVERAGE

catchEuclid: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
	$(CC) $(CFLAGE) $(CATCHINC) -DCATCH_CONFIG_MAIN numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o -o numberTheory_TEST

catchKeyGen: keygen_TEST.cpp numberTheory.o ReallyLongInt.o keygen.o
	$(CC) $(CFLAGE) $(CATCHINC) -DCATCH_CONFIG_MAIN keygen_TEST.cpp numberTheory.o keygen.o ReallyLongInt.o -o keygen_TEST