#include "Shape.h"
#include <vector>

namespace CraneTranformation
{
	using namespace System;
	using System::Drawing::Point;

	Shape::Shape(array<Point>^ shapePoint)
	{
		points = shapePoint;
	}

	array<Point>^ Shape::get_points()
	{
		return points;
	}
}