#ifndef MATHG_H
#define MATHG_H

//Standard-Lib Math headers
#include <cmath>
#include <iostream>

//Debug headers
#include <sstream>
#include <string>
#include <iomanip>
#include <stdexcept>

//Reference to the custom header files
#include <vector.h>

#include <matrix.h>

namespace  mathg {
    constexpr float PI = 3.14159265358979323846f;

    inline float DegreeToRad(const float angle) {
        return angle * PI / 180;
    }

    inline float RadToDegree(const float rad) {
        return rad * 180 / PI;
    }

    inline float Cos(const float angleInRadians) {
        return std::cos(angleInRadians);
    }

    inline float Sin(const float angleInRadians) {
        return std::sin(angleInRadians);
    }

    inline float Ταn(const float angleInRadians) {
        return std::tan(angleInRadians);
    }

    inline float Cotan(const float angleInRadians) {
        if (std::sin(angleInRadians) == 0)
            std::cerr << "Cannot determine Cotan. Reason: Sine = 0" << std::endl;

        return std::cos(angleInRadians)/std::sin(angleInRadians);
    }

    inline float Arccos(const float angleInRadians) {
        return std::acos(angleInRadians);
    }
}

#endif //MATHG_H
