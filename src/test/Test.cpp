
#include <iostream>
#include <gtest/gtest.h>
#include "../../include/MathUtilities.h"
#include "../../include/Vector2.h"

const double EPS = 1e-3;

TEST(MathUtilities, ToNearestInt) {
    EXPECT_EQ(1, math::ToNearestInt(1.2));
    EXPECT_EQ(2, math::ToNearestInt(1.8));
    EXPECT_EQ(21, math::ToNearestInt(20.6));
    EXPECT_EQ(101, math::ToNearestInt(100.51));
}

TEST(MathUtilities, Max) {
    EXPECT_EQ(10, math::Max<int>(1, 10));
    EXPECT_EQ(100, math::Max<int>(100, 10, -1));
    EXPECT_EQ(80, math::Max<int>(10, 14, 80, -20));
    EXPECT_NEAR(2.5, math::Max<float>(1.4, 2.5), EPS);
    EXPECT_NEAR(8.5, math::Max<float>(8.5, -1.43, -1.150), EPS);
    EXPECT_NEAR(14242.12, math::Max<float>(14242.12, -2322.123, 13.2, 5.2), EPS);
}

TEST(MathUtilities, Min) {
    EXPECT_EQ(1, math::Min<int>(1, 10));
    EXPECT_EQ(-1, math::Min<int>(100, 10, -1));
    EXPECT_EQ(-20, math::Min<int>(10, 14, 80, -20));
    EXPECT_NEAR(1.4, math::Min<float>(1.4, 2.5), EPS);
    EXPECT_NEAR(-1.43, math::Min<float>(8.5, -1.43, -1.150), EPS);
    EXPECT_NEAR(-2322.123, math::Min<float>(14242.12, -2322.123, 13.2, 5.2), EPS);
}

TEST(MathUtilities, IsPowerOf2) {
    EXPECT_EQ(true, math::IsPowerOf2(4));
    EXPECT_EQ(false, math::IsPowerOf2(13));
    EXPECT_EQ(true, math::IsPowerOf2(32));
    EXPECT_EQ(true, math::IsPowerOf2(0));
    EXPECT_EQ(false, math::IsPowerOf2(232));
    EXPECT_EQ(false, math::IsPowerOf2(-8));
}

TEST(MathUtilities, ToDegrees) {
    EXPECT_NEAR(60, math::ToDegrees(PI / 3.0), EPS);
    EXPECT_NEAR(360, math::ToDegrees(2 * PI), EPS);
    EXPECT_NEAR(143.239, math::ToDegrees(2.5), EPS);
}


TEST(MathUtilities, ToRadians) {
    EXPECT_NEAR(1, math::ToRadians(57.3), EPS);
    EXPECT_NEAR(2 * PI, math::ToRadians(360), EPS);
}

TEST(MathUtilities, Lerp) {
    EXPECT_NEAR(1.5, math::Lerp<float>( 1, 2, 0.5f ), EPS);
    EXPECT_NEAR(5.5, math::Lerp<float>( 1, 10, 0.5f ), EPS);
    EXPECT_NEAR(2, math::Lerp<int>( 1, 10, 0.2f ), EPS);
}

TEST(MathUtilities, AngularDistance) {
    EXPECT_NEAR(45, math::CalcAngularDistanceInDegrees(45, 90), EPS);
    EXPECT_NEAR(25, math::CalcAngularDistanceInDegrees(45, 20), EPS);
    EXPECT_NEAR(PI, math::CalcAngularDistanceInRadians(2 * PI, PI), EPS);
}

TEST(MathUtilities, Clamp) {
    EXPECT_EQ(20, math::Clamp<int>(15, 20, 40));
    EXPECT_EQ(20, math::Clamp<int>(15, 40, 20)); // inverted range
    EXPECT_EQ(40, math::Clamp<int>(45, 20, 40));
    EXPECT_NEAR(12, math::Clamp<float>(12, 10.5, 22.5), EPS);
    EXPECT_NEAR(20.433, math::Clamp<float>(20.433, 10.5, 22.5), EPS);
}

TEST(Vector2, Constructors) {
    // testing (real x, real y) constructor
    math::Vector2 v1(1, 2);
    EXPECT_NEAR(1, v1.GetX(), EPS);
    EXPECT_NEAR(2, v1.GetY(), EPS);

    // testing copy constructor
    math::Vector2 v2(v1);
    EXPECT_NEAR(1, v2.GetX(), EPS);
    EXPECT_NEAR(2, v2.GetY(), EPS);
}

TEST(Vector2, SettersGetters) {
    math::Vector2 v1(8.13, 15.2);
    EXPECT_NEAR(8.13, v1.GetX(), EPS);
    EXPECT_NEAR(15.2, v1.GetY(), EPS);

    v1.SetX(32.12); v1.SetY(14.32);
    EXPECT_NEAR(32.12, v1.GetX(), EPS);
    EXPECT_NEAR(14.32, v1.GetY(), EPS);
}

TEST(Vector2, CalcLength) {
    math::Vector2 v1(2, 2);
    EXPECT_NEAR(2.828, v1.CalcLength(), EPS);
    EXPECT_NEAR(8, v1.CalcLengthSquared(), EPS);
}

