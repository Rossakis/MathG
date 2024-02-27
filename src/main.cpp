#include <iostream>
#include "../include/mathg.h"
using namespace mathg;

int main() {
    float degree {90};
    float radians = DegreeToRad(degree);

    std::cout << degree << "degrees is " << radians << "radians" << std::endl;

    return 0;
}