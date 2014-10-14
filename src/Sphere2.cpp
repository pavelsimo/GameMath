#include "../include/Sphere2.h"

namespace math 
{   
    Sphere2::Sphere2() 
    : m_center(Vector2(0, 0)),
      m_radius(1.0f)
    {
        
    }

    Sphere2::Sphere2(const Vector2& center, const real radius)
    : m_center(center),
      m_radius(radius)
    {
        
    }
    
    Sphere2::~Sphere2()
    {
        
    }

    bool Sphere2::IsPointInside(const Vector2& point) const
    {
        Vector2 displacement(Vector2(point) - this->GetCenter());   
        return !(displacement.CalcLengthSquared() > m_radius * m_radius);
    }
    
    bool Sphere2::IsOverlappingWithDisc(const Sphere2& rhs) const
    {
        Vector2 displacement(rhs.GetCenter() - this->GetCenter());
        real lengthSqr = displacement.CalcLengthSquared();

        return !(lengthSqr > this->GetRadiusSqr()) 
            && !(lengthSqr > rhs.GetRadiusSqr());
     }

    real Sphere2::CalcDistanceFromDisc(const Sphere2& rhs) const
    {
        if(this->IsOverlappingWithDisc(rhs)) 
        {
            return 0;
        }

        Vector2 displacement(rhs.GetCenter() - this->GetCenter());
        real distance = displacement.CalcLength();

        return distance - this->GetRadius() - rhs.GetRadius();
    }

    real Sphere2::CalcDistanceFromPoint(const Vector2& point) const
    {
        if(this->IsPointInside(point)) 
        {
            return 0;
        }

        Vector2 displacement(Vector2(point) - this->GetCenter());
        real distance = displacement.CalcLength();
        
        return distance - this->GetRadius();
    }

    Vector2 Sphere2::GetCenter() const
    {
        return m_center;
    }

    real Sphere2::GetRadius() const
    {
        return m_radius;
    }

    real Sphere2::GetRadiusSqr() const 
    {
        return m_radius * m_radius;
    }
}
