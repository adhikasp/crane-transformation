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
		int y = 200;
		int x = 200;

		array<Point>^ bodyPoint = {
			Point(x+40, y+180), 
			Point(x+40, y+150), 
			Point(x+65, y+125), 
			Point(x+90, y+150),
			Point(x+90, y+180)
		};
		array<Point>^ upperArmPoint = {
			Point(x+60, y+131), 
			Point(x+60, y+81),
			Point(x+70, y+81),
			Point(x+70, y+131)
		};

		array<Point>^ circlePoint = gcnew array<Point>(CIRCLE_POINT_ACCURATION);
		// Anonymous namespace for automatic variable garbage dump
		{		   
			int r = 10;
			int theta = 0;
			int i = 0;
			while (theta < 360) {
				double rotation = theta * 2 * Math::PI / 360;
				int tmpx = (int)((x + 65) + r*Math::Cos(rotation) + 0.5);
				int tmpy = (int)((y + 180) + r*Math::Sin(rotation) + 0.5);
				circlePoint[i] = Point(tmpx, tmpy);
				i += 1;
				theta += 360 / CIRCLE_POINT_ACCURATION;
			}
		}

		array<Point>^ foreArmPoint = {
			Point(x+60, y+81),
			Point(x+60, y+51),
			Point(x+70, y+51),
			Point(x+70, y+81)
		};

		array<Point>^ clawPoint = {
			Point(x+56, y+55),
			Point(x+53, y+30),
			Point(x+60, y+30),
			Point(x+63, y+35),
			Point(x+66, y+44),
			Point(x+69, y+35),
			Point(x+72, y+30),
			Point(x+78, y+30),
			Point(x+74, y+55),
			Point(x+66, y+58)
		};

		this->body     = gcnew Component::Body(bodyPoint);
		this->wheel    = gcnew Component::Wheel(circlePoint);
		this->upperArm = gcnew Component::UpperArm(upperArmPoint, Point(x+65, y+131));
		this->foreArm  = gcnew Component::ForeArm(foreArmPoint, Point(x+65, y+81));
		this->claw     = gcnew Component::Claw(clawPoint);

		limb = gcnew array<Component::Limb^> { wheel, body, upperArm, foreArm, claw };
		for (int i = 0; i < limb->Length; i++) {
			renderer->addShape(limb[i]->getShape());
		}
	}

	void Crane::move(int deltaX)
	{	 
		for (int i = 0; i < limb->Length; i++) {
			limb[i]->getShape()->translate(Point(deltaX, 0));
		}
		array<Component::Limb^>^ limbWithJoint = gcnew array<CraneTranformation::Component::Limb^> { upperArm };
		for each (Component::Limb^ limb in limbWithJoint) {
			static_cast<Component::UpperArm^>(upperArm)->jointPoint->X += deltaX;
		}
	}

	void Crane::rotateUpperArm(double degree)
	{
		currentUpperArmRotation += degree;
		Point^ reference = static_cast<Component::UpperArm^>(upperArm)->jointPoint;
		array<Component::Limb^>^ movingLimb = gcnew array<CraneTranformation::Component::Limb^> { upperArm, foreArm, claw };
		for each (Component::Limb^ limb in movingLimb) {
			limb->getShape()->rotate(reference, 10);
		}
	}

	void Crane::rotateForeArm(double degree)
	{
		currentForeArmRotation += degree;
		Point^ reference = static_cast<Component::UpperArm^>(foreArm)->jointPoint;
		array<Component::Limb^>^ movingLimb = gcnew array<CraneTranformation::Component::Limb^> { foreArm, claw };
		for each (Component::Limb^ limb in movingLimb) {
			limb->getShape()->rotate(reference, 10);
		}
	}

}