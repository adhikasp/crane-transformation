#ifndef __UTILITY__
#define __UTILITY__

namespace CraneTranformation
{
	using namespace System;
	using System::Drawing::Point;

	public class Utility
	{

	private:

	public:

		static Point^ rotate(Point^ point, Point^ reference, double degree) {
			Point^ tmp;
			double radian = degree * 2 * Math::PI / 180;

			tmp = point;

			tmp->X = int(Math::Cos(radian) * (point->X - reference->X) - Math::Sin(radian) * (point->Y - reference->Y) + reference->X + 0.5);
			tmp->Y = int(Math::Sin(radian) * (point->X - reference->X) + Math::Cos(radian) * (point->Y - reference->Y) + reference->Y + 0.5);

			// Save to shape
			point->X = tmp->X;
			point->Y = tmp->Y;

			return point;
		}

	};
}

#endif