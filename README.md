# Infinte Precision RSA System 
RSA (Rivest–Shamir–Adleman) is one of the first public-key cryptosystems and is widely used for secure data transmission. In this system, the encryption key is public and the decryption key, however, is kept private. This asymmetry is based on the practical difficulty of the factorization of the product of two large prime numbers, the "factoring problem". The idea behind RSA is to make Diffie-Hellman, which relies only upon Fermat's Little Theorem and primes, into a system which involves Euler's Theorem. 

In pratice, the prime numbers are industrial-grade primes. This is the time when built in simple data-types are just not enough. In this project, we will imlement a very large unsigned long called ReallyLongInt of a size not supported by C++ (C++ supports up to 2^64). However, we are going to be consider the RSA algorithm for public-key cryptography, and even 2^64 can be considered small.  

# Requirements
C++ 11

**To Set Up:**
```
$ make test
$ make coverage
$ make system
```

** To Generate Public/Private Key **
```
$ ./keygen.exe p q public.txt private.txt
```
where p and q are primes numbers

*** To Encrypt ***
```
$ ./encrypt.exe public.txt content.txt secureData.txt
```

** Te Decrypt **
```
$ ./decrypt.exe private.txt secureData.txt decryptData.txt
```
# Reference 
https://en.wikipedia.org/wiki/RSA_(cryptosystem)
Karl-Dieter Crisman,Number Theory: In Context and Interactive, January 2017
