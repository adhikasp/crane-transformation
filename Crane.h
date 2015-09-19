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

	public:
		Crane(CraneTranformation::RenderEngine^ renderer);

		void move(int deltaX);
		
		/*
		void rotateUpperArm();
		void rotateForeArm();
		void rotateClaw();
		void clapClaw();
		*/
	};

}

#endif