//
// Created by Moustafa Dimashkieh on 1/27/2023.
//

#ifndef MATRIX_CALCULATOR_CPP_MATRIX_H
#define MATRIX_CALCULATOR_CPP_MATRIX_H


class Matrix {

private:
    int numRows;
    int numCols;
    double** matrix;

public:
    // constructor
    Matrix(int numRows, int numCols);

    // destructor
    ~Matrix();

    // set the value of an element in the matrix
    void set(int row, int col, double value);

    // get the value of an element in the matrix
    double get(int row, int col) const;

    // add two matrices
    Matrix add(const Matrix& other);

    // subtract two matrices
    Matrix subtract(const Matrix& other);

    //multiply two matrices
    Matrix multiply(const Matrix& other);

    // transpose the matrix
    Matrix transpose();

    // raise the matrix to a given power
    Matrix power(int exponent);

    // calculate the inverse of the matrix
    Matrix inverse();

    // calculate the determinant of the matrix
    double determinant();

    // output the matrix
    void output();
};


#endif //MATRIX_CALCULATOR_CPP_MATRIX_H
