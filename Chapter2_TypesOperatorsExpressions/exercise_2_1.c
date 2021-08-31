/**
 * Exercise 2.1  
 * Write a program to determine the sizes of long, char, int
 */
#include <stdio.h>

#ifdef BITS
#define LENGTH_TYPE 8L
#else
#define LENGTH_TYPE 1L
#endif

int main()
{
    printf("This is a char: %lu \n", sizeof(char)*LENGTH_TYPE);
    printf("This is an int: %lu \n", sizeof(int)*LENGTH_TYPE);
    printf("This is a short int: %lu \n", sizeof(short int)*LENGTH_TYPE);
    printf("This is a long int: %lu \n", sizeof(long int)*LENGTH_TYPE);
    printf("This is a long: %lu \n", sizeof(long)*LENGTH_TYPE);
    printf("This is a short: %lu \n", sizeof(short)*LENGTH_TYPE);
    printf("This is a float: %lu \n", sizeof(float)*LENGTH_TYPE);
    printf("This is a double: %lu \n", sizeof(double)*LENGTH_TYPE);
    printf("This is a long double: %lu \n", sizeof(long double)*LENGTH_TYPE);
}