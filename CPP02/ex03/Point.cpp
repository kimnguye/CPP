#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point(void) {}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
	return *this;
}

Fixed Point::getX(void) const
{
    return x;
}

Fixed Point::getY(void) const
{
    return y;
}

void Point::setX(const Fixed &x)
{
    this->x = x;
}

void Point::setY(const Fixed &y)
{
    this->y = y;
}
