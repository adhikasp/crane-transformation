#include "CraneComponent.h"
#include "Shape.h"

namespace CraneTranformation {	namespace Component
{
	
	CraneTranformation::Component::Limb::Limb(array<Point>^ shapePoint)
	{
		this->shape = gcnew CraneTranformation::Shape(shapePoint);
		this->originalShape = gcnew CraneTranformation::Shape(shapePoint);
	}

	Shape^ CraneTranformation::Component::Limb::getShape()
	{
		this->shape = this->originalShape;
		return this->shape;
	}

	Shape^ CraneTranformation::Component::Limb::getOriginalShape()
	{
		return this->originalShape;
	}


	CraneTranformation::Component::Body::Body(array<Point>^ shapePoint) : Limb(shapePoint)
	{

	}

	
	CraneTranformation::Component::UpperArm::UpperArm(array<Point>^ shapePoint, Point^ jointPoint) : Limb(shapePoint)
	{
		this->jointPoint = jointPoint;
	}


	CraneTranformation::Component::ForeArm::ForeArm(array<Point>^ shapePoint, Point^ jointPoint) : Limb(shapePoint)
	{
		this->jointPoint = jointPoint;
	}


	CraneTranformation::Component::Wheel::Wheel(array<Point>^ shapePoint) : Limb(shapePoint)
	{

	}


	CraneTranformation::Component::Claw::Claw(array<Point>^ shapePoint) : Limb(shapePoint)
	{

	}

}}