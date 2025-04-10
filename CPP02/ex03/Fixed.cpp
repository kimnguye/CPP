#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::Fixed(const int value)
{
    this->value = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
    this->value = roundf(value * (1 << fractional_bits));
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		value = other.getRawBits();
	return *this;
}

float Fixed::toFloat(void) const
{
    return (float)value / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return value >> fractional_bits;
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
    output << fixed.toFloat();
    return output;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.toFloat() == 0)
    {
        std::cout << "Error: division by zero" << std::endl;
        return *this;
    }
    return Fixed (this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->toFloat() > other.toFloat();
}


bool Fixed::operator<(const Fixed &other) const
{
    return this->toFloat() < other.toFloat();
}


bool Fixed::operator>=(const Fixed &other) const
{
    return this->toFloat() >= other.toFloat();
}


bool Fixed::operator<=(const Fixed &other) const
{
    return this->toFloat() <= other.toFloat();
}


bool Fixed::operator==(const Fixed &other) const
{
    return this->toFloat() == other.toFloat();
}


bool Fixed::operator!=(const Fixed &other) const
{
    return this->toFloat() != other.toFloat();
}

Fixed &Fixed::operator++(void)
{
    this->value++;
    return *this;
}

Fixed &Fixed::operator--(void)
{
    this->value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->value--;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}


const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}
