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
	/// —водка дл€ MyForm 
	/// </summary> 
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// 
			//TODO: добавьте код конструктора 
			// 
		}

	protected:
		/// <summary> 
		/// ќсвободить все используемые ресурсы. 
		/// </summary> 
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ button2;




	private:

	protected:

	protected:

	private:
		/// <summary> 
		/// ќб€зательна€ переменна€ конструктора. 
		/// </summary> 
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code 
		/// <summary> 
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода. 
		/// </summary> 
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(169, 509);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 30);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(684, 561);
			this->Controls->Add(this->button2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MyForm";
			this->Text = L"шашки шашечки";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion 
		array<PictureBox^>^ TB2 = gcnew array<PictureBox^>(64);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int a = 0;

		for (int i = 0; i < 8; i++)//строки
		{
			for (int j = 0; j < 8; j++)//столбцы
			{
				TB2[a] = gcnew PictureBox();
				this->Controls->Add(TB2[a]);
				if (i % 2 == 0)//если строка чет
				{
					if (j % 2 == 0)//если столбец чет
					{
						TB2[a]->BackColor = System::Drawing::Color::White;
					}
					else
					{
						TB2[a]->BackColor = System::Drawing::Color::DarkGray;
					}
				}
				else//если строка нечет
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
				TB2[a]->TabIndex = a; //номера клеток 
				TB2[a]->TabStop = false;
				TB2[a]->Location = Point(5 + j * 55, 5 + i * 55);
				TB2[a]->SizeMode = PictureBoxSizeMode::StretchImage;
				TB2[a]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseClick);
				if (TB2[a]->BackColor == System::Drawing::Color::DarkGray)
				{
					if (i < 3)
					{
						TB2[a]->Image = Image::FromFile("C:/Users/user/Desktop/images/white1.png");
						TB2[a]->Text = "white";
					}
					if (i > 4)
					{
						TB2[a]->Image = Image::FromFile("C:/Users/user/Desktop/images/black1.png");
						TB2[a]->Text = "black";
					}

				}
				a++;
			}
		}
		//proverkanaboi();
	}
	int now = 0, color = 1, fight = 0;//fight(podboem)
	PictureBox^ t = nullptr;
	void allgray()
	{
		for (int i = 0; i < 64; i++)
		{
			if (TB2[i] -> BackColor == System::Drawing::Color::Blue)
			{
				TB2[i]->BackColor = System::Drawing::Color::DarkGray;
			}
		}
	}
	
	void lighting(PictureBox^sender)
	{
		if (((PictureBox^)sender)->Text == "white")
		{
			if (((PictureBox^)sender)->TabIndex + 14 <= 63)
			{
				if ((TB2[((PictureBox^)sender)->TabIndex + 7]->Text == "black"))
				{
					if (TB2[((PictureBox^)sender)->TabIndex + 14]->Image == nullptr)
					{

						TB2[((PictureBox^)sender)->TabIndex + 14]->BackColor = System::Drawing::Color::Blue;

					}

				}
			}

			if (((PictureBox^)sender)->TabIndex - 14 >= 0)
			{
				if ((TB2[((PictureBox^)sender)->TabIndex - 7]->Text == "black"))
				{
					if (TB2[((PictureBox^)sender)->TabIndex - 14]->Image == nullptr)
					{
						TB2[((PictureBox^)sender)->TabIndex - 14]->BackColor = System::Drawing::Color::Blue;


					}

				}
			}
			if (((PictureBox^)sender)->TabIndex + 18 <= 63)
			{
				if ((TB2[((PictureBox^)sender)->TabIndex + 9]->Text == "black"))
				{

					if (TB2[((PictureBox^)sender)->TabIndex + 18]->Image == nullptr)
					{

						TB2[((PictureBox^)sender)->TabIndex + 18]->BackColor = System::Drawing::Color::Blue;

					}

				}
			}
			if (((PictureBox^)sender)->TabIndex - 18 >= 0)
			{
				if ((TB2[((PictureBox^)sender)->TabIndex - 9]->Text == "black"))
				{

					if (TB2[((PictureBox^)sender)->TabIndex - 18]->Image == nullptr)
					{
						TB2[((PictureBox^)sender)->TabIndex - 18]->BackColor = System::Drawing::Color::Blue;

					}

				}
			}
		}
		
		if (((PictureBox^)sender)->Text == "black")
		{
			if (((PictureBox^)sender)->TabIndex + 14 <= 63)
			{
				if ((TB2[((PictureBox^)sender)->TabIndex + 7]->Text == "black"))
				{
					if (TB2[((PictureBox^)sender)->TabIndex + 14]->Image == nullptr)
					{

						TB2[((PictureBox^)sender)->TabIndex + 14]->BackColor = System::Drawing::Color::Blue;

					}

				}
			}

			if (((PictureBox^)sender)->TabIndex - 14 >= 0)
			{
				if ((TB2[((PictureBox^)sender)->TabIndex - 7]->Text == "black"))
				{
					if (TB2[((PictureBox^)sender)->TabIndex - 14]->Image == nullptr)
					{
						TB2[((PictureBox^)sender)->TabIndex - 14]->BackColor = System::Drawing::Color::Blue;


					}

				}
			}
			if (((PictureBox^)sender)->TabIndex + 18 <= 63)
			{
				if ((TB2[((PictureBox^)sender)->TabIndex + 9]->Text == "black"))
				{

					if (TB2[((PictureBox^)sender)->TabIndex + 18]->Image == nullptr)
					{

						TB2[((PictureBox^)sender)->TabIndex + 18]->BackColor = System::Drawing::Color::Blue;

					}

				}
			}
			if (((PictureBox^)sender)->TabIndex - 18 >= 0)
			{
				if ((TB2[((PictureBox^)sender)->TabIndex - 9]->Text == "black"))
				{

					if (TB2[((PictureBox^)sender)->TabIndex - 18]->Image == nullptr)
					{
						TB2[((PictureBox^)sender)->TabIndex - 18]->BackColor = System::Drawing::Color::Blue;

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
						if ((TB2[i + 7]->Text == "white"))
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
					if ((TB2[i - 7]->Text == "white"))
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
					if ((TB2[i + 9]->Text == "white"))
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
					if ((TB2[i - 9]->Text == "white"))
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
						if ((TB2[i + 7]->Text == "black"))
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
					if ((TB2[i - 7]->Text == "black"))
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
					if ((TB2[i + 9]->Text == "black"))
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
					if ((TB2[i - 9]->Text == "black"))
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
		}
	}
	/*void proverkanaboi()
	{
		for (int i = 0; i < 64; i++)
		{
			if (TB2[i]->Text == "white")
			{
				if (i + 14 <= 63)
				{
					if ((TB2[i + 7]->Text == "black"))
					{
						if (TB2[i + 14]->Image == nullptr)
						{
							TB2[i]->TabStop = 1;
							fight = 1;

						}

					}
				}
				
				if (i - 14 >= 0)
				{
					if ((TB2[i - 7]->Text == "black"))
					{
						if (TB2[i - 14]->Image == nullptr)
						{
							TB2[i]->TabStop = 1;
							fight = 1;
						}

					}
				}
				if (i + 18 <= 63)
				{
					if ((TB2[i + 9]->Text == "black"))
					{

						if (TB2[i + 18]->Image == nullptr)
						{
							TB2[i]->TabStop = 1;
							fight = 1;
						}

					}
				}
				if (i - 18 >= 0)
				{
					if ((TB2[i - 9]->Text == "black"))
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
	}*/
	void firstclick(PictureBox^sender)
	{
		if (color == 1) //перебираем весь мссив пикч ищем белые слева или справа от кот стоит черн если эт о так то вызываем функцию 
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
		}

	};
	/*void secondclick(PictureBox^sender)
	{
		if (fight == 0)
		{
			if (((PictureBox^)sender)->Text == t->Text)
			{
				TB2[t->TabIndex + 7]->BackColor = System::Drawing::Color::DarkGray;
				TB2[t->TabIndex - 7]->BackColor = System::Drawing::Color::DarkGray;
				TB2[t->TabIndex + 9]->BackColor = System::Drawing::Color::DarkGray;
				TB2[t->TabIndex - 9]->BackColor = System::Drawing::Color::DarkGray;
				firstclick((PictureBox^)sender);
			}
			if (((PictureBox^)sender)->BackColor == System::Drawing::Color::Blue)
			{

				if (((PictureBox^)sender)->Image == nullptr)
				{
					//if(t->Text == ((PictureBox^)sender)->Text)
					((PictureBox^)sender)->Image = t->Image;
					((PictureBox^)sender)->Text = t->Text;
					t->Image = nullptr;
					t->Text = "";
					now = 0;

					TB2[t->TabIndex + 7]->BackColor = System::Drawing::Color::DarkGray;
					TB2[t->TabIndex - 7]->BackColor = System::Drawing::Color::DarkGray;
					TB2[t->TabIndex + 9]->BackColor = System::Drawing::Color::DarkGray;
			//		TB2[t->TabIndex - 9]->BackColor = System::Drawing::Color::DarkGray;
					color = color*(-1);
				}
			}
		}
		if (fight == 1)
		{
			if (((PictureBox^)sender)->BackColor == System::Drawing::Color::Blue)
			{

				if (((PictureBox^)sender)->Image == nullptr)
				{
					//if(t->Text == ((PictureBox^)sender)->Text)
					((PictureBox^)sender)->Image = t->Image;
					((PictureBox^)sender)->Text = t->Text;
					t->Image = nullptr;
					t->Text = "";
					
					TB2[t->TabIndex + (-t->TabIndex + ((PictureBox^)sender)->TabIndex) / 2]->Image = nullptr;
					TB2[t->TabIndex + (-t->TabIndex + ((PictureBox^)sender)->TabIndex) / 2]->Text = "";
				//	TB2[t->TabIndex + 14]->BackColor = System::Drawing::Color::DarkGray;
				//	TB2[t->TabIndex - 14]->BackColor = System::Drawing::Color::DarkGray;
				//  TB2[t->TabIndex + 18]->BackColor = System::Drawing::Color::DarkGray;
				//	TB2[t->TabIndex - 18]->BackColor = System::Drawing::Color::DarkGray;
					fight = 0;
					proverkanaboi();
					if (fight != 1)
					{
						color = color*(-1);
						now = 0;
					}
					else
					{
						t = ((PictureBox^)sender);
						lighting(t);
					}
				}
			}
		}
		fight = 0;
		proverkanaboi();
		
	}*/
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
						proverkanaboiwhite();
					}
					else
					{
						proverkanaboiblack();
					}
				}
			}
		}

		if (fight == 1)
		{
			if (((PictureBox^)sender)->BackColor == System::Drawing::Color::Blue)
			{

				if (((PictureBox^)sender)->Image == nullptr)
				{
					((PictureBox^)sender)->Image = t->Image;
					((PictureBox^)sender)->Text = t->Text;
					t->Image = nullptr;
					t->Text = "";

					TB2[t->TabIndex + (-t->TabIndex + ((PictureBox^)sender)->TabIndex) / 2]->Image = nullptr;
					TB2[t->TabIndex + (-t->TabIndex + ((PictureBox^)sender)->TabIndex) / 2]->Text = "";
					fight = 0;

					if (color == 1)
					{
						proverkanaboiwhite();
						if (fight != 1)
						{
							color = color*(-1);
							now = 0;
							allgray();
							proverkanaboiblack();
						}
						else
						{
							t = ((PictureBox^)sender);
							t->BackColor = System::Drawing::Color::DarkGray;
							lighting(t);
						}
					}
					else
					{
						proverkanaboiblack();
						if (fight != 1)
						{
							color = color*(-1);
							now = 0;
							allgray();
							proverkanaboiwhite();
						}
						else
						{
							t = ((PictureBox^)sender);
							t->BackColor = System::Drawing::Color::DarkGray;
							lighting(t);
						}
					}
				}
			}
		}
	}
	private: System::Void pictureBox2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (now == 0)//кликов не было совершено
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