# Infinite Precision RSA System 
RSA (Rivest–Shamir–Adleman) is one of the first public-key cryptosystems and is widely used for secure data transmission. In this system, the encryption key is public, and the decryption key, however, is kept private. This asymmetry is based on the practical difficulty of the factorization of the product of two large prime numbers, the "factoring problem." The idea behind RSA is to make Diffie-Hellman, which relies only upon Fermat's Little Theorem and primes, into a system which involves Euler's Theorem. 

In practice, the prime numbers are industrial-grade primes. This is the time when built-in simple data-types are just not enough. In this project, we will implement a very large unsigned long called ReallyLongInt of a size not supported by C++ (C++ supports up to 2^64). However, we are going to consider the RSA algorithm for public-key cryptography, and even 2^64 can be regarded as small.  

## Requirements
macOS Catalina Version 10.15

C++ 11

## To Set Up Everything:
```
$ make all
```

## To Generate Public/Private Key 
```
$ ./keygen.exe <primeone> <primetwo> <publicfile> <privatefile>
```
The keygen.cpp takes in two prime numbers and two text files as command-line arguments. If two input numbers are not prime, the program will throw an error message. The procedure is the following:

1. The user gives two prime number p and q.

2. Calculate n = p x q

3. Calculate t = (p-1) x (q-1)

4. Pick a number e, such that 1 < e < t, and e and t are relatively prime.

5. Find a d such that (ed) % t = 1

6. The keys are 

* Public (encryption): (e,n)
* Private (decryption): (d,n)

Since it takes ReallyLongInt reasonably long time to do module operation and the number cannot be higher than 3000^3000, please do not try super large prime numbers.

NOTE: If the product of two prime numbers is smaller than 255, the system will fail because it will cause an ASCII code conflict. 

## To Encrypt 
```
$ ./encrypt.exe <publicKeyfile> <sourcefile> <encryptedfile>
```
The encrypt.cpp takes in three file names as command-line arguments: the path of the public key file, the path of the test file, and the destination of encryption. It uses the public key to encrypt the data in the source file. The procedure of the encryption is the following:

1. Loop over characters in message

2. For each character ‘c’ get ASCII value x

3. Let y = (x^e) % n, from the Public key set above

4. Covert the number y back into a character ‘c’ and place into the new message

## To Decrypt 
```
$ ./decrypt.exe <privateKeyfile> <encryptedfile> <decryptedfile>
```
The decrypt.cpp takes three file names as command-line arguments: the path of the private key file, the path of an encrypted file, and the destination of decryption. It uses the private key to decrypt the encrypted data in the encrypted file. The procedure of the decryption is the following:

1. Loop over charaters in the encrypted message

2. For each character ‘c’ get ASCII value y

3. Let x = (y^d) % n, from the Private key set above

4. Convert the number x into a character‘c’ and place into a new message

## Catch and Coverage
```
$ make text
$ make coverage
```
Rest Please See Cheat Sheet

## Cautions

If you are from Franklin and Marshall College, PA and taking CPS 222 right now, DO NOT CONSULT OR EVEN COPY MY CODE. Professor Booth, Hu, and Novak are watching you.

Though I call it an infinite precision integer system, there is still a limit around 3000^3000. It is because both my for loop can at most iterate 2^63 - 1 time and some stack issue. 

Different operating systems and architectures MAY have a different decrypted result though the decrypted numbers are essentially correct.

# Reference 
https://en.wikipedia.org/wiki/RSA_(cryptosystem)

Karl-Dieter Crisman,Number Theory: In Context and Interactive, January 2017
