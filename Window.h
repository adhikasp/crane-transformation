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
	private: System::Windows::Forms::Button^  rotateRight;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Button^  rotateLeft;



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
			this->rotateRight = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->rotateLeft = (gcnew System::Windows::Forms::Button());
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
			// rotateRight
			// 
			this->rotateRight->Location = System::Drawing::Point(401, 513);
			this->rotateRight->Name = L"rotateRight";
			this->rotateRight->Size = System::Drawing::Size(75, 23);
			this->rotateRight->TabIndex = 3;
			this->rotateRight->Text = L"Putar Kanan";
			this->rotateRight->UseVisualStyleBackColor = true;
			this->rotateRight->Click += gcnew System::EventHandler(this, &CraneWindow::rotateRight_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(215, 529);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(97, 17);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Lengan Bawah";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &CraneWindow::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(215, 502);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(85, 17);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Lengan Atas";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &CraneWindow::radioButton2_CheckedChanged);
			// 
			// rotateLeft
			// 
			this->rotateLeft->Location = System::Drawing::Point(320, 513);
			this->rotateLeft->Name = L"rotateLeft";
			this->rotateLeft->Size = System::Drawing::Size(75, 23);
			this->rotateLeft->TabIndex = 6;
			this->rotateLeft->Text = L"Putar Kiri";
			this->rotateLeft->UseVisualStyleBackColor = true;
			this->rotateLeft->Click += gcnew System::EventHandler(this, &CraneWindow::rotateLeft_Click);
			// 
			// CraneWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 565);
			this->Controls->Add(this->rotateLeft);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->rotateRight);
			this->Controls->Add(this->moveLeft);
			this->Controls->Add(this->moveRight);
			this->Controls->Add(this->CraneCanvas);
			this->Name = L"CraneWindow";
			this->Text = L"CraneTranformation";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void CraneCanvas_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			this->renderer->render(sender, e);
		} 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			this->crane->move(10);
			CraneCanvas->Invalidate();
		}
		System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			this->crane->move(-10);
			CraneCanvas->Invalidate();
		}
		System::Void rotateRight_Click(System::Object^  sender, System::EventArgs^  e) {
			if (radioButton1->Checked) {
				this->crane->rotateUpperArm(10);
			}
			else if (radioButton2->Checked) {
				this->crane->rotateForeArm(10);
			}
			CraneCanvas->Invalidate();
		}
		System::Void rotateLeft_Click(System::Object^  sender, System::EventArgs^  e) {
			if (radioButton1->Checked) {
				this->crane->rotateUpperArm(-10);
			}
			else if (radioButton2->Checked) {
				this->crane->rotateForeArm(-10);
			}
			CraneCanvas->Invalidate();

		}

		System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
};
}
