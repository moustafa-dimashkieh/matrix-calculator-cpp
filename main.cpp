//
// Updated by Moustafa Dimashkieh on 1/27/2023.
//

#include "test/test-matrix.h"
#include "matrix/Matrix.h"
#include <iostream>

using namespace std;

void fillMatrix(Matrix& matrix, int row, int column);

int main() {
    // Test File
    // matrixTest();
    cout << "***** Linear Calculator *****" << endl;
    int choice;
    do{
        cout << "1. Matrix Addition\n"
             << "2. Matrix Subtraction\n"
             << "3. Matrix Multiplication\n"
             << "4. Matrix Determinant\n"
             << "5. Matrix Inverse\n"
             << "6. Matrix Transpose.\n"
             << "7. Exit\n"
             << "Choose from the following menu:";

        cin >> choice;
        switch (choice) {
            case 1:{ // Addition
                int row, column;

                // Number of rows and columns for both matrices must be equal.
                cout << "Enter the number of rows and columns for the 2 matrices:\n";
                cout << "Rows:";
                cin >> row;
                cout << "Columns:";
                cin >> column;

                Matrix first(row, column), second(row, column);

                // Creating the entries of the First Matrix.
                cout << "Enter the elements of the first matrix:\n";
                fillMatrix(first, row, column);

                // Displaying the First Matrix
                first.output();

                // Creating the entries of the Second Matrix.
                cout << "Enter the elements of the second matrix:\n";
                fillMatrix(second, row, column);

                // Displaying the Second Matrix
                second.output();

                // Calculating the sum of the first and second matrices
                Matrix result = first.add(second);

                // Displaying Results
                cout << "The sum of the first and second matrices is:\n";
                result.output();

                break;
            }

            case 2:{ // Subtraction
                int row, column;

                // Number of rows and columns for both matrices must be equal.
                cout << "Enter the number of rows and columns for the 2 matrices:\n";
                cout << "Rows:";
                cin >> row;
                cout << "Columns:";
                cin >> column;

                Matrix first(row, column), second(row, column);

                // Creating the entries of the First Matrix.
                cout << "Enter the elements of the first matrix:\n";
                fillMatrix(first, row, column);

                // Displaying the First Matrix
                first.output();

                // Creating the entries of the Second Matrix.
                cout << "Enter the elements of the second matrix:\n";
                fillMatrix(second, row, column);

                // Displaying the Second Matrix
                second.output();

                // Calculating the difference between the first and second matrices
                Matrix result = first.subtract(second);

                // Displaying Results
                cout << "The difference between the first and second matrices is:\n";
                result.output();

                break;

            }

            case 3:{ //Multiplication
                int rowFirst, columnFirst;
                int rowSecond, columnSecond;

                cout << "Enter  the number of rows and columns for first matrix:\n";
                cout << "Rows:";
                cin >> rowFirst;
                cout << "Columns: ";
                cin >> columnFirst;

                cout << "Enter the number of rows and columns for second matrix:\n";
                cout << "Rows:";
                cin >> rowSecond;
                cout << "Columns2:";
                cin >> columnSecond;

                // The number of columns of the first matrix must be equal to the number of rows of the second matrix.
                while (columnFirst != rowSecond)
                {
                    cout << "Error! The number of columns of the first matrix \nis not equal to the number of rows of the second matrix." << endl;

                    cout << "Enter  the number of rows and columns for first matrix:\n";
                    cout << "Rows:";
                    cin >> rowFirst;
                    cout << "Columns:";
                    cin >> columnFirst;

                    cout << "Enter the number of rows and columns for second matrix:\n";
                    cout << "Rows:";
                    cin >> rowSecond;
                    cout << "Columns:";
                    cin >> columnSecond;
                }

                Matrix first(rowFirst, columnFirst), second(rowSecond, columnSecond);

                // Creating the entries of the First Matrix.
                cout << "Enter the elements of the first matrix:\n";
                fillMatrix(first, rowFirst, columnFirst);

                // Displaying the First Matrix
                first.output();

                // Creating the entries of the Second Matrix.
                cout << "Enter the elements of the second matrix:\n";
                fillMatrix(second, rowFirst, columnFirst);

                // Displaying the Second Matrix
                second.output();

                // Calculating the product of the first and second matrices
                Matrix result = first.multiply(second);

                // Displaying Results
                cout << "The product between the first and second matrices is:\n";
                result.output();

                break;

            }

        }
    }while (choice!=7);

    return 0;
}

void fillMatrix(Matrix& matrix, int row, int column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            int value;
            cout << "index[" << i+1 << "][" << j+1 << "]:";
            cin >> value;
            matrix.set(i,j,value);
        }
    }
}

