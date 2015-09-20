#ifndef __SHAPE__
#define __SHAPE__

namespace CraneTranformation
{
	using namespace System;
	using System::Drawing::Point;

	public ref class Shape
	{

	private:
		array<Point>^ points;

	public:					 
		Shape(array<Point>^ shapePoint); 
		array<Point>^ get_points();
		Shape^ operator=(const Shape^ cSource);

		void translate(Point^ delta);
		void rotate(Point^ reference, double degree);

		void printPoint();

	};
}

#endif