#include <cmath>
#include <stdexcept>
#include <Vector2.h>
#include <MathUtilities.h>

namespace math 
{

    Vector2::Vector2() :
        x(0), y(0) 
    {

    }
    
    Vector2::Vector2(const real _x, const real _y) : 
        x(_x), y(_y) 
    {
    
    }

    Vector2::Vector2(const Vector2 &rhs) 
    {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    void Vector2::Normalize() 
    {
        real length = this->CalcLength();
        if(length == 0) {
            throw std::overflow_error("Divide by zero exception");
        }
        this->x /= length;
        this->y /= length;
    }

    void Vector2::SetXY(const real _x, const real _y) 
    {
        this->x = _x;
        this->y = _y;
    }

    void Vector2::SetX(real _x) 
    {
        this->x = _x;
    }

    void Vector2::SetY(real _y) 
    {
        this->y = _y;
    }

    void Vector2::SetLengthAndYawRadians(
        const real radius, 
        const real angleInRadians) 
    {
        this->x = radius * cos(angleInRadians);
        this->y = radius * sin(angleInRadians);
    }

    void Vector2::SetUnitLengthAndYawRadians(const real angleInRadians) 
    {
        SetLengthAndYawRadians(1, angleInRadians);
    }

    void Vector2::SetUnitLengthAndYawDegrees(const real angleInDegrees) 
    {
        SetLengthAndYawRadians(1, ToRadians(angleInDegrees));
    }

    void Vector2::SetLengthAndYawDegrees(
        const real radius, 
        const real angleInDegrees) 
    {
        SetLengthAndYawRadians(radius, ToRadians(angleInDegrees));
    }

    void Vector2::SetLength(const real radius)  
    {
        real angle = this->CalcYawRadians();
        SetLengthAndYawRadians(radius, angle);
    }

    void Vector2::ScaleUniform(const real length) 
    {
        this->x *= length;
        this->y *= length;
    }

    void Vector2::ScaleX(const real length) 
    {
        this->x *= length;
    }

    void Vector2::ScaleY(const real length) 
    {
        this->y *= length;
    }

    Vector2& Vector2::RotateRadians(const real angleInRadians) 
    {
        real cosangle = cos(angleInRadians);
        real sinangle = sin(angleInRadians);
        real n_x = this->x * cosangle - this->y * sinangle;
        real n_y = this->y * cosangle + this->x * sinangle;
        this->x = n_x;
        this->y = n_y;
        return *this;
    }

    Vector2& Vector2::RotateDegrees(const real angleInDegrees) 
    {
        return RotateRadians(ToRadians(angleInDegrees));
    }

    Vector2& Vector2::Rotate90Degrees() 
    {
        return RotateRadians(ToRadians(90));
    }

    Vector2& Vector2::RotateMinus90Degrees() 
    {
        return RotateRadians(ToRadians(-90));
    }

    Vector2& Vector2::Reverse() 
    {
        // swap
        real tmp = this->x;
        this->x = this->y;
        this->y = tmp;
        return *this;
    }

    void Vector2::GetXY( real& _x, real& _y ) 
    {
        _x = this->x;
        _y = this->y;
    }

    real Vector2::GetX() const 
    {
        return this->x;
    }

    real Vector2::GetY() const 
    {
        return this->y;
    }

    real Vector2::CalcLength() const 
    {
        return sqrt(this->CalcLengthSquared());
    }

    real Vector2::CalcLengthSquared() const 
    {
        return this->x * this->x + this->y * this->y;
    }

    real Vector2::DotProduct(const Vector2 &rhs) const 
    {
        return this->x * rhs.x + this->y * rhs.y;
    }

    real Vector2::CalcYawRadians() const 
    {
        return atan2(this->y, this->x);
    }

    real Vector2::CalcYawDegrees() const 
    {
        return ToDegrees(this->CalcYawRadians());
    }

    Vector2 & Vector2::operator=(const Vector2 &rhs) 
    {
        if ( this == &rhs ) {
            return *this;
        }
        this->x = rhs.x;
        this->y = rhs.y;
        return *this;
    }

    Vector2 & Vector2::operator+=(const Vector2 &rhs) 
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    Vector2 & Vector2::operator-=(const Vector2 &rhs) 
    {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    Vector2 & Vector2::operator*=(const real uniformScale) 
    {
        this->x *= uniformScale;
        this->y *= uniformScale;
        return *this;
    }

    Vector2 & Vector2::operator/=(const real inverseScale)  
    {
        if(inverseScale == 0) {
            throw std::overflow_error("Divide by zero exception");
        }
        this->x /= inverseScale;
        this->y /= inverseScale;
        return *this;
    }

    Vector2 Vector2::operator+(const Vector2 &rhs) 
    {
        return Vector2(this->x + rhs.x, this->y + rhs.y);
    }

    Vector2 Vector2::operator+( const float displacement ) 
    {
        Vector2 res;
        res.x = x + displacement;
        res.y = y + displacement;
        return res;
    }

    Vector2 Vector2::operator-(const Vector2 &rhs) 
    {
        return Vector2(this->x - rhs.x, this->y - rhs.y);
    }

    Vector2 Vector2::operator-( const float displacement ) 
    {
        Vector2 res;
        res.x = x - displacement;
        res.y = y - displacement;
        return res;
    }

    Vector2 Vector2::operator*(const real uniformScale) 
    {
        return Vector2(this->x * uniformScale, this->y * uniformScale);
    }

    Vector2 Vector2::operator/(const real inverseScale) 
    {
        if(inverseScale == 0) {
            throw std::overflow_error("Divide by zero exception");
        }
        return Vector2(this->x / inverseScale, this->y / inverseScale);
    }
    
    Vector2 Vector2::operator-() 
    {
        return Vector2(-this->x, -this->y);
    }

    bool Vector2::operator==(const Vector2 &rhs) 
    {
        return IsNear(this->x, rhs.x) && IsNear(this->y, rhs.y);
    }

    bool Vector2::operator!=(const Vector2 &rhs) 
    {
        return !(*this == rhs);
    }

    Vector2 operator*(const real scale, const Vector2& rhs) 
    {
        return Vector2(scale * rhs.x, scale * rhs.y);
    }
}
