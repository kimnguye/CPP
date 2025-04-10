#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
	Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	if (area < 0)
		area.setRawBits(-area.getRawBits());
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_abc = area(a, b, c);
	Fixed area_pab = area(point, a, b);
	Fixed area_pac = area(point, a, c);
	Fixed area_pbc = area(point, b, c);
	if (area_pab == 0 || area_pac == 0 || area_pbc == 0)
		return false;
	if (area_pab + area_pac + area_pbc != area_abc)
		return false;
	return true;
}