TEST(Vector2, DotProduct) {
    math::Vector2 v1(5, 2);
    math::Vector2 v2(8, 2);
    EXPECT_NEAR(44, v1.DotProduct(v2), EPS);
    EXPECT_NEAR(44, v2.DotProduct(v1), EPS);
}

TEST(Vector2, CalcYawRadians) {
    math::Vector2 v1(-10, 10);
    EXPECT_NEAR(2.356, v1.CalcYawRadians(), EPS);

    math::Vector2 v2(2, 2);
    EXPECT_NEAR(PI / 4, v2.CalcYawRadians(), EPS);

    math::Vector2 v3(0, 1);
    EXPECT_NEAR(PI / 2, v3.CalcYawRadians(), EPS);
}

TEST(Vector2, CalcYawDegrees) {
    math::Vector2 v1(-10, 10);
    EXPECT_NEAR(135, v1.CalcYawDegrees(), EPS);

    math::Vector2 v2(2, 2);
    EXPECT_NEAR(45, v2.CalcYawDegrees(), EPS);

    math::Vector2 v3(0, 1);
    EXPECT_NEAR(90, v3.CalcYawDegrees(), EPS);
}

TEST(Vector2, SetLengthAndYawRadians) {
    math::Vector2 v1;

    v1.SetLengthAndYawRadians(1, math::ToRadians(45));
    EXPECT_NEAR(0.707, v1.GetX(), EPS);
    EXPECT_NEAR(0.707, v1.GetY(), EPS);

    v1.SetLengthAndYawRadians(1, math::ToRadians(135));
    EXPECT_NEAR(-0.707, v1.GetX(), EPS);
    EXPECT_NEAR(0.707, v1.GetY(), EPS);

    v1.SetLengthAndYawRadians(1, math::ToRadians(180));
    EXPECT_NEAR(-1, v1.GetX(), EPS);
    EXPECT_NEAR(0, v1.GetY(), EPS);

    v1.SetLengthAndYawRadians(1, math::ToRadians(225));
    EXPECT_NEAR(-0.707, v1.GetX(), EPS);
    EXPECT_NEAR(-0.707, v1.GetY(), EPS);

    v1.SetLengthAndYawRadians(1, math::ToRadians(270));
    EXPECT_NEAR(0, v1.GetX(), EPS);
    EXPECT_NEAR(-1, v1.GetY(), EPS);

    v1.SetLengthAndYawRadians(1, math::ToRadians(0));
    EXPECT_NEAR(1, v1.GetX(), EPS);
    EXPECT_NEAR(0, v1.GetY(), EPS);
}

TEST(Vector2, AssigmentOperator) {
    math::Vector2 v1(1, 1);
    math::Vector2 v2(2, 3);
    v1 = v2;
    EXPECT_NEAR(2, v1.GetX(), EPS);
    EXPECT_NEAR(3, v1.GetY(), EPS);
}

TEST(Vector2, EqualEqualOperator) {
    math::Vector2 v1(1.65, 1.65);
    math::Vector2 v2(1.65, 1.65);
    EXPECT_EQ(true, v1 == v2);
}

TEST(Vector2, DifferentOperator) {
    math::Vector2 v1(1.24, 1.24);
    math::Vector2 v2(1.24, 1.24);
    EXPECT_EQ(false, v1 != v2);
}

TEST(Vector2, Rotate90Degrees) {
    math::Vector2 v1;
    v1.SetLengthAndYawRadians(1, math::ToRadians(0));
    EXPECT_NEAR(1, v1.GetX(), EPS);
    EXPECT_NEAR(0, v1.GetY(), EPS);
    v1.Rotate90Degrees();
    EXPECT_NEAR(0, v1.GetX(), EPS);
    EXPECT_NEAR(1, v1.GetY(), EPS);
    v1.RotateMinus90Degrees();
    EXPECT_NEAR(1, v1.GetX(), EPS);
    EXPECT_NEAR(0, v1.GetY(), EPS);
}

TEST(Vector2, Normalize) {
    math::Vector2 v1(10.5, 10.5);
    v1.Normalize();
    EXPECT_NEAR(0.707, v1.GetX(), EPS);
    EXPECT_NEAR(0.707, v1.GetY(), EPS);
}

TEST(Vector2, Operators) {
    math::Vector2 v1(10.5, 5.5);
    math::Vector2 v2(10.5, 1);
    math::Vector2 v3;

    v3 = v1 + v2;
    EXPECT_NEAR(21, v3.GetX(), EPS);
    EXPECT_NEAR(6.5, v3.GetY(), EPS);

    v3 = v2 - v1;
    EXPECT_NEAR(0, v3.GetX(), EPS);
    EXPECT_NEAR(-4.5, v3.GetY(), EPS);

    v3 = 2 * v1;
    EXPECT_NEAR(21, v3.GetX(), EPS);
    EXPECT_NEAR(11, v3.GetY(), EPS);

    v3 = v1 * 2;
    EXPECT_NEAR(21, v3.GetX(), EPS);
    EXPECT_NEAR(11, v3.GetY(), EPS);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
