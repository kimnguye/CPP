#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;
    public:
        Point(void);
        Point(const Fixed &x, const Fixed &y);
        Point(const Point &other);
        ~Point(void);
        Point &operator=(const Point &other);
        Fixed getX(void) const;
        Fixed getY(void) const;
        void setX(const Fixed &x);
        void setY(const Fixed &y);
};

#endif
