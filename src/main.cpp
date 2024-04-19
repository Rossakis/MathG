#include <iostream>
#include "../include/mathg.h"
using namespace mathg;

int main() {

    Matrix2x2 matrix = Matrix2x2(1, -2, 5, 0);
    Matrix2x2 matrix2  = Matrix2x2(-3, 7, 4, 1/3.0f);
    Matrix2x2 matrix3 = matrix * matrix2;

    std::cout << matrix3.ToString(3) << std::endl;
    std::cout << matrix3.Transpose().ToString(3) << std::endl;

    return 0;
}