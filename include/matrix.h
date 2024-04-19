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

        ///Identity(2) matrix
        static const Matrix2x2 ID;

        explicit Matrix2x2(const float value) : Matrix2x2(value, value, value, value) {}

        explicit Matrix2x2(const float m1, const float m2, const float m3, const float m4) : m11(m1), m12(m2), m21(m3), m22(m4) {
        }

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

        //For more modular access to the field members
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
            }
        }

        Matrix2x2 operator * (const Matrix2x2 &matrix) const {
            return Matrix2x2((this->m11 * matrix.m11) + (this->m12 * matrix.m21),
                             (this->m11 * matrix.m12) + (this->m12 * matrix.m22),
                             (this->m21 * matrix.m11) + (this->m22 * matrix.m21),
                             (this->m21 * matrix.m12) + (this->m22 * matrix.m22));
        }

        ///Returns a transposed instance of this matrix.
        [[nodiscard]] Matrix2x2 Transpose() const{
            return Matrix2x2(this->m11, this->m21, this->m12, this->m22);
        }

        [[nodiscard]] static Matrix2x2 Rotate(float degrees) {
            return Matrix2x2(cos(degrees),
                             sin(degrees),
                             -sin(degrees),
                             cos(degrees));
        }

        ///Uniform scale
        [[nodiscard]] Matrix2x2 Scale(float scalar) const{
            return Matrix2x2(this->m11 * scalar, this->m12, this->m21, this->m22 * scalar);
        }

        ///Non-Uniform scale
        [[nodiscard]] Matrix2x2 Scale(float scalarX, float scalarY) const {
            return Matrix2x2(this->m11 * scalarX, this->m12, this->m21, this->m22 * scalarY);
        }

        [[nodiscard]] static Matrix2x2 SkewX(float scalarX) {
            return Matrix2x2(1, 0, scalarX, 1);
        }

        [[nodiscard]] static Matrix2x2 SkewY(float scalarY) {
            return Matrix2x2(1, scalarY, 0, 1);
        }

        [[nodiscard]] static Matrix2x2 SkewXY(float scalarX, float scalarY) {
            return SkewX(scalarX) * SkewY(scalarY);
        }
        //TODO:
        /*
            Chapter-5
        Project()
        Reflect()
            Chapter-6
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
    const Matrix2x2 Matrix2x2::ID = Matrix2x2(0.0f, 0.0f, 0.0f, 0.0f);

    //TODO: Add Matrix3x3

    /*struct Matrix3x3 {
        float m11;
        float m12;
        float m21;
        float m22;

        ///Identity(2) matrix
        static const Matrix2x2 ID;

        explicit Matrix2x2(const float value) : Matrix2x2(value, value, value, value) {}

        explicit Matrix2x2(const float m1, const float m2, const float m3, const float m4) : m11(m1), m12(m2), m21(m3), m22(m4) {
        }

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

        //For more modular access to the field members
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
            }
        }

        Matrix2x2 operator * (const Matrix2x2 &matrix) const {
            return Matrix2x2((this->m11 * matrix.m11) + (this->m12 * matrix.m21),
                             (this->m11 * matrix.m12) + (this->m12 * matrix.m22),
                             (this->m21 * matrix.m11) + (this->m22 * matrix.m21),
                             (this->m21 * matrix.m12) + (this->m22 * matrix.m22));
        }

        ///Returns a transposed instance of this matrix.
        [[nodiscard]] Matrix2x2 Transpose() const{
            return Matrix2x2(this->m11, this->m21, this->m12, this->m22);
        }

        [[nodiscard]] static Matrix2x2 Rotate(float degrees) {
            return Matrix2x2(cos(degrees),
                             sin(degrees),
                             -sin(degrees),
                             cos(degrees));
        }

        ///Uniform scale
        [[nodiscard]] Matrix2x2 Scale(float scalar) const{
            return Matrix2x2(this->m11 * scalar, this->m12, this->m21, this->m22 * scalar);
        }

        ///Non-Uniform scale
        [[nodiscard]] Matrix2x2 Scale(float scalarX, float scalarY) const {
            return Matrix2x2(this->m11 * scalarX, this->m12, this->m21, this->m22 * scalarY);
        }

        [[nodiscard]] static Matrix2x2 SkewX(float scalarX) {
            return Matrix2x2(1, 0, scalarX, 1);
        }

        [[nodiscard]] static Matrix2x2 SkewY(float scalarY) {
            return Matrix2x2(1, scalarY, 0, 1);
        }

        [[nodiscard]] static Matrix2x2 SkewXY(float scalarX, float scalarY) {
            return SkewX(scalarX) * SkewY(scalarY);
        }
        //TODO:
            Chapter-5
        Rotate()
        Scale(x,y) and Scale(k)  -> uniform scale
        Project()
        Reflect()
        Skew()
            Chapter-6
        Determinant(): Calculates the determinant of the matrix.
        Inverse(): Returns a new matrix that is the inverse of the current matrix (if it exists).
        Utility functions for specific operations you might need, like rotation or scaling transformations (depending on your library's focus).


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
    const Matrix2x2 Matrix2x2::ID = Matrix2x2(0.0f, 0.0f, 0.0f, 0.0f);*/
}

#endif //MATRICES_H
