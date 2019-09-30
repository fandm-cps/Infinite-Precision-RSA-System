CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g
COVERAGE = --coverage 

all: catchdebug 

test: catchdebug catchEuclid 

coverage: coverage_R coverage_E

ReallyLongInt.o: ReallyLongInt.cpp
	$(CC) -c ReallyLongInt.cpp

numberTheory.o: numberTheory.cpp
	$(CC) -c numberTheory.cpp

keygen.o: keygen.cpp
	$(CC) -c keygen.cpp

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o 
	$(CC) $(CFLAGE) $(CATCHINC) -DCATCH_CONFIG_MAIN ReallyLongInt_TEST.cpp ReallyLongInt.o -o ReallyLongInt_TEST

catchEuclid: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
	$(CC) $(CFLAGE) $(CATCHINC) -DCATCH_CONFIG_MAIN numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o -o numberTheory_TEST

coverage_R: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) -DCATCH_CONFIG_MAIN ReallyLongInt_TEST.cpp ReallyLongInt.cpp -o ReallyLongInt_COVERAGE

coverage_E: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) -DCATCH_CONFIG_MAIN numberTheory_TEST.cpp numberTheory.cpp ReallyLongInt.o -o numberTheory_COVERAGE