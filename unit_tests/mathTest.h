//
// Created by Giorgos Tsolakidis on 4/3/24.
//

#ifndef MATHG_MATHTEST_H
#define MATHG_MATHTEST_H


#define CATCH_CONFIG_MAIN
#include "catch.cpp"
#include "mathg.h"

TEST_CASE("Mathg Functions", "[mathg]") {
SECTION("Degree to Radian Conversion") {
REQUIRE(mathg::DegreeToRad(90) == Approx(1.5708).epsilon(0.01));
REQUIRE(mathg::DegreeToRad(180) == Approx(3.14159).epsilon(0.01));
}

SECTION("Radian to Degree Conversion") {
REQUIRE(mathg::RadToDegree(1.5708) == Approx(90).epsilon(0.01));
REQUIRE(mathg::RadToDegree(3.14159) == Approx(180).epsilon(0.01));
}

SECTION("Cosine Function") {
REQUIRE(mathg::Cos(0) == Approx(1).epsilon(0.01));
REQUIRE(mathg::Cos(mathg::PI) == Approx(-1).epsilon(0.01));
}

SECTION("Sine Function") {
REQUIRE(mathg::Sin(0) == Approx(0).epsilon(0.01));
REQUIRE(mathg::Sin(mathg::PI / 2) == Approx(1).epsilon(0.01));
}
}

TEST_CASE("Vector2 Operations", "[Vector2]") {
mathg::Vector2 vec1(3, 4);
mathg::Vector2 vec2(1, 2);

SECTION("Vector Addition") {
mathg::Vector2 result = vec1 + vec2;
REQUIRE(result.x == 4);
REQUIRE(result.y == 6);
}

SECTION("Vector Subtraction") {
mathg::Vector2 result = vec1 - vec2;
REQUIRE(result.x == 2);
REQUIRE(result.y == 2);
}

SECTION("Vector Scalar Multiplication") {
mathg::Vector2 result = vec1 * 2;
REQUIRE(result.x == 6);
REQUIRE(result.y == 8);
}

// Add more test cases for other Vector2 operations as needed
}


#endif //MATHG_MATHTEST_H
