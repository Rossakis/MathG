#ifndef MATHG_H
#define MATHG_H

//Math headers
#include <cmath>
#include <iostream>

//Debug headers
#include <sstream>
#include <string>
#include <iomanip>

///TODO: Matrix struct
/// Vector zero
namespace  mathg {
    constexpr float PI = 3.14159265358979323846f;

    //Helper functions
    inline float DegreeToRad(const float angle) {
        return angle * PI / 180;
    }

    inline float RadToDegree(const float rad) {
        return rad * 180 / PI;
    }

    inline float Cos(const float angleInRadians) {
        return std::cosf(angleInRadians);
    }

    inline float Sin(const float angleInRadians) {
        return std::sinf(angleInRadians);
    }

    inline float Ταn(const float angleInRadians) {
        return std::tan(angleInRadians);
    }

    inline float Cotan(const float angleInRadians) {
        if (std::sinf(angleInRadians) == 0)
            std::cerr << "Cannot determine Cotan. Reason: Sine = 0" << std::endl;

        return std::cosf(angleInRadians)/std::sinf(angleInRadians);
    }

    inline float Arccos(const float angleInRadians) {
        return std::acosf(angleInRadians);
    }

    struct Vector2 {
        float x;
        float y;
        float magnitude;
        static const Vector2 zero;

        explicit Vector2(float xValue = 0, float yValue = 0) : x(xValue), y(yValue) {
            this->magnitude = std::sqrt(x * x + y * y);
        }

        static inline float Distance(const Vector2 &vec1, const Vector2 &vec2) {
            return std::sqrt(std::pow(vec2.x-vec1.x, 2) + std::pow(vec2.y-vec1.y, 2));
        }

        static inline float Dot(const Vector2 &vec1, const Vector2 &vec2) {
            return vec1.x * vec2.x + vec1.y * vec2.y;
        }

        static inline float Angle(const Vector2 &vec1, const Vector2 &vec2) {
            if(vec1.magnitude == 0.0f || vec2.magnitude == 0.0f) {
                std::cout << "Trying to find angle between two Vector2, when one of them is Vector2.zero" << std::endl;
                return 0.0f;
            }
            return std::acosf(Dot(vec1, vec2) / (vec1.magnitude * vec2.magnitude));
        }

        inline Vector2& operator = (const Vector2& vec2) {
            // Check for self-assignment
            if (this != &vec2) {
                this->x = vec2.x;
                this->y = vec2.y;
            }
            return *this; // Return a reference to the current object
        }

        inline Vector2 operator + (const Vector2 &vec3) const {
            return Vector2(this->x + vec3.x, this->y + vec3.y);
        }

        inline Vector2 operator - (const Vector2 &vec3) const {
            return Vector2(this->x + vec3.x, this->y + vec3.y);
        }

        inline Vector2 operator * (int scalar) const {
            return Vector2(this->x * scalar, this->y * scalar);
        }

        inline void operator += (const Vector2& vec2) {
            this->x += vec2.x;
            this->y += vec2.y;
        }

        inline void operator -= (const Vector2& vec2) {
            this->x -= vec2.x;
            this->y -= vec2.y;
        }

        inline void operator *= (const Vector2& vec2) {
            this->x *= vec2.x;
            this->y *= vec2.y;
        }

        inline bool operator == (const Vector2& vec2) const
        {
            return this->x == vec2.x && this->y == vec2.y;
        }

        inline bool operator != (const Vector2& vec2) const
        {
            return this->x != vec2.x || this->y != vec2.y;
        }

        ///By default, shows the maximum amount of digits for each float number of this vector
        inline std::string ToString(int precisionNumber) const {
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

        explicit Vector3(float xValue = 0, float yValue = 0, float zValue = 0) : x(xValue), y(yValue), z(zValue) {
            this->magnitude = std::sqrt(x * x + y * y + z * z);
        }

        static inline float Distance(const Vector3 &vec1, const Vector3 &vec2) {
            return std::sqrt(std::pow(vec2.x - vec1.x, 2) + std::pow(vec2.y - vec1.y, 2) + std::pow(vec2.z - vec1.z, 2));
        }

        static inline float Dot(const Vector3 &vec1, const Vector3 &vec2) {
            return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
        }

        static inline Vector3 Cross(const Vector3 &vec1, const Vector3 &vec2) {
            return Vector3(vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x);
        }

        static inline float Angle(const Vector3 &vec1, const Vector3 &vec2) {
            if (vec1.magnitude == 0.0f || vec2.magnitude == 0.0f) {
                std::cout << "Trying to find angle between two Vector3, when one of them is Vector3.zero" << std::endl;
                return 0.0f;
            }
            return std::acosf(Dot(vec1, vec2) / (vec1.magnitude * vec2.magnitude));
        }

        inline Vector3& operator = (const Vector3 &vec3) {
            // Check for self-assignment
            if (this != &vec3) {
                this->x = vec3.x;
                this->y = vec3.y;
                this->z = vec3.z;
            }
            return *this; // Return a reference to the current object
        }

        inline Vector3 operator + (const Vector3 &vec3) const {
            return Vector3(this->x + vec3.x, this->y + vec3.y, this->z + vec3.z);
        }

        inline Vector3 operator - (const Vector3 &vec3) const {
            return Vector3(this->x + vec3.x, this->y + vec3.y, this->z + vec3.z);
        }

        inline Vector3 operator * (int scalar) const {
            return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
        }

        inline void operator += (const Vector3 &vec3) {
            this->x += vec3.x;
            this->y += vec3.y;
            this->z += vec3.z;
        }

        inline void operator -= (const Vector3 &vec3) {
            this->x -= vec3.x;
            this->y -= vec3.y;
            this->z -= vec3.z;
        }

        inline void operator *= (const Vector3 &vec3) {
            this->x *= vec3.x;
            this->y *= vec3.y;
            this->z *= vec3.z;
        }

        inline bool operator == (const Vector3 &vec3) const {
            return this->x == vec3.x && this->y == vec3.y && this->z == vec3.z;
        }

        inline bool operator != (const Vector3 &vec3) const {
            return this->x != vec3.x || this->y != vec3.y || this->z != vec3.z;
        }

        ///By default, shows the maximum amount of digits for each float number of this vector
        inline std::string ToString(int precisionNumber) const {
            std::stringstream ss;
            ss << std::fixed << std::setprecision(precisionNumber) << "(" << this->x << ", " << this->y << ", " << this->z << ")";;
            return ss.str();
        }
    };
    const Vector3 Vector3::zero = Vector3(0, 0, 0);
};

#endif //MATHG_H
