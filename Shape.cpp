#include "Shape.h"

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

	void Shape::translate(Point^ delta)
	{
		for (int i = 0; i < points->Length; i++)
		{
			points[i].X += delta->X;
			points[i].Y += delta->Y;
		}
	}

	void Shape::printPoint()
	{
		for each(Point^ point in points)
		{
			System::Console::WriteLine(point->X + " " + point->Y);
		}
	}
}