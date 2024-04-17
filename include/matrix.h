//
// Created by GiorgosDev on 4/10/2024.
//

#ifndef MATRICES_H
#define MATRICES_H
#include <mathg.h>

namespace mathg{
    struct Matrix2x2 {
    private:
        float m11;
        float m12;
        float m21;
        float m22;

    public:
        ///Identity matrix
        static const Matrix2x2 I2;

        explicit Matrix2x2(const float value) : Matrix2x2(value, value, value, value) {}

        explicit Matrix2x2(const float m1, const float m2, const float m3, const float m4) : m11(m1), m12(m2), m21(m3), m22(m4) {
        }

        //TODO: Overloaded Operators (*)
        Matrix2x2& operator = (const Matrix2x2 matrix) {
            if(this != &matrix) {
                this->m11 = matrix.m11;
                this->m12 = matrix.m12;
                this->m21 = matrix.m21;
                this->m22 = matrix.m22;
            }
            return *this;
        }

        Matrix2x2 operator + (const Matrix2x2 &matrix) const {
            return Matrix2x2(this->m11 + matrix.m11,
                this-> m12 + matrix.m12,
                this-> m21 + matrix.m21,
                this-> m22 + matrix.m22);
        }

        Matrix2x2 operator - (const Matrix2x2 &matrix) const {
            return Matrix2x2(this->m11 - matrix.m11,
                this-> m12 - matrix.m12,
                this-> m21 - matrix.m21,
                this-> m22 - matrix.m22);
        }

        float& operator[](const int index) {
            switch (index) {
                case 1:
                    return this->m11;
                case 2:
                    return this->m12;
                case 3:
                    return this->m21;
                case 4:
                    return this->m22;
                default:
                    //When passing wrong indices
                    throw InvalidParametersException("Nonexistent matrix coordinates passed as parameters!");
                    break;
            }
        }

        Matrix2x2 operator * (const Matrix2x2 &matrix) const {
            Matrix2x2 matrix2 = Matrix2x2(0);

            /*for (int i= 0; i < 2; i++) {
                C[i, j] = A[i, 1] * B[1, j] + A[i, 2] * B[2, j]  // Dot product of row i in A and column j in B
            }*/

            return Matrix2x2(this->m11 - matrix.m11,
                this-> m12 - matrix.m12,
                this-> m21 - matrix.m21,
                this-> m22 - matrix.m22);
        }

        //TODO:
        /*
        Transpose(): Returns a new matrix with rows and columns swapped.
        Determinant(): Calculates the determinant of the matrix.
        Inverse(): Returns a new matrix that is the inverse of the current matrix (if it exists).
        Utility functions for specific operations you might need, like rotation or scaling transformations (depending on your library's focus).
        */

        //DEBUG
        struct InvalidParametersException : std::runtime_error {
            explicit InvalidParametersException(const std::string& message) : std::runtime_error(message) {}
        };

        ///By default, shows the maximum amount of digits for each float number of this vector
        [[nodiscard]] std::string ToString(const int precisionNumber = 7) const {
            std::stringstream ss;
            ss << std::fixed << std::setprecision(precisionNumber)
            << "|" << this->m11 << ", " << this->m12 << "|\n"
            << "|" << this->m21 << ", " << this->m22 << "|\n";

            return ss.str();
        }
    };

    const Matrix2x2 Matrix2x2::I2 = Matrix2x2(0.0f, 0.0f, 0.0f, 0.0f);
}

#endif //MATRICES_H
