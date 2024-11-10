//
// Created by GiorgosDev on 4/10/2024.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <MathG.h>

namespace  MathG {
    struct Vector2 {
        float x;
        float y;
        float magnitude;
        static const Vector2 zero;

        explicit Vector2(const float xValue = 0, const float yValue = 0) : x(xValue), y(yValue) {
            this->magnitude = std::sqrt(x * x + y * y);
        }

        static float Distance(const Vector2 &vec1, const Vector2 &vec2) {
            return static_cast<float>(std::sqrt(std::pow(vec2.x - vec1.x, 2) + static_cast<float>(std::pow(vec2.y - vec1.y, 2))));
        }

        static float Dot(const Vector2 &vec1, const Vector2 &vec2) {
            return vec1.x * vec2.x + vec1.y * vec2.y;
        }

        static float Angle(const Vector2 &vec1, const Vector2 &vec2) {
            if(vec1.magnitude == 0.0f || vec2.magnitude == 0.0f) {
                std::cout << "Trying to find angle between two Vector2, when one of them is Vector2.zero" << std::endl;
                return 0.0f;
            }
            return std::acos(Dot(vec1, vec2) / (vec1.magnitude * vec2.magnitude));
        }

        Vector2& operator = (const Vector2& vec2) {
            // Check for self-assignment
            if (this != &vec2) {
                this->x = vec2.x;
                this->y = vec2.y;
            }
            return *this; // Return a reference to the current object
        }

        Vector2 operator + (const Vector2 &vec2) const {
            return Vector2(this->x + vec2.x, this->y + vec2.y);
        }

        Vector2 operator - (const Vector2 &vec2) const {
            return Vector2(this->x + vec2.x, this->y + vec2.y);
        }

        Vector2 operator * (const float scalar) const {
            return Vector2(this->x * scalar, this->y * scalar);
        }

        void operator += (const Vector2& vec2) {
            this->x += vec2.x;
            this->y += vec2.y;
        }

        void operator -= (const Vector2& vec2) {
            this->x -= vec2.x;
            this->y -= vec2.y;
        }

        void operator *= (const Vector2& vec2) {
            this->x *= vec2.x;
            this->y *= vec2.y;
        }

        bool operator == (const Vector2& vec2) const
        {
            return this->x == vec2.x && this->y == vec2.y;
        }

        bool operator != (const Vector2& vec2) const
        {
            return this->x != vec2.x || this->y != vec2.y;
        }

        ///By default, shows the maximum amount of digits for each float number of this vector
        [[nodiscard]] std::string ToString(const int precisionNumber = 7) const {
            std::stringstream ss;
            ss << std::fixed << std::setprecision(precisionNumber) << "(" << this->x << ", " << this->y << ")";;
            return ss.str();
        }
    };
    const Vector2 Vector2::zero = Vector2(0, 0);

    struct Vector3 {
        float x;
        float y;
        float z;
        float magnitude;
        static const Vector3 zero;

        explicit Vector3(const float xValue = 0, const float yValue = 0, const float zValue = 0) : x(xValue), y(yValue), z(zValue) {
            this->magnitude = std::sqrt(x * x + y * y + z * z);
        }

        static float Distance(const Vector3 &vec1, const Vector3 &vec2) {
            return static_cast<float>(std::sqrt
                (std::pow(vec2.x - vec1.x, 2) +
                    std::pow(vec2.y - vec1.y, 2) +
                    std::pow(vec2.z - vec1.z, 2)));
        }

        static float Dot(const Vector3 &vec1, const Vector3 &vec2) {
            return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
        }

        static Vector3 Cross(const Vector3 &vec1, const Vector3 &vec2) {
            return Vector3(vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x);
        }

        static float Angle(const Vector3 &vec1, const Vector3 &vec2) {
            if (vec1.magnitude == 0.0f || vec2.magnitude == 0.0f) {
                std::cout << "Trying to find angle between two Vector3, when one of them is Vector3.zero" << std::endl;
                return 0.0f;
            }
            return std::acos(Dot(vec1, vec2) / (vec1.magnitude * vec2.magnitude));
        }

        Vector3& operator = (const Vector3 &vec3) {
            // Check for self-assignment
            if (this != &vec3) {
                this->x = vec3.x;
                this->y = vec3.y;
                this->z = vec3.z;
            }
            return *this; // Return a reference to the current object
        }

        Vector3 operator + (const Vector3 &vec3) const {
            return Vector3(this->x + vec3.x, this->y + vec3.y, this->z + vec3.z);
        }

        Vector3 operator - (const Vector3 &vec3) const {
            return Vector3(this->x + vec3.x, this->y + vec3.y, this->z + vec3.z);
        }

        Vector3 operator * (const float scalar) const {
            return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
        }

        void operator += (const Vector3 &vec3) {
            this->x += vec3.x;
            this->y += vec3.y;
            this->z += vec3.z;
        }

