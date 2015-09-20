#ifndef __CRANE__
#define __CRANE__

#include "CraneComponent.h"
#include "RenderEngine.h"

namespace CraneTranformation
{

	public ref class Crane
	{
	private:
		Component::Limb^     body;
		Component::Limb^    wheel;
		Component::Limb^  foreArm;
		Component::Limb^ upperArm;
		Component::Limb^     claw;

		array<Component::Limb^>^ limb;

		double currentUpperArmRotation = 0;
		static const double MAX_UPPERARM_ROTATION = 30;
		static const double MIN_UPPERARM_ROTATION = -30;

		double currentForeArmRotation = 0;
		static const double MAX_FOREARM_ROTATION = 30;
		static const double MIN_FOREARM_ROTATION = -30;

		static const double MAX_CLAW_ROTATION = 30;
		static const double MIN_CLAW_ROTATION = -30;

	public:
		Crane(CraneTranformation::RenderEngine^ renderer);

		void move(int deltaX);		 		
		void rotateUpperArm(double degree);
		void rotateForeArm(double degree);

		/*
		void rotateClaw(double degree);
		void clapClaw();
		*/
	};

}

#endif