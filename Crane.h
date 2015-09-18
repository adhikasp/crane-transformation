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

	public:
		Crane(CraneTranformation::RenderEngine^ renderer);
	};

}

#endif