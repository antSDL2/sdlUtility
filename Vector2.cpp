//Vector2.cpp
#include "Vector2.h"
#include <math.h>

namespace AtUtility {
    void Vector2::operator=(Vector2 Vector) {
        x = Vector.X();
        y = Vector.Y();
    }

    void Vector2::operator+=(Vector2 Vector) {
        x += Vector.X();
        y += Vector.Y();
    }

    void Vector2::operator-=(Vector2 Vector) {
        x -= Vector.X();
        y -= Vector.Y();
    }

    bool Vector2::operator==(Vector2 Vector) {
        return (x == Vector.X())&&(y == Vector.Y());
    }

    bool Vector2::operator!(void) {
        return !(x && y);
    }

    bool Vector2::operator!=(Vector2 Vector) {
        return !(x == Vector.X() && y == Vector.Y());
    }

    float Vector2::Angle() {
        return atan2(y, x);
    }

    float Vector2::Length() {
        return sqrt(pow(x, 2)+pow(y, 2));
    }

    float Vector2::Length2() {
        return pow(x, 2)+pow(y, 2);
    }

    Vector2::Vector2(float X, float Y) {
        x = X;
        y = Y;
    }

    float Vector2::X() {
        return x;
    }

    float Vector2::Y() {
        return y;
    }

    Vector2::~Vector2() {
        x = y = 0;
    }
}
