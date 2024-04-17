#include <iostream>
#include "../include/mathg.h"
using namespace mathg;

int main() {
    Vector3 a = Vector3(4,1);
    Vector3 b = Vector3::zero;
    b += Vector3(0,2,4) * 4;

    auto matrix = Matrix2x2(1);
    auto matrix2  = Matrix2x2(3);
    matrix = matrix - matrix2;

    //std::cout << "Vector b is: " << b.ToString(1) << std::endl;
    std::cout << matrix.ToString(3) << std::endl;
    std::cout << matrix2.ToString(3) << std::endl;


    return 0;
}