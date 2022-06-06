#pragma once
#include<iostream>
#include<Windows.h>

#pragma comment(lib, "user32.lib")
namespace GUI {

	using namespace System;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ ToggleT;
	protected:
	private: System::Windows::Forms::CheckBox^ cb1;
	private: System::Windows::Forms::TextBox^ xoffset;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ yoffset;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ToggleT = (gcnew System::Windows::Forms::Label());
			this->cb1 = (gcnew System::Windows::Forms::CheckBox());
			this->xoffset = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->yoffset = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// ToggleT
			// 
			this->ToggleT->AutoSize = true;
			this->ToggleT->BackColor = System::Drawing::Color::Black;
			this->ToggleT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->ToggleT->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->ToggleT->Location = System::Drawing::Point(109, 203);
			this->ToggleT->Name = L"ToggleT";
			this->ToggleT->Size = System::Drawing::Size(55, 26);
			this->ToggleT->TabIndex = 0;
			this->ToggleT->Text = L"OFF";
			// 
			// cb1
			// 
			this->cb1->AutoSize = true;
			this->cb1->BackColor = System::Drawing::Color::Black;
			this->cb1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21));
			this->cb1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->cb1->Location = System::Drawing::Point(84, 137);
			this->cb1->Name = L"cb1";
			this->cb1->Size = System::Drawing::Size(124, 36);
			this->cb1->TabIndex = 1;
			this->cb1->Text = L"Enable";
			this->cb1->UseVisualStyleBackColor = false;
			this->cb1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cb1_CheckedChanged);
			// 
			// xoffset
			// 
			this->xoffset->BackColor = System::Drawing::SystemColors::WindowText;
			this->xoffset->ForeColor = System::Drawing::SystemColors::Window;
			this->xoffset->Location = System::Drawing::Point(84, 23);
			this->xoffset->Name = L"xoffset";
			this->xoffset->Size = System::Drawing::Size(100, 22);
			this->xoffset->TabIndex = 2;
			this->xoffset->Text = L"0";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// yoffset
			// 
			this->yoffset->BackColor = System::Drawing::SystemColors::WindowText;
			this->yoffset->ForeColor = System::Drawing::SystemColors::Window;
			this->yoffset->Location = System::Drawing::Point(84, 51);
			this->yoffset->Name = L"yoffset";
			this->yoffset->Size = System::Drawing::Size(100, 22);
			this->yoffset->TabIndex = 3;
			this->yoffset->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->yoffset);
			this->Controls->Add(this->xoffset);
			this->Controls->Add(this->cb1);
			this->Controls->Add(this->ToggleT);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Zodiac";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cb1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

			if (cb1->Checked == true)
			{
				timer1->Enabled = true;
				ToggleT->Text = "ON";
			}

			else if (cb1->Checked == false)
			{
				timer1->Enabled = false;
				ToggleT->Text = "OFF";
			}
		
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
			if ( ToggleT->Text == "ON")
			{
				if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000))
				{
					int x = System::Convert::ToInt16(xoffset->Text);
					int y = System::Convert::ToInt16(yoffset->Text);

					mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);
				}
			}
		
	}
};
}