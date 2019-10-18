CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g
COVERAGE = --coverage 

all: keyGeneator encryption decryption

test: catchdebug catchEuclid 

coverage: coverage_R coverage_E

ReallyLongInt.o: ReallyLongInt.cpp
	$(CC) -c ReallyLongInt.cpp

numberTheory.o: numberTheory.cpp
	$(CC) -c numberTheory.cpp

keygen.o: keygen.cpp
	$(CC) -c keygen.cpp

encrypt.o: encrypt.cpp
	$(CC) -c encrypt.cpp

decrypt.o: decrypt.cpp
	$(CC) -c decrypt.cpp

keyGeneator: keygen.cpp
	$(CC) -o keygen.exe keygen.cpp

encryption: encrypt.cpp
	$(CC) -o encrypt.exe encrypt.cpp

decryption: decrypt.cpp
	$(CC) -o decrypt.exe decrypt.cpp

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o 
	$(CC) $(CFLAGE) $(CATCHINC) -DCATCH_CONFIG_MAIN ReallyLongInt_TEST.cpp ReallyLongInt.o -o ReallyLongInt_TEST.exe

catchEuclid: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
	$(CC) $(CFLAGE) $(CATCHINC) -DCATCH_CONFIG_MAIN numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o -o numberTheory_TEST.exe

coverage_R: ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) -DCATCH_CONFIG_MAIN ReallyLongInt_TEST.cpp ReallyLongInt.cpp -o ReallyLongInt_COVERAGE.exe

coverage_E: numberTheory_TEST.cpp numberTheory.o ReallyLongInt.o
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) -DCATCH_CONFIG_MAIN numberTheory_TEST.cpp numberTheory.cpp ReallyLongInt.o -o numberTheory_COVERAGE.exe

clean:
	rm *.o *.exe *.txt *.gcno *.gcda