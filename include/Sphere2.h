#ifndef SPHERE2_H
#define SPHERE2_H

#include "Vector2.h"

namespace math 
{
    class Sphere2
    {
        public:
            // ctor & dtor
            Sphere2();
            Sphere2(const Vector2& center, const real radius);
            ~Sphere2();

            // functions
            bool IsPointInside( const Vector2& point ) const;
            bool IsOverlappingWithDisc( const Sphere2& rhs ) const;
            real CalcDistanceFromDisc( const Sphere2& rhs ) const;
            real CalcDistanceFromPoint( const Vector2& point ) const;

            Vector2 GetCenter() const;
            real GetRadius() const;
            real GetRadiusSqr() const;

        private:
            Vector2 m_center;
            real m_radius;
    };
}

#endif
