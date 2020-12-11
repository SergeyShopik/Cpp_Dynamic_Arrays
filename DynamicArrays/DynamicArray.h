#pragma once
#include<iostream>
#include<ctime>
void swap(int*, int*);
int* searchMin(int*, size_t);
void selectionSort(int*, size_t);
void selectionSort1(int*, int);

int* allocateMem(int*, size_t);
int* freeMem(int*);
void initArray(int*, size_t, int, int);
void printArray(int*, size_t);

int** allocateMem(int**, size_t, size_t);
int** freeMem(int**, size_t);

void initArray(int**, size_t, size_t, int, int);
void printArray(int**, size_t, size_t);

int** insertCol(int**, size_t, size_t&, size_t, int*); //third size_t for index, second int for new array
int** insertRow(int**, size_t&, size_t, size_t, int*);
int** deleteRow(int**, size_t&, size_t, size_t);
int** deleteCol(int**, size_t, size_t&, size_t);
void matrixProd(int**, int**, int**, size_t, size_t, size_t);

size_t defineLargestArray(size_t, size_t);
size_t defineSmallestArray(size_t, size_t);

int* _6_addTwoPolynomials(int*, int*, size_t, size_t);
int* _6_multiplyTwoPolynomials(int*, int*, size_t, size_t);

int* _7_gatherElmentsFromTwoArrays(int*, int*, size_t, size_t);

size_t defineSizeForCommonElements(int*, int*, size_t, size_t);
int* _8_gatherCommonElements(int*, int*, size_t, size_t);

size_t defineSizeForExclusiveElements(int*, int*, size_t, size_t);
int* _9_exclusiveAElements(int*, int*, size_t, size_t);
