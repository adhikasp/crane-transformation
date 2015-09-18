#include "CraneComponent.h"
#include "Shape.h"

namespace CraneTranformation {	namespace Component
{
	
	CraneTranformation::Component::Limb::Limb(array<Point>^ shapePoint)
	{
		this->shape = gcnew CraneTranformation::Shape(shapePoint);
	}

	Shape^ CraneTranformation::Component::Limb::getShape()
	{
		return this->shape;
	}


	CraneTranformation::Component::Body::Body(array<Point>^ shapePoint) : Limb(shapePoint)
	{

	}

	
	CraneTranformation::Component::UpperArm::UpperArm(array<Point>^ shapePoint) : Limb(shapePoint)
	{

	}


	CraneTranformation::Component::ForeArm::ForeArm(array<Point>^ shapePoint) : Limb(shapePoint)
	{

	}


	CraneTranformation::Component::Wheel::Wheel(array<Point>^ shapePoint) : Limb(shapePoint)
	{

	}


	CraneTranformation::Component::Claw::Claw(array<Point>^ shapePoint) : Limb(shapePoint)
	{

	}

}}