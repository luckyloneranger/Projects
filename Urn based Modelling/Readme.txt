gcc -Wall -I/usr/local/include -c main.c
 
gcc -static main.o -lgsl -lgslcblas -lm

./a.out



	