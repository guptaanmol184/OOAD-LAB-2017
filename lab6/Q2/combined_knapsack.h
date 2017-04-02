#ifndef KNAPSACK_H
#define KNAPSACK_H

// 1 & 2
int max(int a,int b);
float max(float a,float b);
void knapsack(int W,int *weight,int *profit,int n);
void knapsack(float W,float *weight,float *profit,int n);

// 3
void knapsack(int W, int weight[], int no_weights);

// 4
void knapsack(int w, int weight[], int profit[], int no_weights, bool flag);
int max_index(float a[], int start, int end);
template <typename T> void print_array(T a[],int size);
template <typename T> void swap(T arr[], int index1, int index2);

#include "./combined_knapsack.cpp"

#endif