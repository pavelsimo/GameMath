#include "../include/Ray2.h"

namespace math 
{
    Ray2::Ray2()
    {
        
    }

    Ray2::Ray2(const Vector2& origin, const Vector2& end)
    : m_origin(origin),
      m_end(end)
    {
        
    }

    Ray2::Ray2(const Vector2& origin, const real radius)
    : m_origin(origin),
      m_end(radius * origin)
    {
        
    }

    Ray2::Ray2(const real originX, const real originY, 
         const real endX, const real endY)
    : m_origin(Vector2(originX, originY)),
      m_end(Vector2(endX, endY))
    {
        
    }

    Ray2::~Ray2()
    {
        
    }
    
    Vector2 Ray2::GetPointAtParametric(real parametric) const
    {
        // p(t) = p_o + td
        // p_o = origin point
        // t = parameter, in normalized range [0,1]
        // d = delta vector
        Vector2 d(this->GetEnd() - this->GetOrigin());
        return this->GetOrigin() + (parametric * d);
    }

    Vector2 Ray2::GetOrigin() const
    {
        return m_origin;
    }
    
    Vector2 Ray2::GetEnd() const 
    {
        return m_end;
    }  
}
