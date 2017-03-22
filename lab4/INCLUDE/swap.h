#ifndef swap_H
#define swap_H

#include "./Implementation/swap.cpp"
/*swap two numbers by passing PARAMETER as REFERENCES
using temporary variable
Input: two integer pointers*/
void swap_TEMP(int *a,int *b);

/*swap two FLOATING numbers by passing PARAMETER as REFERENCES
using temporary variable
Input: two float type pointers*/
void swap_TEMP(float *a,float *b);

/*swap two characters values by passing PARAMETER as REFERENCES
using temporary variable
Input: two char type pointers*/
void swap_TEMP(char *a,char *b);

/*swap two numbers by passing PARAMETER as REFERENCES
using BOOLEAN XOR FUNCTION
Input: two integer pointers*/
void swap_XOR(int *a,int *b);

/*swap two characters values by passing PARAMETER as REFERENCES
using BOOLEAN XOR FUNCTION
Input: two char type pointers*/
void swap_XOR(char *a,char *b);

/*swap two FLOATING numbers by passing PARAMETER as REFERENCES
using temporary variable
Input: two float type pointers*/
void swap_XOR(float *a,float *b);

/*swap two numbers by passing PARAMETER as REFERENCES
without using TEMPORARY variable
Input: two integer pointers*/
void swap_W_O_TEMP(int *a,int *b);

/*swap two characters by passing PARAMETER as REFERENCES
without using TEMPORARY variable
Input: two character pointers*/
void swap_W_O_TEMP(char *a,char *b);

/*swap two FLOATING numbers by passing PARAMETER as REFERENCES
without using TEMPORARY variable
Input: two FLOAT pointers*/
void swap_W_O_TEMP(float *a,float *b);

#endif