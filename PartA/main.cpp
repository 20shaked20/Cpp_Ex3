#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

int main()
{

    bool flag;
    double scalar;
    string op;
    Matrix mat1;
    Matrix mat2;
    cout << "Welcome to matrix calculator..." << endl;

    cout << "Insert first matrix values: " << endl;
    cin >> mat1;

    cout << "Insert second matrix values: " << endl;
    cin >> mat2;

    cout << "Insert scalar if you wish to mult in scalar or -1 if not" << endl;
    cin >> scalar;

    cout << "Insert method " << endl;
    cin >> op;

    if (scalar == -1)
    {
        if (op == "mat1+mat2")
        {
            cout << mat1 + mat2 << endl;
        }
        if (op == "mat1-mat2")
        {
            cout << mat1 - mat2 << endl;
        }
        if (op == "mat1*mat2")
        {
            cout << mat1 * mat2 << endl;
        }
        if (op == "mat1 == mat2")
        {
            bool ans = (mat1 == mat2);
            cout << ans << endl;
        }
    }
    else
    {
        if (op == "mat1*scalar")
        {
            cout << mat1 * scalar << endl;
        }
        if (op == "mat2*scalar")
        {
            cout << mat2 * scalar << endl;
        }
    }
}
