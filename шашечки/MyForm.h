#pragma once 

namespace шашечки {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	/// <summary> 

	/// </summary> 
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// 

			// 
		}

	protected:
		/// <summary> 

		/// </summary> 
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary> 

		/// </summary> 
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code 
		/// <summary> 

		/// </summary> 
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(584, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(88, 30);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Новая игра";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(275, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 23);
			this->label1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(684, 561);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion 
		array<PictureBox^>^ TB2 = gcnew array<PictureBox^>(64);
		array<Label^>^ TB3 = gcnew array<Label^>(16);
		int now = 0, color = 1, fight = 0;//fight(podboem)
		PictureBox^ t = nullptr;

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		now = 0; color = 1; fight = 0;
		int a = 0;
		if (TB2[0] == nullptr)
		{
			for (int i = 0; i < 8; i++)//stroki
			{
				for (int j = 0; j < 8; j++)//stilbci
				{
					TB2[a] = gcnew PictureBox();//create new picture box
					this->Controls->Add(TB2[a]);
					if (i % 2 == 0)//if delitsa na 2
					{
						if (j % 2 == 0)
						{
							TB2[a]->BackColor = System::Drawing::Color::White;
						}
						else
						{
							TB2[a]->BackColor = System::Drawing::Color::DarkGray;
						}
					}
					else
					{
						if (j % 2 == 0)
						{
							TB2[a]->BackColor = System::Drawing::Color::DarkGray;
						}
						else
						{
							TB2[a]->BackColor = System::Drawing::Color::White;
						}
					}
					TB2[a]->Size = System::Drawing::Size(55, 55);
					TB2[a]->TabIndex = a;
					TB2[a]->TabStop = false;//can li sender shashka bit 1+ 0-
					TB2[a]->Location = Point(110 + j * 55, 55 + i * 55);
					TB2[a]->SizeMode = PictureBoxSizeMode::StretchImage;
					TB2[a]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseClick);
					if (TB2[a]->BackColor == System::Drawing::Color::DarkGray)
					{
						if (i < 3)
						{
							TB2[a]->Image = Image::FromFile("white1.png");
							TB2[a]->Text = "white";
						}
						if (i > 4)
						{
							TB2[a]->Image = Image::FromFile("black1.png");
							TB2[a]->Text = "black";
						}
					}
					a++;
				}
			}
			int x = 0;
			for (int i = 0; i < 8; i++)
			{
				TB3[i] = gcnew Label();
				this->Controls->Add(TB3[i]);
				TB3[i]->AutoSize = true;
				TB3[i]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				TB3[i]->Location = System::Drawing::Point(121 + x, 496);
				TB3[i]->Name = L"label1";
				TB3[i]->Size = System::Drawing::Size(32, 31);
				TB3[i]->TabIndex = 3;
				switch (i)
				{
				case 0: TB3[i]->Text = L"A"; break;
				case 1: TB3[i]->Text = L"B"; break;
				case 2: TB3[i]->Text = L"C"; break;
				case 3: TB3[i]->Text = L"D"; break;
				case 4: TB3[i]->Text = L"E"; break;
				case 5: TB3[i]->Text = L"F"; break;
				case 6: TB3[i]->Text = L"G"; break;
				case 7: TB3[i]->Text = L"H"; break;
				}

				x = x + 55;
			}
			int y = 0;
			for (int i = 8; i < 16; i++)
			{
				TB3[i] = gcnew Label();
				this->Controls->Add(TB3[i]);
				TB3[i]->AutoSize = true;
				TB3[i]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				TB3[i]->Location = System::Drawing::Point(552, 69 + y);
				TB3[i]->Name = L"label1";
				TB3[i]->Size = System::Drawing::Size(32, 31);
				TB3[i]->TabIndex = 3;
				switch (i)
				{
				case 8: TB3[i]->Text = L"8"; break;
				case 9: TB3[i]->Text = L"7"; break;
				case 10: TB3[i]->Text = L"6"; break;
				case 11: TB3[i]->Text = L"5"; break;
				case 12: TB3[i]->Text = L"4"; break;
				case 13: TB3[i]->Text = L"3"; break;
				case 14: TB3[i]->Text = L"2"; break;
				case 15: TB3[i]->Text = L"1"; break;
				}

				y = y + 55;
			}
		}
		else
		{
			for (int i = 0; i < 64; i++)//stroki
			{
				TB2[i]->Image = nullptr;
				TB2[i]->Text = "";
				if (TB2[i]->BackColor == System::Drawing::Color::Blue)
				{
					TB2[i]->BackColor = System::Drawing::Color::DarkGray;
				}
			}

			for (int i = 0; i < 8; i++)//stroki
			{
				for (int j = 0; j < 8; j++)//stilbci
				{
					if (TB2[a]->BackColor == System::Drawing::Color::DarkGray)
					{
						if (i < 3)
						{
							TB2[a]->Image = Image::FromFile("C:/Users/user/Documents/Visual Studio 2017/Projects/шашечки/images/white1.png");
							TB2[a]->Text = "white";
						}
						if (i > 4)
						{
							TB2[a]->Image = Image::FromFile("C:/Users/user/Documents/Visual Studio 2017/Projects/шашечки/images/black1.png");
							TB2[a]->Text = "black";
						}
					}
					a++;
				}
			}
		}
		label1->Text = "Ход белых";
	}

			 void theend()
			 {
				 int w = 0, b = 0;
				 for (int i = 0; i < 64; i++)
				 {
					 if (TB2[i]->Text == "white" || TB2[i]->Text == "white1")
					 {
						 w++;
					 }
					 if (TB2[i]->Text == "black" || TB2[i]->Text == "black1")
					 {
						 b++;
					 }
				 }
				 if (b == 0)
				 {
					 MessageBox::Show("Победили белые");
				 }
				 if (w == 0)
				 {
					 MessageBox::Show("Победили черные");
				 }
			 }

			 void allgray()
			 {
				 for (int i = 0; i < 64; i++)
				 {
					 if (TB2[i]->BackColor == System::Drawing::Color::Blue)
					 {
						 TB2[i]->BackColor = System::Drawing::Color::DarkGray;
					 }
				 }
			 }

			 void fight0()//obnulenie fight
			 {
				 for (int i = 0; i < 64; i++)
				 {
					 TB2[i]->TabStop = 0;
				 }
			 }

			 void lighting(PictureBox^sender)
			 {
				 if (((PictureBox^)sender)->Text == "white")
				 {
					 if (((PictureBox^)sender)->TabIndex + 14 <= 63)
					 {
						 if ((((PictureBox^)sender)->TabIndex + 7) % 8 != 0)
						 {
							 if ((TB2[((PictureBox^)sender)->TabIndex + 7]->Text == "black") || (TB2[((PictureBox^)sender)->TabIndex + 7]->Text == "black1"))
							 {
								 if (TB2[((PictureBox^)sender)->TabIndex + 14]->Image == nullptr)
								 {
									 TB2[((PictureBox^)sender)->TabIndex + 14]->BackColor = System::Drawing::Color::Blue;
								 }
							 }
						 }
					 }

					 if (((PictureBox^)sender)->TabIndex - 14 >= 0)
					 {
						 if (((((PictureBox^)sender)->TabIndex - 7) + 1) % 8 != 0)
						 {
							 if ((TB2[((PictureBox^)sender)->TabIndex - 7]->Text == "black") || (TB2[((PictureBox^)sender)->TabIndex - 7]->Text == "black1"))
							 {
								 if (TB2[((PictureBox^)sender)->TabIndex - 14]->Image == nullptr)
								 {
									 TB2[((PictureBox^)sender)->TabIndex - 14]->BackColor = System::Drawing::Color::Blue;
								 }
							 }
						 }
					 }

					 if (((PictureBox^)sender)->TabIndex + 18 <= 63)
					 {
						 if (((((PictureBox^)sender)->TabIndex + 9) + 1) % 8 != 0)
						 {
							 if ((TB2[((PictureBox^)sender)->TabIndex + 9]->Text == "black") || (TB2[((PictureBox^)sender)->TabIndex + 9]->Text == "black1"))
							 {
								 if (TB2[((PictureBox^)sender)->TabIndex + 18]->Image == nullptr)
								 {
									 TB2[((PictureBox^)sender)->TabIndex + 18]->BackColor = System::Drawing::Color::Blue;
								 }
							 }
						 }
					 }

					 if (((PictureBox^)sender)->TabIndex - 18 >= 0)
					 {
						 if ((((PictureBox^)sender)->TabIndex - 9) % 8 != 0)
						 {
							 if ((TB2[((PictureBox^)sender)->TabIndex - 9]->Text == "black") || (TB2[((PictureBox^)sender)->TabIndex - 9]->Text == "black1"))
							 {
								 if (TB2[((PictureBox^)sender)->TabIndex - 18]->Image == nullptr)
								 {
									 TB2[((PictureBox^)sender)->TabIndex - 18]->BackColor = System::Drawing::Color::Blue;
								 }
							 }
						 }
					 }
				 }

				 if (((PictureBox^)sender)->Text == "black")
				 {
					 if (((PictureBox^)sender)->TabIndex + 14 <= 63)
					 {
						 if ((((PictureBox^)sender)->TabIndex + 7) % 8 != 0)
						 {
							 if ((TB2[((PictureBox^)sender)->TabIndex + 7]->Text == "white") || (TB2[((PictureBox^)sender)->TabIndex + 7]->Text == "white1"))
							 {
								 if (TB2[((PictureBox^)sender)->TabIndex + 14]->Image == nullptr)
								 {
									 TB2[((PictureBox^)sender)->TabIndex + 14]->BackColor = System::Drawing::Color::Blue;
								 }
							 }
						 }
					 }

					 if (((PictureBox^)sender)->TabIndex - 14 >= 0)
					 {
						 if (((((PictureBox^)sender)->TabIndex - 7) + 1) % 8 != 0)
						 {
							 if ((TB2[((PictureBox^)sender)->TabIndex - 7]->Text == "white") || (TB2[((PictureBox^)sender)->TabIndex - 7]->Text == "white1"))
							 {
								 if (TB2[((PictureBox^)sender)->TabIndex - 14]->Image == nullptr)
								 {
									 TB2[((PictureBox^)sender)->TabIndex - 14]->BackColor = System::Drawing::Color::Blue;
								 }
							 }
						 }
					 }

					 if (((PictureBox^)sender)->TabIndex + 18 <= 63)
					 {
						 if (((((PictureBox^)sender)->TabIndex + 9) + 1) % 8 != 0)
						 {
							 if ((TB2[((PictureBox^)sender)->TabIndex + 9]->Text == "white") || (TB2[((PictureBox^)sender)->TabIndex + 9]->Text == "white1"))
							 {
								 if (TB2[((PictureBox^)sender)->TabIndex + 18]->Image == nullptr)
								 {
									 TB2[((PictureBox^)sender)->TabIndex + 18]->BackColor = System::Drawing::Color::Blue;
								 }
							 }
						 }
					 }

					 if (((PictureBox^)sender)->TabIndex - 18 >= 0)
					 {
						 if ((((PictureBox^)sender)->TabIndex - 9) % 8 != 0)
						 {
							 if ((TB2[((PictureBox^)sender)->TabIndex - 9]->Text == "white") || (TB2[((PictureBox^)sender)->TabIndex - 9]->Text == "white1"))
							 {
								 if (TB2[((PictureBox^)sender)->TabIndex - 18]->Image == nullptr)
								 {
									 TB2[((PictureBox^)sender)->TabIndex - 18]->BackColor = System::Drawing::Color::Blue;
								 }
							 }
						 }
					 }
				 }
			 }

			 void lightingdamka(PictureBox^sender)
			 {
				 int a = 1;
				 int i = ((PictureBox^)sender)->TabIndex;
				 while (i < 56 && i % 8 != 0 && a)
				 {
					 i = i + 7;
					 if (TB2[i]->Image != nullptr)
					 {
						 a = 0;
					 }
					 else
					 {
						 TB2[i]->BackColor = System::Drawing::Color::Blue;
					 }
				 }
				 a = 1;
				 i = ((PictureBox^)sender)->TabIndex;
				 while (i < 56 && (i + 1) % 8 != 0 && a)
				 {
					 i = i + 9;
					 if (TB2[i]->Image != nullptr)
					 {
						 a = 0;
					 }
					 else
					 {
						 TB2[i]->BackColor = System::Drawing::Color::Blue;
					 }
				 }
				 a = 1;
				 i = ((PictureBox^)sender)->TabIndex;
				 while (i > 7 && (i + 1) % 8 != 0 && a)
				 {
					 i = i - 7;
					 if (TB2[i]->Image != nullptr)
					 {
						 a = 0;
					 }
					 else
					 {
						 TB2[i]->BackColor = System::Drawing::Color::Blue;
					 }
				 }
				 a = 1;
				 i = ((PictureBox^)sender)->TabIndex;
				 while (i > 7 && i % 8 != 0 && a)
				 {
					 i = i - 9;
					 if (TB2[i]->Image != nullptr)
					 {
						 a = 0;
					 }
					 else
					 {
						 TB2[i]->BackColor = System::Drawing::Color::Blue;
					 }
				 }
			 }

			 void lightingdamkacanfight(PictureBox^sender)
			 {

				 if (((PictureBox^)sender)->TabStop == 1)
				 {
					 if (((PictureBox^)sender)->Text == "white1") {
						 int a = 1;
						 int i = ((PictureBox^)sender)->TabIndex;
						 while (i < 56 && i % 8 != 0 && a)
						 {
							 i = i + 7;
							 if (TB2[i]->Text != "white1" && TB2[i]->Text != "white")
							 {
								 if (i % 8 != 0 && i < 56)
								 {
									 if (TB2[i]->Text == "black" || TB2[i]->Text == "black1")
									 {
										 if (TB2[i + 7]->Image == nullptr)
										 {
											 i = i + 7;
											 while (TB2[i]->Text != "black" && a && TB2[i]->Text != "white1" && TB2[i]->Text != "white" && TB2[i]->Text != "black1")
											 {
												 TB2[i]->BackColor = System::Drawing::Color::Blue;
												 if (i % 8 == 0 || i >= 56)
												 {
													 a = 0;
												 }
												 if (a)
												 {
													 i = i + 7;
												 }
											 }
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
								 else
								 {
									 a = 0;
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }
						 a = 1;
						 i = ((PictureBox^)sender)->TabIndex;
						 while (i < 56 && (i + 1) % 8 != 0 && a)
						 {
							 i = i + 9;
							 if (TB2[i]->Text != "white1" || TB2[i]->Text != "white")
							 {
								 if ((i + 1) % 8 != 0 && i < 56)
								 {
									 if (TB2[i]->Text == "black" || TB2[i]->Text == "black1")
									 {
										 if (TB2[i + 9]->Image == nullptr)
										 {
											 i = i + 9;
											 while (TB2[i]->Text != "black" && a && TB2[i]->Text != "white1" && TB2[i]->Text != "white" && TB2[i]->Text != "black1")
											 {
												 TB2[i]->BackColor = System::Drawing::Color::Blue;
												 if ((i + 1) % 8 == 0 || i >= 56)
												 {
													 a = 0;
												 }
												 if (a)
												 {
													 i = i + 9;
												 }
											 }
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
								 else
								 {
									 a = 0;
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }
						 a = 1;
						 i = ((PictureBox^)sender)->TabIndex;
						 while (i > 7 && (i + 1) % 8 != 0 && a)
						 {
							 i = i - 7;
							 if (TB2[i]->Text != "white1" || TB2[i]->Text != "white")
							 {
								 if ((i + 1) % 8 != 0 && i > 7)
								 {
									 if (TB2[i]->Text == "black" || TB2[i]->Text == "black1")
									 {
										 if (TB2[i - 7]->Image == nullptr)
										 {
											 i = i - 7;
											 while (TB2[i]->Text != "black" && a && TB2[i]->Text != "white1" && TB2[i]->Text != "white" && TB2[i]->Text != "black1")
											 {
												 TB2[i]->BackColor = System::Drawing::Color::Blue;
												 MessageBox::Show(System::Convert::ToString(i));
												 if ((i + 1) % 8 == 0 || i <= 7)
												 {
													 a = 0;
												 }
												 if (a)
												 {
													 i = i - 7;
												 }
											 }
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
								 else
								 {
									 a = 0;
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }
						 a = 1;
						 i = ((PictureBox^)sender)->TabIndex;
						 while (i > 7 && i % 8 != 0 && a)
						 {
							 i = i - 9;
							 if (TB2[i]->Text != "white1" || TB2[i]->Text != "white")
							 {
								 if (i % 8 != 0 && i > 7)
								 {
									 if (TB2[i]->Text == "black" || TB2[i]->Text == "black1")
									 {
										 if (TB2[i - 9]->Image == nullptr)
										 {
											 i = i - 9;
											 while (TB2[i]->Text != "black" && a && TB2[i]->Text != "white1" && TB2[i]->Text != "white" && TB2[i]->Text != "black1")
											 {
												 TB2[i]->BackColor = System::Drawing::Color::Blue;
												 if (i % 8 == 0 || i <= 7)
												 {
													 a = 0;
												 }
												 if (a)
												 {
													 i = i - 9;
												 }
											 }
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
								 else
								 {
									 a = 0;
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }
					 }

					 ///////////////////////////////////////////////////////////////
					 if (((PictureBox^)sender)->Text == "black1") {

						 int a = 1;
						 int i = ((PictureBox^)sender)->TabIndex;
						 while (i < 56 && i % 8 != 0 && a)
						 {
							 i = i + 7;
							 if (TB2[i]->Text != "black1" && TB2[i]->Text != "black")
							 {
								 if (i % 8 != 0 && i < 56)
								 {
									 if (TB2[i]->Text == "white" || TB2[i]->Text == "white1")
									 {
										 if (TB2[i + 7]->Image == nullptr)
										 {
											 i = i + 7;
											 while (TB2[i]->Text != "white" && a && TB2[i]->Text != "black1" && TB2[i]->Text != "black" && TB2[i]->Text != "white1")
											 {
												 TB2[i]->BackColor = System::Drawing::Color::Blue;
												 if (i % 8 == 0 || i >= 56)
												 {
													 a = 0;
												 }
												 if (a)
												 {
													 i = i + 7;
												 }
											 }
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
								 else
								 {
									 a = 0;
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }
						 a = 1;
						 i = ((PictureBox^)sender)->TabIndex;
						 while (i < 56 && (i + 1) % 8 != 0 && a)
						 {
							 i = i + 9;
							 if (TB2[i]->Text != "black1" || TB2[i]->Text != "black")
							 {
								 if ((i + 1) % 8 != 0 && i < 56)
								 {
									 if (TB2[i]->Text == "white" || TB2[i]->Text == "white1")
									 {
										 if (TB2[i + 9]->Image == nullptr)
										 {
											 i = i + 9;
											 while (TB2[i]->Text != "white" && a && TB2[i]->Text != "black1" && TB2[i]->Text != "black" && TB2[i]->Text != "white1")
											 {
												 TB2[i]->BackColor = System::Drawing::Color::Blue;
												 if ((i + 1) % 8 == 0 || i >= 56)
												 {
													 a = 0;
												 }
												 if (a)
												 {
													 i = i + 9;
												 }
											 }
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
								 else
								 {
									 a = 0;
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }
						 a = 1;
						 i = ((PictureBox^)sender)->TabIndex;
						 while (i > 7 && (i + 1) % 8 != 0 && a)
						 {
							 i = i - 7;
							 if (TB2[i]->Text != "black1" || TB2[i]->Text != "black")
							 {
								 if ((i + 1) % 8 != 0 && i > 7)
								 {
									 if (TB2[i]->Text == "white" || TB2[i]->Text == "white1")
									 {
										 if (TB2[i - 7]->Image == nullptr)
										 {
											 i = i - 7;
											 while (TB2[i]->Text != "white" && a && TB2[i]->Text != "black1" && TB2[i]->Text != "black" && TB2[i]->Text != "white1")
											 {
												 TB2[i]->BackColor = System::Drawing::Color::Blue;
												 MessageBox::Show(System::Convert::ToString(i));
												 if ((i + 1) % 8 == 0 || i <= 7)
												 {
													 a = 0;
												 }
												 if (a)
												 {
													 i = i - 7;
												 }
											 }
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }

								 }
								 else
								 {
									 a = 0;
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }
						 a = 1;
						 i = ((PictureBox^)sender)->TabIndex;
						 while (i > 7 && i % 8 != 0 && a)
						 {
							 i = i - 9;
							 if (TB2[i]->Text != "black1" || TB2[i]->Text != "black")
							 {
								 if (i % 8 != 0 && i > 7)
								 {
									 if (TB2[i]->Text == "white" || TB2[i]->Text == "white1")
									 {
										 if (TB2[i - 9]->Image == nullptr)
										 {
											 i = i - 9;
											 while (TB2[i]->Text != "white" && a && TB2[i]->Text != "black1" && TB2[i]->Text != "black" && TB2[i]->Text != "white1")
											 {
												 TB2[i]->BackColor = System::Drawing::Color::Blue;
												 if (i % 8 == 0 || i <= 7)
												 {
													 a = 0;
												 }
												 if (a)
												 {
													 i = i - 9;
												 }
											 }
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
								 else
								 {
									 a = 0;
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }
					 }


				 }
			 }

			 void proverkanaboiblack()
			 {
				 for (int i = 0; i < 64; i++)
				 {
					 if (TB2[i]->Text == "black")
					 {
						 if ((i < 47) && (i % 8 != 0))
						 {
							 if ((i + 7) % 8 != 0)
							 {
								 if ((TB2[i + 7]->Text == "white") || (TB2[i + 7]->Text == "white1"))
								 {
									 if (TB2[i + 14]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
									 }
								 }
							 }
						 }
						 if (i > 16 && ((i + 1) % 8 != 0))
						 {
							 if ((TB2[i - 7]->Text == "white") || (TB2[i - 7]->Text == "white1"))
							 {
								 if ((i - 6) % 8 != 0)
								 {
									 if (TB2[i - 14]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
									 }
								 }
							 }
						 }
						 if ((i < 47) && ((i + 1) % 8 != 0))
						 {
							 if ((TB2[i + 9]->Text == "white") || (TB2[i + 9]->Text == "white1"))
							 {
								 if ((i + 10) % 8 != 0)
								 {
									 if (TB2[i + 18]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
									 }
								 }
							 }
						 }
						 if ((i > 16) && (i % 8 != 0))
						 {
							 if ((TB2[i - 9]->Text == "white") || (TB2[i - 9]->Text == "white1"))
							 {
								 if ((i - 9) % 8 != 0)
								 {
									 if (TB2[i - 18]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
									 }
								 }
							 }
						 }
					 }
					 if (TB2[i]->Text == "black1")
					 {
						 int d = i;
						 int a = 1;
						 while (d < 47 && d % 8 != 0 && a)
						 {
							 d = d + 7;
							 if (d % 8 != 0)
							 {
								 if (TB2[d]->Text == "black1" || TB2[d]->Text == "black")
								 {
									 a = 0;
								 }
								 else
								 {
									 if (d % 8 != 0)
									 {
										 if (TB2[d]->Text == "white" || TB2[d]->Text == "white1")
										 {
											 if (TB2[d + 7]->Image == nullptr)
											 {
												 TB2[i]->TabStop = 1;
												 fight = 1;
												 a = 0;
											 }
											 else
											 {
												 a = 0;
											 }
										 }
									 }
								 }
							 }
						 }

						 d = i;
						 a = 1;
						 while (d > 16 && (d + 1) % 8 != 0 && a)
						 {
							 d = d - 7;
							 if ((d + 1) % 8 != 0)
							 {
								 if (TB2[d]->Text == "black1" || TB2[d]->Text == "black")
								 {
									 a = 0;
								 }
								 else
								 {
									 if ((TB2[d]->Text == "white" || TB2[d]->Text == "white1"))
									 {
										 if (TB2[d - 7]->Image == nullptr)
										 {
											 TB2[i]->TabStop = 1;
											 fight = 1;
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }

						 d = i;
						 a = 1;
						 while (d < 47 && (d + 1) % 8 != 0 && a)
						 {
							 d = d + 9;
							 if ((d + 1) % 8 != 0)
							 {
								 if (TB2[d]->Text == "black1" || TB2[d]->Text == "black")
								 {
									 a = 0;
								 }
								 else
								 {

									 if (TB2[d]->Text == "white" || TB2[d]->Text == "white1")
									 {
										 if (TB2[d + 9]->Image == nullptr)
										 {
											 TB2[i]->TabStop = 1;
											 fight = 1;
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }

								 }
							 }
						 }

						 d = i;
						 a = 1;
						 while (d > 16 && d % 8 != 0 && a)
						 {
							 d = d - 9;
							 if (d % 8 != 0)
							 {
								 if (TB2[d]->Text == "black1" || TB2[d]->Text == "black")
								 {
									 a = 0;
								 }
								 else
								 {

									 if (TB2[d]->Text == "white" || TB2[d]->Text == "white1")
									 {
										 if (TB2[d - 9]->Image == nullptr)
										 {
											 TB2[i]->TabStop = 1;
											 fight = 1;
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }

								 }
							 }
						 }

					 }
				 }

			 }

			 void proverkanaboiwhite()
			 {
				 for (int i = 0; i < 64; i++)
				 {
					 if (TB2[i]->Text == "white")
					 {
						 if ((i < 47) && (i % 8 != 0))
						 {
							 if ((i + 7) % 8 != 0)
							 {
								 if ((TB2[i + 7]->Text == "black") || (TB2[i + 7]->Text == "black1"))
								 {
									 if (TB2[i + 14]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
									 }
								 }
							 }
						 }
						 if (i > 16 && ((i + 1) % 8 != 0))
						 {
							 if ((TB2[i - 7]->Text == "black" || (TB2[i - 7]->Text == "black1")))
							 {
								 if ((i - 6) % 8 != 0)
								 {
									 if (TB2[i - 14]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
									 }
								 }
							 }
						 }
						 if ((i < 47) && ((i + 1) % 8 != 0))
						 {
							 if ((TB2[i + 9]->Text == "black") || (TB2[i + 9]->Text == "black1"))
							 {
								 if ((i + 10) % 8 != 0)
								 {
									 if (TB2[i + 18]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
									 }
								 }
							 }
						 }
						 if ((i > 16) && (i % 8 != 0))
						 {
							 if ((TB2[i - 9]->Text == "black") || (TB2[i - 9]->Text == "black1"))
							 {
								 if ((i - 9) % 8 != 0)
								 {
									 if (TB2[i - 18]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
									 }
								 }
							 }
						 }
					 }

					 if (TB2[i]->Text == "white1")
					 {
						 int d = i;
						 int a = 1;
						 while (d < 47 && d % 8 != 0 && a)
						 {
							 d = d + 7;
							 if (d % 8 != 0)
							 {
								 if (TB2[d]->Text == "white1" || TB2[d]->Text == "white")
								 {
									 a = 0;
								 }
								 else
								 {
									 if (d % 8 != 0)
									 {
										 if (TB2[d]->Text == "black" || TB2[d]->Text == "black1")
										 {
											 if (TB2[d + 7]->Image == nullptr)
											 {
												 TB2[i]->TabStop = 1;
												 fight = 1;
												 a = 0;
											 }
											 else
											 {
												 a = 0;
											 }
										 }
									 }
								 }
							 }
						 }

						 d = i;
						 a = 1;
						 while (d > 16 && (d + 1) % 8 != 0 && a)
						 {
							 d = d - 7;
							 if ((d + 1) % 8 != 0)
							 {
								 if (TB2[d]->Text == "white1" || TB2[d]->Text == "white")
								 {
									 a = 0;
								 }
								 else
								 {
									 if ((TB2[d]->Text == "black" || TB2[d]->Text == "black1"))
									 {
										 if (TB2[d - 7]->Image == nullptr)
										 {
											 TB2[i]->TabStop = 1;
											 fight = 1;
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
							 }
							 else
							 {
								 a = 0;
							 }
						 }

						 d = i;
						 a = 1;
						 while (d < 47 && (d + 1) % 8 != 0 && a)
						 {
							 d = d + 9;
							 if ((d + 1) % 8 != 0)
							 {
								 if (TB2[d]->Text == "white1" || TB2[d]->Text == "white")
								 {
									 a = 0;
								 }
								 else
								 {

									 if (TB2[d]->Text == "black" || TB2[d]->Text == "black1")
									 {
										 if (TB2[d + 9]->Image == nullptr)
										 {
											 TB2[i]->TabStop = 1;
											 fight = 1;
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }

								 }
							 }
						 }

						 d = i;
						 a = 1;
						 while (d > 16 && d % 8 != 0 && a)
						 {
							 d = d - 9;
							 if (d % 8 != 0)
							 {
								 if (TB2[d]->Text == "white1" || TB2[d]->Text == "white")
								 {
									 a = 0;
								 }
								 else
								 {

									 if (TB2[d]->Text == "black" || TB2[d]->Text == "black1")
									 {
										 if (TB2[d - 9]->Image == nullptr)
										 {
											 TB2[i]->TabStop = 1;
											 fight = 1;
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }

								 }
							 }
						 }

					 }
				 }
			 }

			 void proverkanaboisender(PictureBox^sender)
			 {
				 int i = ((PictureBox^)sender)->TabIndex;
				 if (TB2[i]->Text == "white")
				 {
					 if ((i < 47) && (i % 8 != 0))
					 {
						 if ((i + 7) % 8 != 0)
						 {
							 if ((TB2[i + 7]->Text == "black") || (TB2[i + 7]->Text == "black1"))
							 {
								 if (TB2[i + 14]->Image == nullptr)
								 {
									 TB2[i]->TabStop = 1;
									 fight = 1;
								 }
							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 if (i > 16 && ((i + 1) % 8 != 0))
					 {
						 if ((TB2[i - 7]->Text == "black" || (TB2[i - 7]->Text == "black1")))
						 {
							 if ((i - 6) % 8 != 0)
							 {
								 if (TB2[i - 14]->Image == nullptr)
								 {
									 TB2[i]->TabStop = 1;
									 fight = 1;
								 }
							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 if ((i < 47) && ((i + 1) % 8 != 0))
					 {
						 if ((TB2[i + 9]->Text == "black") || (TB2[i + 9]->Text == "black1"))
						 {
							 if ((i + 10) % 8 != 0)
							 {
								 if (TB2[i + 18]->Image == nullptr)
								 {
									 TB2[i]->TabStop = 1;
									 fight = 1;
								 }
							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 if ((i > 16) && (i % 8 != 0))
					 {
						 if ((TB2[i - 9]->Text == "black") || (TB2[i - 9]->Text == "black1"))
						 {
							 if ((i - 9) % 8 != 0)
							 {
								 if (TB2[i - 18]->Image == nullptr)
								 {
									 TB2[i]->TabStop = 1;
									 fight = 1;
								 }
							 }
						 }
					 }
				 }
				 i = ((PictureBox^)sender)->TabIndex;
				 if (TB2[i]->Text == "white1")
				 {
					 int d = i;
					 int a = 1;
					 while (d < 47 && d % 8 != 0 && a)
					 {
						 d = d + 7;
						 if (d % 8 != 0)
						 {
							 if (TB2[d]->Text == "white1" || TB2[d]->Text == "white")
							 {
								 a = 0;
							 }
							 else
							 {
								 if (d % 8 != 0)
								 {
									 if (TB2[d]->Text == "black" || TB2[d]->Text == "black1")
									 {
										 if (TB2[d + 7]->Image == nullptr)
										 {
											 TB2[i]->TabStop = 1;
											 fight = 1;
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 d = i;
					 a = 1;

					 while (d > 16 && (d + 1) % 8 != 0 && a)
					 {
						 d = d - 7;
						 if ((d + 1) % 8 != 0)
						 {
							 if (TB2[d]->Text == "white1" || TB2[d]->Text == "white")
							 {
								 a = 0;
							 }
							 else
							 {
								 if ((TB2[d]->Text == "black" || TB2[d]->Text == "black1"))
								 {
									 if (TB2[d - 7]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
										 a = 0;
									 }
									 else
									 {
										 a = 0;
									 }
								 }
							 }
						 }
						 else
						 {
							 a = 0;
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 d = i;
					 a = 1;
					 while (d < 47 && (d + 1) % 8 != 0 && a)
					 {
						 d = d + 9;
						 if ((d + 1) % 8 != 0)
						 {
							 if (TB2[d]->Text == "white1" || TB2[d]->Text == "white")
							 {
								 a = 0;
							 }
							 else
							 {

								 if (TB2[d]->Text == "black" || TB2[d]->Text == "black1")
								 {
									 if (TB2[d + 9]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
										 a = 0;
									 }
									 else
									 {
										 a = 0;
									 }
								 }

							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 d = i;
					 a = 1;
					 while (d > 16 && d % 8 != 0 && a)
					 {
						 d = d - 9;
						 if (d % 8 != 0)
						 {
							 if (TB2[d]->Text == "white1" || TB2[d]->Text == "white")
							 {
								 a = 0;
							 }
							 else
							 {

								 if (TB2[d]->Text == "black" || TB2[d]->Text == "black1")
								 {
									 if (TB2[d - 9]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
										 a = 0;
									 }
									 else
									 {
										 a = 0;
									 }
								 }

							 }
						 }
					 }

				 }
				 /////////////////////////////////////////////
				 i = ((PictureBox^)sender)->TabIndex;
				 if (TB2[i]->Text == "black")
				 {
					 if ((i < 47) && (i % 8 != 0))
					 {
						 if ((i + 7) % 8 != 0)
						 {
							 if ((TB2[i + 7]->Text == "white") || (TB2[i + 7]->Text == "white1"))
							 {
								 if (TB2[i + 14]->Image == nullptr)
								 {
									 TB2[i]->TabStop = 1;
									 fight = 1;
								 }
							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 if (i > 16 && ((i + 1) % 8 != 0))
					 {
						 if ((TB2[i - 7]->Text == "white" || (TB2[i - 7]->Text == "white1")))
						 {
							 if ((i - 6) % 8 != 0)
							 {
								 if (TB2[i - 14]->Image == nullptr)
								 {
									 TB2[i]->TabStop = 1;
									 fight = 1;
								 }
							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 if ((i < 47) && ((i + 1) % 8 != 0))
					 {
						 if ((TB2[i + 9]->Text == "white") || (TB2[i + 9]->Text == "white1"))
						 {
							 if ((i + 10) % 8 != 0)
							 {
								 if (TB2[i + 18]->Image == nullptr)
								 {
									 TB2[i]->TabStop = 1;
									 fight = 1;
								 }
							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 if ((i > 16) && (i % 8 != 0))
					 {
						 if ((TB2[i - 9]->Text == "white") || (TB2[i - 9]->Text == "white1"))
						 {
							 if ((i - 9) % 8 != 0)
							 {
								 if (TB2[i - 18]->Image == nullptr)
								 {
									 TB2[i]->TabStop = 1;
									 fight = 1;
								 }
							 }
						 }
					 }
				 }
				 i = ((PictureBox^)sender)->TabIndex;
				 if (TB2[i]->Text == "black1")
				 {
					 int d = i;
					 int a = 1;
					 while (d < 47 && d % 8 != 0 && a)
					 {
						 d = d + 7;
						 if (d % 8 != 0)
						 {
							 if (TB2[d]->Text == "black1" || TB2[d]->Text == "black")
							 {
								 a = 0;
							 }
							 else
							 {
								 if (d % 8 != 0)
								 {
									 if (TB2[d]->Text == "white" || TB2[d]->Text == "white1")
									 {
										 if (TB2[d + 7]->Image == nullptr)
										 {
											 TB2[i]->TabStop = 1;
											 fight = 1;
											 a = 0;
										 }
										 else
										 {
											 a = 0;
										 }
									 }
								 }
							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 d = i;
					 a = 1;

					 while (d > 16 && (d + 1) % 8 != 0 && a)
					 {
						 d = d - 7;
						 if ((d + 1) % 8 != 0)
						 {
							 if (TB2[d]->Text == "black1" || TB2[d]->Text == "black")
							 {
								 a = 0;
							 }
							 else
							 {
								 if ((TB2[d]->Text == "white" || TB2[d]->Text == "white1"))
								 {
									 if (TB2[d - 7]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
										 a = 0;
									 }
									 else
									 {
										 a = 0;
									 }
								 }
							 }
						 }
						 else
						 {
							 a = 0;
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 d = i;
					 a = 1;
					 while (d < 47 && (d + 1) % 8 != 0 && a)
					 {
						 d = d + 9;
						 if ((d + 1) % 8 != 0)
						 {
							 if (TB2[d]->Text == "black1" || TB2[d]->Text == "black")
							 {
								 a = 0;
							 }
							 else
							 {

								 if (TB2[d]->Text == "white" || TB2[d]->Text == "white1")
								 {
									 if (TB2[d + 9]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
										 a = 0;
									 }
									 else
									 {
										 a = 0;
									 }
								 }

							 }
						 }
					 }
					 i = ((PictureBox^)sender)->TabIndex;
					 d = i;
					 a = 1;
					 while (d > 16 && d % 8 != 0 && a)
					 {
						 d = d - 9;
						 if (d % 8 != 0)
						 {
							 if (TB2[d]->Text == "black1" || TB2[d]->Text == "black")
							 {
								 a = 0;
							 }
							 else
							 {

								 if (TB2[d]->Text == "white" || TB2[d]->Text == "white1")
								 {
									 if (TB2[d - 9]->Image == nullptr)
									 {
										 TB2[i]->TabStop = 1;
										 fight = 1;
										 a = 0;
									 }
									 else
									 {
										 a = 0;
									 }
								 }

							 }
						 }
					 }

				 }

			 }
			 void firstclick(PictureBox^sender)
			 {
				 if (color == 1)
				 {
					 if (((PictureBox^)sender)->Text == "white")
					 {
						 if (fight == 1)
						 {
							 if (((PictureBox^)sender)->TabStop == 1)
							 {
								 lighting((PictureBox^)sender);
								 t = ((PictureBox^)sender);
								 now = 1;
							 }
						 }
						 else
						 {
							 if (((PictureBox^)sender)->TabIndex < 56)
							 {
								 if (((PictureBox^)sender)->TabIndex % 8 != 0)
								 {
									 if (TB2[((PictureBox^)sender)->TabIndex + 7]->Image == nullptr)
									 {
										 TB2[((PictureBox^)sender)->TabIndex + 7]->BackColor = System::Drawing::Color::Blue;
										 t = ((PictureBox^)sender);
										 now = 1;
									 }
								 }
								 if ((((PictureBox^)sender)->TabIndex + 1) % 8 != 0)
								 {
									 if (TB2[((PictureBox^)sender)->TabIndex + 9]->Image == nullptr)
									 {
										 TB2[((PictureBox^)sender)->TabIndex + 9]->BackColor = System::Drawing::Color::Blue;
										 t = ((PictureBox^)sender);
										 now = 1;
									 }
								 }
							 }
						 }
					 }
					 if (((PictureBox^)sender)->Text == "white1")
					 {
						 if (fight == 0)
						 {
							 lightingdamka(((PictureBox^)sender));
							 t = ((PictureBox^)sender);
							 now = 1;
						 }
						 else
						 {
							 lightingdamkacanfight(((PictureBox^)sender));
							 t = ((PictureBox^)sender);
							 now = 1;
						 }
					 }
				 }
				 else
				 {
					 if (((PictureBox^)sender)->Text == "black")
					 {
						 if (fight == 1)
						 {
							 if (((PictureBox^)sender)->TabStop == 1)
							 {
								 lighting((PictureBox^)sender);
								 t = ((PictureBox^)sender);
								 now = 1;
							 }

						 }
						 else
						 {
							 if (((PictureBox^)sender)->TabIndex > 7)
							 {
								 if (((PictureBox^)sender)->TabIndex % 8 != 0)
								 {
									 if (TB2[((PictureBox^)sender)->TabIndex - 9]->Image == nullptr)
									 {
										 TB2[((PictureBox^)sender)->TabIndex - 9]->BackColor = System::Drawing::Color::Blue;
										 t = ((PictureBox^)sender);
										 now = 1;
									 }
								 }
								 if ((((PictureBox^)sender)->TabIndex + 1) % 8 != 0)
								 {
									 if (TB2[((PictureBox^)sender)->TabIndex - 7]->Image == nullptr)
									 {
										 TB2[((PictureBox^)sender)->TabIndex - 7]->BackColor = System::Drawing::Color::Blue;
										 t = ((PictureBox^)sender);
										 now = 1;
									 }
								 }
							 }
						 }
					 }
					 if (((PictureBox^)sender)->Text == "black1")
					 {
						 if (fight == 0)
						 {
							 lightingdamka(((PictureBox^)sender));
							 t = ((PictureBox^)sender);
							 now = 1;
						 }
						 else
						 {
							 lightingdamkacanfight(((PictureBox^)sender));
							 t = ((PictureBox^)sender);
							 now = 1;
						 }
					 }
				 }
			 };

			 void secondclick(PictureBox^sender)
			 {
				 if (fight == 0)
				 {
					 if (((PictureBox^)sender)->Text == t->Text)
					 {
						 allgray();
						 firstclick((PictureBox^)sender);
					 }
					 if (((PictureBox^)sender)->BackColor == System::Drawing::Color::Blue)
					 {

						 if (((PictureBox^)sender)->Image == nullptr)
						 {

							 ((PictureBox^)sender)->Image = t->Image;
							 ((PictureBox^)sender)->Text = t->Text;
							 t->Image = nullptr;
							 t->Text = "";
							 now = 0;
							 color = color*(-1);
							 allgray();
							 if (color == 1)
							 {
								 if (((PictureBox^)sender)->TabIndex < 8)
								 {
									 ((PictureBox^)sender)->Text = "black1";
									 ((PictureBox^)sender)->Image = Image::FromFile("black111.png");
								 }
								 proverkanaboiwhite();
								 label1->Text = "Ход белых";
							 }
							 else
							 {
								 if (((PictureBox^)sender)->TabIndex > 55)
								 {
									 ((PictureBox^)sender)->Text = "white1";
									 ((PictureBox^)sender)->Image = Image::FromFile("white111.png");

								 }
								 proverkanaboiblack();
								 label1->Text = "Ход черных";
							 }
						 }
					 }
				 }

				 if (fight == 1)
				 {
					 if (((PictureBox^)sender)->Text == t->Text && ((PictureBox^)sender)->TabStop == 1)
					 {
						 allgray();
						 firstclick((PictureBox^)sender);
					 }
					 if (((PictureBox^)sender)->BackColor == System::Drawing::Color::Blue)
					 {

						 if (((PictureBox^)sender)->Image == nullptr)
						 {
							 ((PictureBox^)sender)->Image = t->Image;
							 ((PictureBox^)sender)->Text = t->Text;
							 t->Image = nullptr;
							 t->Text = "";

							 if (((PictureBox^)sender)->Text != "white1" && ((PictureBox^)sender)->Text != "black1")
							 {
								 TB2[t->TabIndex + (-t->TabIndex + ((PictureBox^)sender)->TabIndex) / 2]->Image = nullptr;
								 TB2[t->TabIndex + (-t->TabIndex + ((PictureBox^)sender)->TabIndex) / 2]->Text = "";
							 }
							 else
							 {
								 if ((((PictureBox^)sender)->TabIndex - t->TabIndex) % 7 == 0)
								 {
									 if (((PictureBox^)sender)->TabIndex - t->TabIndex > 0)
									 {
										 for (int i = t->TabIndex; i < ((PictureBox^)sender)->TabIndex; i = i + 7)
										 {
											 TB2[i]->Image = nullptr;
											 TB2[i]->Text = "";
										 }
									 }
									 if (((PictureBox^)sender)->TabIndex - t->TabIndex < 0)
									 {
										 for (int i = t->TabIndex; i >((PictureBox^)sender)->TabIndex; i = i - 7)
										 {
											 TB2[i]->Image = nullptr;
											 TB2[i]->Text = "";
										 }
									 }
								 }

								 if ((((PictureBox^)sender)->TabIndex - t->TabIndex) % 9 == 0)
								 {
									 if (((PictureBox^)sender)->TabIndex - t->TabIndex > 0)
									 {
										 for (int i = t->TabIndex; i < ((PictureBox^)sender)->TabIndex; i = i + 9)
										 {
											 TB2[i]->Image = nullptr;
											 TB2[i]->Text = "";
										 }
									 }
									 if (((PictureBox^)sender)->TabIndex - t->TabIndex < 0)
									 {
										 for (int i = t->TabIndex; i >((PictureBox^)sender)->TabIndex; i = i - 9)
										 {
											 TB2[i]->Image = nullptr;
											 TB2[i]->Text = "";
										 }
									 }
								 }
							 }
							 fight = 0;

							 if (color == 1)
							 {
								 if (((PictureBox^)sender)->TabIndex > 55)
								 {
									 ((PictureBox^)sender)->Text = "white1";
									 ((PictureBox^)sender)->Image = Image::FromFile("white111.png");

								 }
								 proverkanaboisender((PictureBox^)sender);
								 if (fight != 1)
								 {
									 if (((PictureBox^)sender)->TabIndex > 55)
									 {
										 ((PictureBox^)sender)->Text = "white1";
										 ((PictureBox^)sender)->Image = Image::FromFile("white111.png");

									 }
									 color = color*(-1);
									 now = 0;
									 allgray();
									 fight0();
									 proverkanaboiblack();
									 label1->Text = "Ход черных";
								 }
								 else
								 {
									 if (((PictureBox^)sender)->TabIndex > 55)
									 {
										 ((PictureBox^)sender)->Text = "white1";
										 ((PictureBox^)sender)->Image = Image::FromFile("white111.png");

									 }
									 t = ((PictureBox^)sender);
									 allgray();
									 fight0();
									 t->TabStop = 1;
									 if (((PictureBox^)sender)->Text == "white1")
									 {
										 lightingdamkacanfight(t);
									 }
									 else
									 {
										 lighting(t);
									 }
								 }
							 }
							 else
							 {
								 if (((PictureBox^)sender)->TabIndex > 55)
								 {
									 ((PictureBox^)sender)->Text = "black1";
									 ((PictureBox^)sender)->Image = Image::FromFile("black111.png");

								 }
								 proverkanaboisender((PictureBox^)sender);
								 if (fight != 1)
								 {
									 if (((PictureBox^)sender)->TabIndex < 8)
									 {
										 ((PictureBox^)sender)->Text = "black1";
										 ((PictureBox^)sender)->Image = Image::FromFile("black111.png");
									 }
									 color = color*(-1);
									 now = 0;
									 allgray();
									 fight0();
									 proverkanaboiwhite();
									 label1->Text = "Ход белых";
								 }
								 else
								 {
									 if (((PictureBox^)sender)->TabIndex < 8)
									 {
										 ((PictureBox^)sender)->Text = "black1";
										 ((PictureBox^)sender)->Image = Image::FromFile("black111.png");
									 }
									 t = ((PictureBox^)sender);
									 allgray();
									 fight0();
									 t->TabStop = 1;
									 if (((PictureBox^)sender)->Text == "black1")
									 {
										 lightingdamkacanfight(t);
									 }
									 else
									 {
										 lighting(t);
									 }
								 }
							 }
						 }
					 }
				 }
				 theend();
			 }

	private: System::Void pictureBox2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (now == 0)
		{
			firstclick((PictureBox^)sender);
		}
		else
		{
			secondclick((PictureBox^)sender);
		}
	}
	};
}