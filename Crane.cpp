#include "Crane.h"
#include "CraneComponent.h"
#include "RenderEngine.h"
#include "CraneComponent.h"

#include <vector>

#define CIRCLE_POINT_ACCURATION 12		   // Must be a factor of 360

namespace CraneTranformation
{
	Crane::Crane(CraneTranformation::RenderEngine^ renderer)
	{
		int y = 100;
		int x = 100;

		array<Point>^ pointBody = { 
			Point(x-10, y-10), 
			Point(x-10, y+40), 
			Point(x+40, y+40), 
			Point(x+40, y-10) 
		};
		array<Point>^ pointUpperArm = {
			Point(x+10, y-5), 
			Point(x+20, y-5),
			Point(x+20, y-40),
			Point(x+10, y-40)
		};

		array<Point>^ circlePoint = gcnew array<Point>(CIRCLE_POINT_ACCURATION);
		// Anonymous namespace for automatic variable garbage dump
		{		   
			int r = 20;
			int theta = 0;
			int i = 0;
			while (theta < 360) {
				double rotation = theta * 2 * Math::PI / 360;
				int tmpx = (int)((x + 15) + r*Math::Cos(rotation) + 0.5);
				int tmpy = (int)((y + 40) + r*Math::Sin(rotation) + 0.5);
				circlePoint[i] = Point(tmpx, tmpy);
				i += 1;
				theta += 360 / CIRCLE_POINT_ACCURATION;
			}
		}

		this->body = gcnew Component::Body(pointBody);
		this->wheel = gcnew Component::Wheel(circlePoint);
		this->upperArm = gcnew Component::UpperArm(pointUpperArm);
		//foreArm  = gcnew Component::ForeArm();
		//claw     = gcnew Component::Claw();

		limb = gcnew array<Component::Limb^> { wheel, body, upperArm};
		for (int i = 0; i < limb->Length; i++) {
			renderer->addShape(limb[i]->getShape());
		}
	}

	void Crane::move(int deltaX)
	{	 
		for (int i = 0; i < limb->Length; i++) {
			limb[i]->getShape()->translate(Point(deltaX, 0));
		}
	}

}