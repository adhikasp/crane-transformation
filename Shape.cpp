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

	void Shape::rotate(Point^ reference, float degree)
	{
		Point^ tmp;
		double radian = degree * 2 * Math::PI / 180;
		for (int i = 0; i < points->Length; i++) {
			tmp = points[i];
			
			// 1. Translate to 0, 0
			tmp->X -= reference->X;
			tmp->Y -= reference->Y;

			// 2. Rotate
			tmp->X = (int)( tmp->X * Math::Cos(radian) - tmp->Y * Math::Sin(radian) + 0.5 );
			tmp->Y = (int)( tmp->X * Math::Sin(radian) + tmp->Y * Math::Cos(radian) + 0.5 );

			// 3. Tranlate back
			tmp->X += reference->X;
			tmp->Y += reference->Y;

			// Save to shape
			points[i].X = tmp->X;
			points[i].Y = tmp->Y;
		}
	}
}