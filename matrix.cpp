/*File Matrix.cpp
 *  @brief Implementation of matrix operations of functions.
 *  @author Avramis Kontou
 *  @details This file contains the implementation of functions to manipulate a matrix.
 */ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matrix.h"
using namespace std;
/*functions
 *  @brief sumOfRow calculates the sum of a specific row in a matrix.
 *  @param mat array for the matrix to be processed.
 *  @param row The index of the row to sum.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return The sum of the specified row.
 */ 
double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow) {
    if (row < 0 || row >= maxRow) return 0;
    double sum = 0;
    for (int j = 0; j < MAX_COL; j++) {
        sum += mat[row][j];
    }
    return sum;
}
/*functions
 *  @brief sumOfCol calculates the sum of a specific column in a matrix.
 *  @param mat array for the matrix to be processed.
 *  @param column The index of the column to sum.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return The sum of the specified column.
 */ 
double sumOfCol(const double mat[][MAX_COL], const int column, const int maxRow) {
    if (column < 0 || column >= MAX_COL) return 0;
    double sum = 0;
    for (int i = 0; i < maxRow; i++) {
        sum += mat[i][column];
    }
    return sum;
}
/*functions
 *  @brief fillWithRandomNum fills a matrix with random numbers between 1 and 100.
 *  @param mat array for the matrix to be filled.
 *  @param maxRow The maximum number of rows in the matrix.
 */
void fillWithRandomNum(double mat[][MAX_COL], const int maxRow) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            mat[i][j] = rand() % 100 + 1; // random number between 1 and 100
        }
    }
}
/*functions
 *  @brief printMatrix prints the contents of a matrix.
 *  @param mat array for the matrix to be printed.
 *  @param maxRow The maximum number of rows in the matrix.
 */
void printMatrix(const double mat[][MAX_COL], const int maxRow) {
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}
/*functions
 *  @brief findMaxValue finds the maximum value in a matrix.
 *  @param mat array for the matrix to be processed.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return The maximum value found in the matrix.
 */
double findMaxValue(const double mat[][MAX_COL], const int maxRow) {
    double max = mat[0][0];
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (mat[i][j] > max) {
                max = mat[i][j];
            }
        }
    }
    return max;
}
/*functions
 *  @brief findMinValue finds the minimum value in a matrix.
 *  @param mat array for the matrix to be processed.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return The minimum value found in the matrix.
 */
double findMinValue(const double mat[][MAX_COL], const int maxRow) {
    double min = mat[0][0];
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (mat[i][j] < min) {
                min = mat[i][j];
            }
        }
    }
    return min;
}
/*functions
 *  @brief averageValue calculates the average value of all elements in a matrix.
 *  @param mat array for the matrix to be processed.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return The average value of all elements in the matrix.
 */
double averageValue(const double mat[][MAX_COL], const int maxRow) {
    double sum = 0;
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            sum += mat[i][j];
        }
    }
    return sum / (maxRow * MAX_COL);
}
/*functions
 *  @brief sumOfRows calculates the sum of each row in a matrix.
 *  @param mat array for the matrix to be processed.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return An array containing the sum of each row.
 */
double* sumOfRows(const double mat[][MAX_COL], const int maxRow) {
    double* rowSums = new double[maxRow];
    for (int i = 0; i < maxRow; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < MAX_COL; j++) {
            rowSums[i] += mat[i][j];
        }
    }
    return rowSums;
}
/*functions
 *  @brief sumOfCols calculates the sum of each column in a matrix.
 *  @param mat array for the matrix to be processed.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return An array containing the sum of each column.
 */
double* sumOfCols(const double mat[][MAX_COL], const int maxRow) {
    double* colSums = new double[MAX_COL];
    for (int j = 0; j < MAX_COL; j++) {
        colSums[j] = 0;
        for (int i = 0; i < maxRow; i++) {
            colSums[j] += mat[i][j];
        }
    }
    return colSums;
}
/*functions
 *  @brief isIdentityMatrix checks if a matrix is an identity matrix.
 *  @param mat array for the matrix to be checked.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return true if the matrix is an identity matrix, false otherwise.
 */
bool isIdentityMatrix(const double mat[][MAX_COL], const int maxRow) {
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (i == j && mat[i][j] != 1) return false;
			if (i != j && mat[i][j] != 0) return false;
        }
    }
    return true; 
}
/*functions
 *  @brief makeIdentityMatrix creates an identity matrix.
 *  @param mat array for the matrix to be created.
 *  @param maxRow The maximum number of rows in the matrix.
 */
void makeIdentityMatrix(double mat[][MAX_COL], const int maxRow) {
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (i == j)
                mat[i][j] = 1;
            
        }
    }
}
/*functions
 *  @brief sumOfDiagonal calculates the sum of the diagonal elements of a matrix.
 *  @param mat array for the matrix to be processed.
 *  @param maxRow The maximum number of rows in the matrix.
 *  @return The sum of the diagonal elements.
 */
double sumOfDiagonal(const double mat[][MAX_COL], const int maxRow) {
    double sum = 0;
    for (int i = 0; i <= maxRow; i++) { 
        sum += mat[i][i];
    }
    return sum;
}

