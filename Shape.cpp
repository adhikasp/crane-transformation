#include "Shape.h"

namespace CraneTranformation
{
	using namespace System;
	using System::Drawing::Point;

	Shape::Shape(array<Point>^ shapePoint)
	{						  
		points = shapePoint;
	}		

	Shape^ Shape::operator=(const Shape^ source)
	{
		// check for self-assignment
		if (this == source)
			return this;

		points = source->points;

		return this;
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

	void Shape::rotate(Point^ reference, double degree)
	{
		Point^ tmp;
		double radian = degree * 2 * Math::PI / 180;
		for (int i = 0; i < points->Length; i++) {
			tmp = points[i];
			
			tmp->X = int( Math::Cos(radian) * (points[i].X - reference->X) - Math::Sin(radian) * (points[i].Y - reference->Y) + reference->X );
			tmp->Y = int( Math::Sin(radian) * (points[i].X - reference->X) + Math::Cos(radian) * (points[i].Y - reference->Y) + reference->Y );

			// Save to shape
			points[i].X = tmp->X;
			points[i].Y = tmp->Y;
		}
		System::Console::WriteLine(reference->X + " " + reference->Y);
	}
}