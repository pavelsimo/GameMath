#ifndef RAY2_H
#define RAY2_H

#include "Vector2.h"

namespace math 
{
    class Ray2
    {
        public:
            Ray2();
            Ray2(const Vector2& origin, const Vector2& end);
            Ray2(const Vector2& origin, const real radius);
            Ray2(const real originX, const real originY, 
                 const real endX, const real endY);
            ~Ray2();
            Vector2 GetPointAtParametric(real parametric) const;
            Vector2 GetOrigin() const;
            Vector2 GetEnd() const;
            
        private:
            Vector2 m_origin;
            Vector2 m_end;
    };
}

#endif
