#pragma once
#include <string>
#include "..\Queue\queue.h"
#include <msclr\marshal_cppstd.h>



namespace FormQueue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int MaxSize;
		int Size;
		double p;
		double q;
		int PopCount;
		int PushCount;

		TQueue<int>* pQueue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rnd1;
		Pen^ BlackPen;
		Pen^ WhitePen;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			gr = this->CreateGraphics();
			rnd1 = gcnew Random();

			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.0F;

			CenterX = 200;
			CenterY = 300;
			Width = Height = 200;
			PopCount = PushCount = 0;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Максимальная длина очереди";
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Исходная длина очереди";
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 17);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Вероятность добавления";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 215);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Добавлено в очередь";
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 269);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(159, 17);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Извлечено из очереди";
			this->textBox1->Location = System::Drawing::Point(256, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(124, 22);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"10";
			this->textBox2->Location = System::Drawing::Point(256, 79);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(124, 22);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"0";
			this->textBox3->Location = System::Drawing::Point(256, 124);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(124, 22);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"0,8";
			this->textBox4->Location = System::Drawing::Point(256, 210);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(124, 22);
			this->textBox4->TabIndex = 9;
			this->textBox4->Text = L"0";
			this->textBox5->Location = System::Drawing::Point(256, 264);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(124, 22);
			this->textBox5->TabIndex = 10;
			this->textBox5->Text = L"0";
			this->button1->Location = System::Drawing::Point(471, 82);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 35);
			this->button1->TabIndex = 11;
			this->button1->Text = L"СТАРТ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button2->Location = System::Drawing::Point(471, 173);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(132, 35);
			this->button2->TabIndex = 12;
			this->button2->Text = L"СТОП";
			this->button2->UseVisualStyleBackColor = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(28, 317);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 17);
			this->label6->TabIndex = 13;
			this->label6->Text = L"статус";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			this->textBox6->Location = System::Drawing::Point(256, 170);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(124, 22);
			this->textBox6->TabIndex = 15;
			this->textBox6->Text = L"0,4";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(28, 173);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(177, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Вероятность исключения";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(767, 688);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox2->Text);
		p = Convert::ToDouble(textBox6->Text);
		q = Convert::ToDouble(textBox3->Text);
		//Создание и заполенение очереди
		pQueue = new TQueue<int>(MaxSize);

		PopCount = PushCount = 0;

		textBox4->Text = "0";
		textBox5->Text = "0";

		gr->DrawEllipse(WhitePen, CenterX, CenterY, Width, Height);
		if (timer1->Enabled) {
			timer1->Enabled = false;
		}
		else
			if (Size <= MaxSize) {
				for (int i = 0; i < Size; i++) {
					pQueue->push(i);
				}
				DrawQueue();
				timer1->Enabled = true;
			}
			else {
				label6->Text = "Incorrect size";
			}
	}
	///////////////////////
	void DrawQueue() {
		int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
		int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();
		gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
	}
	void Clean() {
		int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
		int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();
		gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, start, finish);
	}
	///////////////////////
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Clean();

		try {
			if (rnd1->NextDouble() < p) {
				pQueue->pop();
				PopCount++;
				
			}
			if (rnd1->NextDouble() < q) {
				pQueue->push(p);
				PushCount++;
			}
			label6->Text = "success";
		}
		catch (int er) {
			switch (er) {
			case 1:
				label6->Text = "full";
				break;
			case 0:
				label6->Text = "empty";
				break;
			}
		}
		// нарисовать очередь
		DrawQueue();
		// обновить статистику
		textBox4->Text = Convert::ToString(PushCount);
		textBox5->Text = Convert::ToString(PopCount);

	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	   private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	   }

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox5_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}