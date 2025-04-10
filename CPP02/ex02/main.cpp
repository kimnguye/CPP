#include "Fixed.hpp"

int main()
{
    Fixed       a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    /*tests*/
    Fixed c(b);
    std::cout << std::endl;
    std::cout << "a=" << a << "   b=" << b << "   c=" << c << std::endl;
    std::cout << "max=" << Fixed::max(a, b) << std::endl;
    std::cout << "min=" << Fixed::min(a, b) << std::endl;
    if (b > a)
        std::cout << "b est plus grand que a" << std::endl;
    if (a < b)
        std::cout << "a est plus petit que b" << std::endl;
    if (c == b)
        std::cout << "c est egale a b" << std::endl;
    if (a != b)
        std::cout << "a n'est pas egale a b" << std::endl;
    if (c >= b)
        std::cout << "c est plus grand ou egale a b" << std::endl;
    if (c <= b)
        std::cout << "c est plus petit ou egale a b" << std::endl;

    std::cout << std::endl;
    a = Fixed(5);
    std::cout << "a=" << a << "   b=" << b << "   c=" << c << std::endl;
    Fixed d = a + b;
    std::cout << "a + b = " << d << std::endl;
    Fixed e = a - b;
    std::cout << "a - b = " << e << std::endl;
    Fixed f = a * b;
    std::cout << "a * b = " << f << std::endl;
    Fixed g = b / a;
    std::cout << "b / a = " << g << std::endl;

    std::cout << std::endl;
     a = Fixed(5);
    std::cout << "a=" << a << "   b=" << b << "   c=" << c << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "--a = " << --a << std::endl;
    std::cout << "a=" << a << std::endl;
    return 0;
}
