#include <iostream>
#include "../include/mathg.h"
using namespace mathg;

int main() {

    Vector3 a = Vector3(4,1);
    Vector3 b = Vector3::zero;
    b += Vector3(0,2,4) * 4;

    std::cout << "Vector b is: " << b.ToString(1) << std::endl;

    return 0;
}