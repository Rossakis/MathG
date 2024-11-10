//
// Created by GiorgosDev on 4/10/2024.
//

#ifndef MATRICES_H
#define MATRICES_H
#include <MathG.h>

//TODO: incorporate vectors into the possible operations with matrices
namespace MathG{
    struct Matrix2 {
        float m11;
        float m12;
        float m21;
        float m22;

        ///Identity(2) matrix
        static const Matrix2 ID;

        explicit Matrix2(const float value) : Matrix2(value, value, value, value) {}

        explicit Matrix2(const float m1, const float m2, const float m3, const float m4) : m11(m1), m12(m2), m21(m3), m22(m4) {
        }

        Matrix2& operator = (const Matrix2 matrix) {
            if(this != &matrix) {
                this->m11 = matrix.m11;
                this->m12 = matrix.m12;
                this->m21 = matrix.m21;
                this->m22 = matrix.m22;
            }
            return *this;
        }

        Matrix2 operator + (const Matrix2 &matrix) const {
            return Matrix2(this->m11 + matrix.m11,
                this-> m12 + matrix.m12,
                this-> m21 + matrix.m21,
                this-> m22 + matrix.m22);
        }

        Matrix2 operator - (const Matrix2 &matrix) const {
            return Matrix2(this->m11 - matrix.m11,
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

        Matrix2 operator * (const Matrix2 &matrix) const {
            return Matrix2((this->m11 * matrix.m11) + (this->m12 * matrix.m21),
                             (this->m11 * matrix.m12) + (this->m12 * matrix.m22),
                             (this->m21 * matrix.m11) + (this->m22 * matrix.m21),
                             (this->m21 * matrix.m12) + (this->m22 * matrix.m22));
        }

        //TODO: add operator * matrix2x2 with vector2

        ///Returns a transposed instance of this matrix.
        [[nodiscard]] Matrix2 Transpose() const{
            return Matrix2(this->m11, this->m21, this->m12, this->m22);
        }

        [[nodiscard]] static Matrix2 Rotate(float degrees) {
            return Matrix2(cos(degrees),
                             sin(degrees),
                             -sin(degrees),
                             cos(degrees));
        }

        ///Uniform scale
        [[nodiscard]] Matrix2 Scale(float scalar) const{
            return Matrix2(this->m11 * scalar, this->m12, this->m21, this->m22 * scalar);
        }

        ///Non-Uniform scale
        [[nodiscard]] Matrix2 Scale(float scalarX, float scalarY) const {
            return Matrix2(this->m11 * scalarX, this->m12, this->m21, this->m22 * scalarY);
        }

        [[nodiscard]] static Matrix2 SkewX(float scalarX) {
            return Matrix2(1, 0, scalarX, 1);
        }

        [[nodiscard]] static Matrix2 SkewY(float scalarY) {
            return Matrix2(1, scalarY, 0, 1);
        }

        [[nodiscard]] static Matrix2 SkewXY(float scalarX, float scalarY) {
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
    const Matrix2 Matrix2::ID = Matrix2(0.0f, 0.0f, 0.0f, 0.0f);

    //TODO: Add Matrix3x3

    struct Matrix3 {
        float m11;
        float m12;
        float m13;
        float m21;
        float m22;
        float m23;
        float m31;
        float m32;
        float m33;

        ///Identity(2) matrix
        static const Matrix3 ID;

        explicit Matrix3(const float value) : Matrix3(value, value, value, value, value, value, value, value, value) {}

        explicit Matrix3
        (const float m11, const float m12, const float m13, const float m21, const float m22, const float m23, const float m31, const float m32, const float m33) : 
        m11(m11), m12(m12), m21(m13), m22(m21), m22(m22), m22(m23), m22(m31), m22(m32), m22(m33) {
        }

        Matrix3& operator = (const Matrix3 matrix) {
            if(this != &matrix) {
                this->m11 = matrix.m11;
                this->m12 = matrix.m12;
                this->m21 = matrix.m21;
                this->m22 = matrix.m22;
            }
            return *this;
        }

        Matrix3 operator + (const Matrix3 &matrix) const {
            return Matrix2x2(this->m11 + matrix.m11,
                             this-> m12 + matrix.m12,
                             this-> m21 + matrix.m21,
                             this-> m22 + matrix.m22);
        }

        Matrix3 operator - (const Matrix3 &matrix) const {
            return Matrix2x2(this->m11 - matrix.m11,
                             this-> m12 - matrix.m12,
                             this-> m21 - matrix.m21,
                             this-> m22 - matrix.m22);
        }

        //For more modular access to the field members, e.g. type 1 to get member m11 of matrix
        float& operator[](const int firstIndex, const int secondIndex) {
            switch (index) {
                case 1:
                    switch (secondIndex)
                    {
                    case 1:
                        return this->m11;
                    case 2:
                        return this->m12;
                    case 3:
                        return this->m13;
                    default:
                        break;
                    }
                case 2:
                    switch (secondIndex)
                    {
                    case 1:
                        return this->m21;
                    case 2:
                        return this->m22;
                    case 3:
                        return this->m23;
                    default:
                        break;
                    }
                case 3:
                    switch (secondIndex)
                    {
                    case 1:
                        return this->m31;
                    case 2:
                        return this->m32;
                    case 3:
                        return this->m33;
                    default:
                        break;
                    }
                default:
                    throw InvalidParametersException("Nonexistent matrix coordinates passed as parameters!");
            }
        }

        Matrix3 operator * (const Matrix3 &matrix) const {
            return Matrix3(
                (this->m11 * matrix.m11) + (this->m12 * matrix.m21),
                (this->m11 * matrix.m12) + (this->m12 * matrix.m22),
                (this->m21 * matrix.m11) + (this->m22 * matrix.m21),
                (this->m21 * matrix.m12) + (this->m22 * matrix.m22));
        }

        ///Returns a transposed instance of this matrix.
        [[nodiscard]] Matrix3 Transpose() const{
            return Matrix2x2(this->m11, this->m21, this->m12, this->m22);
        }

        [[nodiscard]] static Matrix3 Rotate(float degrees) {
            return Matrix3(cos(degrees),
                             sin(degrees),
                             -sin(degrees),
                             cos(degrees));
        }

        ///Uniform scale
        [[nodiscard]] Matrix3 Scale(float scalar) const{
            return Matrix3(
                this->m11 * scalar, 
                this->m12, 
                this->m21, 
                this->m22 * scalar);
        }

        ///Non-Uniform scale
        [[nodiscard]] Matrix3 Scale(float scalarX, float scalarY) const {
            return Matrix3(this->m11 * scalarX, this->m12, this->m21, this->m22 * scalarY);
        }

        [[nodiscard]] static Matrix3 SkewX(float scalarX) {
            return Matrix3(1, 0, scalarX, 1);
        }

        [[nodiscard]] static Matrix3 SkewY(float scalarY) {
            return Matrix3(1, scalarY, 0, 1);
        }

        [[nodiscard]] static Matrix3 SkewXY(float scalarX, float scalarY) {
            return SkewX(scalarX) * SkewY(scalarY);
        }
        //TODO:
        //     Chapter-5
        // Rotate()
        // Scale(x,y) and Scale(k)  -> uniform scale
        // Project()
        // Reflect()
        // Skew()
        //     Chapter-6
        // Determinant(): Calculates the determinant of the matrix.
        // Inverse(): Returns a new matrix that is the inverse of the current matrix (if it exists).
        // Utility functions for specific operations you might need, like rotation or scaling transformations (depending on your library's focus).


        //DEBUG
        struct InvalidParametersException : std::runtime_error {
            explicit InvalidParametersException(const std::string& message) : std::runtime_error(message) {}
        };

        ///By default, shows the maximum amount of digits for each float number of this vector
        [[nodiscard]] std::string ToString(const int precisionNumber = 7) const {
            std::stringstream ss;
            ss  << std::fixed << std::setprecision(precisionNumber)
                << "|" << this->m11 << ", " << this->m12 << ", " << this->m13 << "|\n"
                << "|" << this->m21 << ", " << this->m22 << ", " << this->m23 << "|\n"
                << "|" << this->m31 << ", " << this->m32 << ", " << this->m33 << "|\n";

            return ss.str();
        }
    };
    const Matrix3 Matrix3::ID = Matrix3(0.0f, 0.0f, 0.0f, 
                               0.0f, 0.0f, 0.0f,
                               0.0f, 0.0f, 0.0f);
}

#endif //MATRICES_H
