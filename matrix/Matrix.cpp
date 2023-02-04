//
// Updated by Moustafa Dimashkieh on 2/4/2023.
//

#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// constructor
Matrix::Matrix(int numRows, int numCols) {
    this->numRows = numRows;
    this->numCols = numCols;
    matrix = new double*[numRows];
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new double[numCols];
    }
}

// destructor
Matrix::~Matrix() {
    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// set the value of an element in the matrix
void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}

// get the value of an element in the matrix
double Matrix::get(int row, int col) const {
    return matrix[row][col];
}

// add two matrices
Matrix Matrix::add(const Matrix& other) {
    if (numRows != other.numRows || numCols != other.numCols) {
        cerr << "Cannot add matrices of different sizes." << endl;
        exit(1);
    }

    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

// subtract two matrices
Matrix Matrix::subtract(const Matrix& other) {
    if (numRows != other.numRows || numCols != other.numCols) {
        cerr << "Cannot subtract matrices of different sizes." << endl;
        exit(1);
    }

    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

//multiply two matrices
Matrix Matrix::multiply(const Matrix& other) {
    if (numCols != other.numRows) {
        cerr << "Cannot multiply matrices with incompatible dimensions." << endl;
        exit(1);
    }

    Matrix result(numRows, other.numCols);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < other.numCols; j++) {
            for (int k = 0; k < numCols; k++) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

// transpose of a matrix
Matrix Matrix::transpose() {
    Matrix result(numCols, numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result.matrix[j][i] = matrix[i][j];
        }
    }
    return result;
}

// matrix power (matrix raised to a power)
Matrix Matrix::power(int exponent) {
    if (numRows != numCols) {
        cerr << "Cannot raise a non-square matrix to a power." << endl;
        exit(1);
    }

    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result.matrix[i][j] = pow(matrix[i][j], exponent);
        }
    }
    return result;
}

// inverse of a matrix
Matrix Matrix::inverse() {
    // check if matrix is invertible
    if (numRows != numCols) {
        cerr << "Cannot find inverse of a non-square matrix." << endl;
        exit(1);
    }
    if (determinant() == 0) {
        cerr << "Cannot find inverse of a singular matrix." << endl;
        exit(1);
    }
    // code to calculate inverse of matrix goes here
    // ...
    // return result
}

// determinant of a matrix
double Matrix::determinant() {
    if (numRows != numCols) {
        cerr << "Cannot find determinant of a non-square matrix." << endl;
        exit(1);
    }

    int size = numRows;
    double det = 0;
    if (size == 1) {
        det = matrix[0][0];
    }
    else if (size == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        for (int i = 0; i < size; i++) {
            Matrix subMatrix(size - 1, size - 1);
            for (int j = 1; j < size; j++) {
                int subMatrixCol = 0;
                for (int k = 0; k < size; k++) {
                    if (k == i) {
                        continue;
                    }
                    subMatrix.matrix[j-1][subMatrixCol] = matrix[j][k];
                    subMatrixCol++;
                }
            }
            det += pow(-1, i) * matrix[0][i] * subMatrix.determinant();
        }
    }
    return det;
}

// output matrix to console
void Matrix::output() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << setw(5) << left << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
