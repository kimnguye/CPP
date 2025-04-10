#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    //on decale de 8 bits vers la gauche
    this->value = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    //on multiplie la valeur par 2^8
    //on ne peut pas faire un decalage de bits sur un float
    this->value = roundf(value * (1 << fractional_bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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
    std::cout << "Copy assignment operator called" << std::endl;
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

