#ifndef MATHG_H
#define MATHG_H

///@file
///
namespace  mathg {
    //TODO: Trigonometry functions
    //cos, sin, tan, cotan, atan, atan2...

    constexpr float PI = 3.14159265358979323846f;

    inline float DegreeToRad(const float angle) {
        return angle * PI / 180;
    }

    inline float RadToDegree(const float rad) {
        return rad * 180 / PI;
    }

    inline float Cos(const float angleInRadians) {

    }
    //TODO: **Vector Operations**:
    //Dot product, cross product
    //Normalization, magnitude
    //Component-wise operations,
    struct Vector2 {
        float x;
        float y;

        explicit Vector2(float xValue = 0, float yValue = 0) : x(xValue), y(yValue) {};

        Vector2& operator = (const Vector2& vec2) {
            // Check for self-assignment
            if (this != &vec2) {
                this->x = vec2.x;
                this->y = vec2.y;
            }
            return *this; // Return a reference to the current object
        }

        Vector2 operator + (const Vector2& vec2) const {
            Vector2 vector2 = vec2;
            vector2.x = this->x + vec2.x;
            vector2.y = this->y + vec2.y;
            return  vector2;
        }

        Vector2 operator * (const float scalar) const {
            Vector2 vector2 = Vector2(x, y);
            vector2.x *= scalar;
            vector2.y *= scalar;
            return  vector2;
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

        bool operator == (const Vector2& vec1, const Vector2& vec2) const
        {
            return vec1.x == vec2.x && vec1.y == vec2.y;
        }

        bool operator != (const Vector2& vec1, const Vector2& vec2) const
        {
            return vec1.x != vec2.x || vec1.y != vec2.y;
        }
    };
};

#endif //MATHG_H