        void operator -= (const Vector3 &vec3) {
            this->x -= vec3.x;
            this->y -= vec3.y;
            this->z -= vec3.z;
        }

        void operator *= (const Vector3 &vec3) {
            this->x *= vec3.x;
            this->y *= vec3.y;
            this->z *= vec3.z;
        }

        bool operator == (const Vector3 &vec3) const {
            return this->x == vec3.x && this->y == vec3.y && this->z == vec3.z;
        }

        bool operator != (const Vector3 &vec3) const {
            return this->x != vec3.x || this->y != vec3.y || this->z != vec3.z;
        }

        ///By default, shows the maximum amount of digits for each float number of this vector
        [[nodiscard]] std::string ToString(const int precisionNumber) const {
            std::stringstream ss;
            ss << std::fixed << std::setprecision(precisionNumber) << "(" << this->x << ", " << this->y << ", " << this->z << ")";;
            return ss.str();
        }
    };
    const Vector3 Vector3::zero = Vector3(0, 0, 0);

    struct Vector4 {
        float x;
        float y;
        float z;
        float w;
        float magnitude;
        static const Vector4 zero;

        explicit Vector4(const float xValue = 0, const float yValue = 0, const float zValue = 0, const float wValue = 0) : x(xValue), y(yValue), z(zValue), w(wValue) {
            this->magnitude = std::sqrt(x * x + y * y + z * z + w * w);
        }

        static float Distance(const Vector4 &vec1, const Vector4 &vec2) {
            return static_cast<float>(std::sqrt
                (   std::pow(vec2.x - vec1.x, 2) +
                    std::pow(vec2.y - vec1.y, 2) +
                    std::pow(vec2.z - vec1.z, 2) +
                    std::pow(vec2.w - vec1.w, 2)));
        }

        static float Dot(const Vector4 &vec1, const Vector4 &vec2) {
            return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
        }

        //TODO:
        static Vector4 Cross(const Vector4 &vec1, const Vector4 &vec2) {
            return Vector4(vec1.y * vec2.z - vec1.z * vec2.y, 
            vec1.z * vec2.x - vec1.x * vec2.z, 
            vec1.x * vec2.y - vec1.y * vec2.x);
        }

        static float Angle(const Vector4 &vec1, const Vector4 &vec2) {
            if (vec1.magnitude == 0.0f || vec2.magnitude == 0.0f) {
                std::cout << "Trying to find angle between two Vector4, when one of them is Vector4.zero" << std::endl;
                return 0.0f;
            }
            return std::acos(Dot(vec1, vec2) / (vec1.magnitude * vec2.magnitude));
        }

        Vector4& operator = (const Vector4 &vec4) {
            // Check for self-assignment
            if (this != &vec4) {
                this->x = vec4.x;
                this->y = vec4.y;
                this->z = vec4.z;
                this->w = vec4.w;
            }
            return *this; // Return a reference to the current object
        }

        Vector4 operator + (const Vector4 &vec4) const {
            return Vector4(
                this->x + vec4.x, 
                this->y + vec4.y, 
                this->z + vec4.z, 
                this->w + vec4.w);
        }

        Vector4 operator - (const Vector4 &vec4) const {
            return Vector4(
                this->x + vec4.x, 
                this->y + vec4.y, 
                this->z + vec4.z,
                this->w + vec4.w);
        }

        Vector4 operator * (const float scalar) const {
            return Vector4(
                this->x * scalar, 
                this->y * scalar, 
                this->z * scalar, 
                this->w * scalar);
        }

        void operator += (const Vector4 &vec4) {
            this->x += vec4.x;
            this->y += vec4.y;
            this->z += vec4.z;
            this->w += vec4.w;
        }

        void operator -= (const Vector4 &vec4) {
            this->x -= vec4.x;
            this->y -= vec4.y;
            this->z -= vec4.z;
            this->w -= vec4.z;
        }

        void operator *= (const Vector4 &vec4) {
            this->x *= vec4.x;
            this->y *= vec4.y;
            this->z *= vec4.z;
            this->w *= vec4.w;
        }

        bool operator == (const Vector4 &vec4) const {
            return  this->x == vec4.x && 
                    this->y == vec4.y && 
                    this->z == vec4.z &&
                    this->w == vec4.w;
        }

        bool operator != (const Vector4 &vec4) const {
            return this->x != vec4.x 
                || this->y != vec4.y 
                || this->z != vec4.z 
                || this->w != vec4.w;
        }

        ///By default, shows the maximum amount of digits for each float number of this vector
        [[nodiscard]] std::string ToString(const int precisionNumber) const {
            std::stringstream ss;
            ss << std::fixed << std::setprecision(precisionNumber) 
            << "(" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << ")";
            return ss.str();
        }
    };
    const Vector4 Vector4::zero = Vector4(0, 0, 0, 0);
}
#endif //VECTOR_H
