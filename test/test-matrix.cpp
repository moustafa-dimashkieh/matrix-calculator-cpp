//
// Updated by Moustafa Dimashkieh on 1/27/2023.
//

#include "../matrix/Matrix.h"
#include <iostream>

using std::cout;
using std::endl;

void matrixTest() {

    // Set the values of Matrix m1
    Matrix m1(3, 3);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(0, 2, 3);
    m1.set(1, 0, 4);
    m1.set(1, 1, 5);
    m1.set(1, 2, 6);
    m1.set(2, 0, 7);
    m1.set(2, 1, 8);
    m1.set(2, 2, 9);
    cout << "Matrix m1:\n";
    m1.output();

    // Set the values of Matrix m2
    Matrix m2(3, 3);
    m2.set(0, 0, 9);
    m2.set(0, 1, 8);
    m2.set(0, 2, 7);
    m2.set(1, 0, 6);
    m2.set(1, 1, 5);
    m2.set(1, 2, 4);
    m2.set(2, 0, 3);
    m2.set(2, 1, 2);
    m2.set(2, 2, 1);
    cout << "Matrix m2:\n";
    m2.output();

    // Test case 1: Test add() function
    cout << "Test case 1: Test add() function\n";
    Matrix result = m1.add(m2);
    result.output();

    // Test case 2: Test subtract() function
    cout << "Test case 2: Test subtract() function\n";
    result = m1.subtract(m2);
    result.output();

    // Test case 3: Test multiply() function
    cout << "Test case 3: Test multiply() function\n";
    result = m1.multiply(m2);
    result.output();

    // Test case 4: Test transpose() function
    cout << "Test case 4: Test transpose() function\n";
    result = m1.transpose();
    result.output();

    // Test case 5: Test power() function
    cout << "Test case 5: Test power() function\n";
    result = m1.power(3);
    result.output();

    // Test case 6: Test inverse() function
    cout << "Test case 6: Test inverse() function\n";
    // result = m1.inverse();
    // result.output();
    cout << "Algorithm not complete yet.\n";


    // Test case 7: Test determinant() function
    cout << "Test case 7: Test determinant() function\n";
    // double det = m1.determinant();
    // cout << "Determinant of matrix: " << det << "\n";
    cout << "Algorithm not complete yet.\n";
}
