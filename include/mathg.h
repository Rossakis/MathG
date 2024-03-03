#ifndef MATHG_H
#define MATHG_H

#include <cmath>

namespace  mathg {
    constexpr float PI = 3.14159265358979323846f;

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

    //TODO: **Vector Operations**:
    //Dot product, cross product
    //Normalization, magnitude
    //Component-wise operations,
    struct Vector2 {
        float x;
        float y;
        float magnitude;
        //TODO: magnitude
        //distance,
        //dot product func

        explicit Vector2(float xValue = 0, float yValue = 0) : x(xValue), y(yValue) {
            this->magnitude = std::sqrt(x * x + y * y);
        };

        inline float Distance(const Vector2 &vec1, const Vector2 &vec2) const {
            return std::sqrt(std::pow(vec2.x-vec1.x, 2) + std::pow(vec2.y-vec1.y, 2));
        }

        inline float Dot(const Vector2 &vec1, const Vector2 &vec2) const {
            return vec1.x * vec2.x + vec1.y * vec2.y;
        }

        inline float Angle(const Vector2 &vec1, const Vector2 &vec2) const {
            if(vec1.magnitude == 0.0f || vec2.magnitude == 0.0f) {
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

        inline Vector2 operator + (const Vector2& vec2) const {
            Vector2 vector2 = vec2;
            vector2.x = this->x + vec2.x;
            vector2.y = this->y + vec2.y;
            return  vector2;
        }

        inline Vector2 operator - (const Vector2& vec2) const {
            Vector2 vector2 = vec2;
            vector2.x = this->x - vec2.x;
            vector2.y = this->y - vec2.y;
            return  vector2;
        }

        inline Vector2 operator * (const float scalar) const {
            Vector2 vector2 = Vector2(x, y);
            vector2.x *= scalar;
            vector2.y *= scalar;
            return  vector2;
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
    };
};

#endif //MATHG_H
