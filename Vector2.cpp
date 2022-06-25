//Vector2.cpp
#include "Vector2.h"
#include <math.h>

namespace sdlUtility {
    /// operator= implementation.
    /** Assigns the x, y values to the specified Vector2. */
    void Vector2::operator=(Vector2 Vector) {
        x = Vector.X();
        y = Vector.Y();
    }

    /// operator+= implementation.
    /** Increments the x, y values by the specified Vector2. */
    void Vector2::operator+=(Vector2 Vector) {
        x += Vector.X();
        y += Vector.Y();
    }

    /// operator-= implementation.
    /** Decrements the x, y values by the specified Vector2. */
    void Vector2::operator-=(Vector2 Vector) {
        x -= Vector.X();
        y -= Vector.Y();
    }

    /// operator== implementation.
    /** Compares the x, y values to the specified Vector2. */
    bool Vector2::operator==(Vector2 Vector) {
        return (x == Vector.X())&&(y == Vector.Y());
    }

    /// operator! implementation.
    /** Returns true if (x, y) = (0, 0). */
    bool Vector2::operator!(void) {
        return !(x && y);
    }

    /// operator!= implementation.
    /** Compares the x, y values to the specified Vector2. */
    bool Vector2::operator!=(Vector2 Vector) {
        return !(x == Vector.X() && y == Vector.Y());
    }

    /// Returns the angle of the vector.
    /** Calculated in relation to the origin point (0, 0). */
    float Vector2::Angle() {
        return atan2(y, x);
    }

    /// Returns the magnitude of the vector.
    float Vector2::Length() {
        return sqrt(pow(x, 2)+pow(y, 2));
    }

    /// Returns the squared magnitude of the vector.
    float Vector2::Length2() {
        return pow(x, 2)+pow(y, 2);
    }

    /// Basic constructor.
    /** @param X, Y Used to initialise the x, y of the vector. */
    Vector2::Vector2(float X, float Y) {
        x = X;
        y = Y;
    }

    /// Returns the X component of the vector.
    float Vector2::X() {
        return x;
    }

    /// Returns the Y component of the vector.
    float Vector2::Y() {
        return y;
    }

    /// Basic destructor.
    Vector2::~Vector2() {
        x = y = 0;
    }
}
