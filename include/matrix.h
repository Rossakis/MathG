//
// Created by GiorgosDev on 4/10/2024.
//

#ifndef MATRICES_H
#define MATRICES_H
#include <mathg.h>

namespace mathg{
    struct Matrix2x2 {
        float m11;
        float m12;
        float m21;
        float m22;

        static const Matrix2x2 identity;//identity matrix

        explicit Matrix2x2(const float value) : Matrix2x2(value, value, value, value) {}

        explicit Matrix2x2(const float m1, const float m2, const float m3, const float m4) : m11(m1), m12(m2), m21(m3), m22(m4) {
        }

        //TODO: Overloaded Operators (+, -, *, =)

        //TODO:
        /*
        Transpose(): Returns a new matrix with rows and columns swapped.
        Determinant(): Calculates the determinant of the matrix.
        Inverse(): Returns a new matrix that is the inverse of the current matrix (if it exists).
        Utility functions for specific operations you might need, like rotation or scaling transformations (depending on your library's focus).
        */
    };

    const Matrix2x2 Matrix2x2::identity = Matrix2x2(0.0f, 0.0f, 0.0f, 0.0f);
}

#endif //MATRICES_H
