/** \file matrix.h
* \brief Header file for matrix operations.
* \author Avramis kontou 
* \date 15/5/25
*
*This header file contains function declarations for various matrix operations,
* including filling a matrix with random numbers, calculating sums of rows and columns,
* and finding maximum and minimum values in a matrix.
*/
#ifndef MATRIX_H
#define MATRIX_H
const int MAX_ROW = 5; //initialize a row for a matrix
const int MAX_COL = 5;//initialize a column for a matrix 

// Functions prototypes 
double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow);
double sumOfCol(const double mat[][MAX_COL], const int column, const int maxRow);
void fillWithRandomNum(double mat[][MAX_COL], const int maxRow);
void printMatrix(const double mat[][MAX_COL], const int maxRow);

// Add three functions
double findMaxValue(const double mat[][MAX_COL], const int maxRow);
double findMinValue(const double mat[][MAX_COL], const int maxRow);
double averageValue(const double mat[][MAX_COL], const int maxRow);

// Three more functions prototypes 
bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow);
void makeIdentityMatrix(double mat[][MAX_COL], const int maxRow);
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow);

// Advanced functions(extension)
double* sumOfRows(const double mat[][MAX_COL], const int maxRow);
double* sumOfCols(const double mat[][MAX_COL], const int maxRow);
#endif

