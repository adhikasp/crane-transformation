#pragma once
#include "RenderEngine.h"	
#include "Crane.h"

namespace CraneTranformation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CraneWindow
	/// </summary>
	public ref class CraneWindow : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Panel^    CraneCanvas;
		CraneTranformation::RenderEngine^ renderer;
	private: System::Windows::Forms::Button^  moveRight;
	private: System::Windows::Forms::Button^  moveLeft;


			 CraneTranformation::Crane^        crane;

	public:
		CraneWindow(void)
		{
			InitializeComponent();

			this->renderer = gcnew CraneTranformation::RenderEngine(this->CraneCanvas);
			this->crane    = gcnew Crane(this->renderer);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CraneWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CraneCanvas = (gcnew System::Windows::Forms::Panel());
			this->moveRight = (gcnew System::Windows::Forms::Button());
			this->moveLeft = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// CraneCanvas
			// 
			this->CraneCanvas->BackColor = System::Drawing::Color::White;
			this->CraneCanvas->Location = System::Drawing::Point(12, 12);
			this->CraneCanvas->Name = L"CraneCanvas";
			this->CraneCanvas->Size = System::Drawing::Size(754, 471);
			this->CraneCanvas->TabIndex = 0;
			this->CraneCanvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CraneWindow::CraneCanvas_Paint);
			// 
			// moveRight
			// 
			this->moveRight->Location = System::Drawing::Point(93, 513);
			this->moveRight->Name = L"moveRight";
			this->moveRight->Size = System::Drawing::Size(75, 23);
			this->moveRight->TabIndex = 1;
			this->moveRight->Text = L"Kanan";
			this->moveRight->UseVisualStyleBackColor = true;
			this->moveRight->Click += gcnew System::EventHandler(this, &CraneWindow::button1_Click);
			// 
			// moveLeft
			// 
			this->moveLeft->Location = System::Drawing::Point(12, 513);
			this->moveLeft->Name = L"moveLeft";
			this->moveLeft->Size = System::Drawing::Size(75, 23);
			this->moveLeft->TabIndex = 2;
			this->moveLeft->Text = L"Kiri";
			this->moveLeft->UseVisualStyleBackColor = true;
			this->moveLeft->Click += gcnew System::EventHandler(this, &CraneWindow::button1_Click_1);
			// 
			// CraneWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 565);
			this->Controls->Add(this->moveLeft);
			this->Controls->Add(this->moveRight);
			this->Controls->Add(this->CraneCanvas);
			this->Name = L"CraneWindow";
			this->Text = L"CraneTranformation";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void CraneCanvas_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			this->renderer->render(sender, e);
		} 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			this->crane->move(20);
			CraneCanvas->Invalidate();
		}
		System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			this->crane->move(-20);
			CraneCanvas->Invalidate();
		}
	};
}
