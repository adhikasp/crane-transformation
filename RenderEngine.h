#ifndef __RENDERENGINE__
#define __RENDERENGINE__

#include <vector>
#include "Shape.h"

namespace CraneTranformation
{
	using namespace System;
	using namespace System::Drawing;
	using System::Collections::Generic::List;

	public ref class RenderEngine
	{

	private:	  
		System::Windows::Forms::Panel^ canvas;
		List<Shape^>^ queue;
		Pen^ renderPen = gcnew Pen(Color::Black, 1.0f);


	public:																  
		RenderEngine(System::Windows::Forms::Panel^ Canvas);   
		void addShape(Shape^ shape);
		void render(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);

	};
}

#endif