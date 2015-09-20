#ifndef __CRANECOMPONENT__
#define __CRANECOMPONENT__

#include "Shape.h"

namespace CraneTranformation {
	namespace Component
	{
		public ref class Limb
		{
		private:
			CraneTranformation::Shape^ shape;
			CraneTranformation::Shape^ originalShape;
		public:
			Limb(array<Point>^ shapePoint);	  
			Shape^ getShape();
			Shape^ getOriginalShape();
		};

		public ref class Body : public Limb
		{
		public:
			Body(array<Point>^ shapePoint);
		};

		public ref class UpperArm : public Limb
		{
		public:
			Point^ jointPoint;
			UpperArm(array<Point>^ shapePoint, Point^ jointPoint);
		};

		public ref class ForeArm : public Limb
		{
		public:
			ForeArm(array<Point>^ shapePoint); 

		};

		public ref class Wheel : public Limb
		{
		public:
			Wheel(array<Point>^ shapePoint);

		};

		public ref class Claw : public Limb
		{
		public:
			Claw(array<Point>^ shapePoint);

		};

	}
}

#endif