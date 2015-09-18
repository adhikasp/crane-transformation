#include "Crane.h"
#include "CraneComponent.h"
#include "RenderEngine.h"


namespace CraneTranformation
{
	Crane::Crane(CraneTranformation::RenderEngine^ renderer)
	{
		array<Point>^ pointBody = { Point(10, 10), Point(10, 40), Point(40, 40), Point(40, 10) };

		this->body = gcnew Component::Body(pointBody);
		//wheel    = gcnew Component::Wheel();
		//foreArm  = gcnew Component::ForeArm();
		//upperArm = gcnew Component::UpperArm();
		//claw     = gcnew Component::Claw();

		renderer->addShape(this->body->getShape());
	}

}