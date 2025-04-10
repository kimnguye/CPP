#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);
Fixed area(Point const a, Point const b, Point const c);

int main()
{
    Point a(0, 0);
    Point b(0, 20);
    Point c(20, 0);
    Point point1(1, 1);
    Point point2(0, 0);
    std::cout << "a=(" << a.getX() << "," << a.getY() << ") ";
    std::cout << "b=(" << b.getX() << "," << b.getY() << ") ";
    std::cout << "c=(" << c.getX() << "," << c.getY() << ") ";
    std::cout << std::endl;
    std::cout << "point1=(" << point1.getX() << "," << point1.getY() << ") ";
    std::cout << "point2=(" << point2.getX() << "," << point2.getY() << ")";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "point1 is in triangle: " << bsp(a, b, c, point1) << std::endl;
    std::cout << "point2 is not in triangle: " << bsp(a, b, c, point2) << std::endl;

    std::cout << std::endl;

    Point d(0.5f, 0.5f);
    Point e(0, -1);
    Point f(2, 0);
    Point point3(1, 0);
    Point point4(0, 0);
    std::cout << "d=(" << d.getX() << "," << d.getY() << ") ";
    std::cout << "e=(" << e.getX() << "," << e.getY() << ") ";
    std::cout << "f=(" << f.getX() << "," << f.getY() << ") ";
    std::cout << std::endl;
    std::cout << "point3=(" << point3.getX() << "," << point3.getY() << ") ";
    std::cout << "point4=(" << point4.getX() << "," << point4.getY() << ")";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "point3 is in triangle: " << bsp(d, e, f, point3) << std::endl;
    std::cout << "point4 is not in triangle: " << bsp(d, e, f, point4) << std::endl;
    return 0;
}
