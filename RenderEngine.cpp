#include "RenderEngine.h"
#include "Shape.h"
#include <vector>

namespace CraneTranformation
{
	using namespace System;
	using namespace System::Drawing;
	using System::Collections::Generic::List;

	RenderEngine::RenderEngine(System::Windows::Forms::Panel^ Canvas)
	{
		this->canvas = Canvas;
		queue = gcnew List<Shape^>();
	}

	void RenderEngine::addShape(Shape^ shape)
	{
		queue->Add(shape);
	}

	void RenderEngine::render(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		for each (Shape^ shape in queue) {
			e->Graphics->DrawPolygon(renderPen, shape->get_points());
		}
	}
};