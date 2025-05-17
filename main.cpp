/*File main.cpp
 *  @brief Main function to demonstrate matrix operations.
 *  @author Avramis Kontou
 *  @details This file contains the main function to demonstrate the use of matrix operations.
 */ 
#include <iostream>
#include "matrix.h"
using namespace std;
/**main
 *  @brief Main function to demonstrate matrix operations.
 *  @return 0 on success.
 *  @details This function provides a menu-driven interface for the user to perform various matrix operations.
 */
int main() {
    double matrix[MAX_ROW][MAX_COL];
    int choice;
    int index;
    fillWithRandomNum(matrix, MAX_ROW);
    //display the menu with option by the user 
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Print Matrix\n";
        cout << "2. Fill Matrix with Random Numbers\n";
        cout << "3. Sum of a Specific Row\n";
        cout << "4. Sum of a Specific Column\n";
        cout << "5. Find Max Value\n";
        cout << "6. Find Min Value\n";
        cout << "7. Average of All Elements\n";
        cout << "8. Sum of All Rows\n";
        cout << "9. Sum of All Columns\n";
        cout << "10. Check if Identity Matrix\n";
        cout << "11. Make Identity Matrix\n";
        cout << "12. Sum of Main Diagonal\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        //use switch statement for decision making 
        switch (choice) {
        case 1:
            printMatrix(matrix, MAX_ROW);
            break;
        case 2:
            fillWithRandomNum(matrix, MAX_ROW);
            cout << "Matrix filled with random numbers.\n";
            break;
        case 3:
            cout << "Enter row (0-" << MAX_ROW - 1 << "): ";
            cin >> index;
            cout << "Sum of row " << index << ": " << sumOfRow(matrix, index, MAX_ROW) << endl;
            break;
        case 4:
            cout << "Enter column (0-" << MAX_COL - 1 << "): ";
            cin >> index;
            cout << "Sum of column " << index << ": " << sumOfCol(matrix, index, MAX_ROW) << endl;
            break;
        case 5:
            cout << "Max value: " << findMaxValue(matrix, MAX_ROW) << endl;
            break;
        case 6:
            cout << "Min value: " << findMinValue(matrix, MAX_ROW) << endl;
            break;
        case 7:
            cout << "Average value: " << averageValue(matrix, MAX_ROW) << endl;
            break;
        case 8: {
            double* rowSums = sumOfRows(matrix, MAX_ROW);
            cout << "Sum of each row:\n";
            for (int i = 0; i < MAX_ROW; i++) {
                cout << "Row " << i << ": " << rowSums[i] << endl;
            }
            delete[] rowSums;
            break;
        }
        case 9: {
            double* colSums = sumOfCols(matrix, MAX_ROW);
            cout << "Sum of each column:\n";
            for (int i = 0; i < MAX_COL; i++) {
                cout << "Column " << i << ": " << colSums[i] << endl;
            }
            delete[] colSums;
            break;
        }
        case 10:
            if (isIdentityMatrix(matrix, MAX_ROW))
                cout << "Matrix IS identity.\n";
            else
                cout << "Matrix is NOT identity.\n";
            break;
        case 11:
            makeIdentityMatrix(matrix, MAX_ROW);
            cout << "Matrix turned into identity matrix.\n";
            break;
        case 12:
            cout << "Sum of main diagonal: " << sumOfDiagonal(matrix, MAX_ROW) << endl;
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option!\n";
        }
    } while (choice != 0);

    return 0;
}
