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
	}
			 int current = 1;//1 белые -1 черные
			 int now = 0;//1 клик
			 int push = 0;//ничего не делает как и €
			 int left = 1, right = 1;//диагонали слева и справа от шашки
			 PictureBox^ t = nullptr;//пустой пикчербокс
			 void podsvetkarightwhite(PictureBox^ sender)
			 {
				
			 }
			 void podsvetkaleftwhite(PictureBox^ sender)
			 {

			 }
			/* void leftdown(PictureBox^ sender)
			 {
				 if (((PictureBox^)sender)->Text != (TB2[left = ((PictureBox^)sender)->TabIndex + 7]->Text))//шашка сбоку др цвета слева и снизу
				 {
					 if (TB2[left + 7]->Image == nullptr)
					 {
						 TB2[left = left + 7]->BackColor = System::Drawing::Color::Blue;
						 if (left +7 < 63)//чтобы он не выходил за пределы массива 58+7
						 {
							 if (TB2[left + 7]->Image != nullptr)
							 {
								 leftdown(TB2[left]);
							 }
						 }

					 }

				 }
				 if (((PictureBox^)sender)->Text != (TB2[right = ((PictureBox^)sender)->TabIndex + 9]->Text))//шашка сбоку др цвета слева и снизу
				 {
					 if (TB2[right + 9]->Image == nullptr)
					 {
						 TB2[right = right + 9]->BackColor = System::Drawing::Color::Blue;
						 if (right + 9 < 63)//чтобы он не выходил за пределы массива 58+7
						 {
							 if (TB2[right + 9]->Image != nullptr)
							 {
								 leftdown(TB2[left]);
							 }
						 }

					 }
				 }
			 }*/
			 /*void rightdown(PictureBox^ sender)
			 {
				 if (((PictureBox^)sender)->Text != (TB2[right = ((PictureBox^)sender)->TabIndex + 9]->Text))//шашка сбоку др цвета слева и снизу
				 {
					 if (TB2[right + 9]->Image == nullptr)
					 {
						 TB2[right = right + 9]->BackColor = System::Drawing::Color::Blue;
						 if (right != 58)//чтобы он не выходил за пределы массива 58+7
						 {
							 if (TB2[right + 9]->Image != nullptr)
							 {
								 rightdown(TB2[left]);
							 }
						 }

					 }
				 }
			 }*/
			 void firstclick(PictureBox^ sender)
			 {
				 if (((PictureBox^)sender)->Image != nullptr)//пустой пикч
				 {
					 if (current == 1)//проверка на то что сейчас должны ходить белые
					 {
						 if (((PictureBox^)sender)->Text == "white")
						 {
							 if (((PictureBox^)sender)->TabIndex % 8 != 0)//индекс кратен 8(слева)
							 {
								 if (TB2[left = ((PictureBox^)sender)->TabIndex + 7]->Image != nullptr)
								 {
									 //rightdown((PictureBox^)sender);
								 }
								 if (TB2[left = ((PictureBox^)sender)->TabIndex + 7]->Image == nullptr)
								 {
									 TB2[left = ((PictureBox^)sender)->TabIndex + 7]->BackColor = System::Drawing::Color::Blue;//подсветочка							
									 t = ((PictureBox^)sender);//в пустой пикч заносим тот на кот нажали
									 now = 1;//был совершен 1 клик
								 }
							 }
							 if ((((PictureBox^)sender)->TabIndex + 1) % 8 != 0)//индекс кратен 7(справа)
							 {
								 if (TB2[right = ((PictureBox^)sender)->TabIndex + 9]->Image == nullptr)
								 {
									 TB2[right = ((PictureBox^)sender)->TabIndex + 9]->BackColor = System::Drawing::Color::Blue;
									 t = ((PictureBox^)sender);//в пустой пикч заносим тот на кот нажали
									 now = 1;//был совершен 1 клик
								 }
							 }
						 }
					 }
					 else
					 {
						 if (((PictureBox^)sender)->Text == "black")
						 {
							 if ((((PictureBox^)sender)->TabIndex + 1 ) % 8 != 0)//индекс кратен 8(слева)
							 {
								 if (TB2[left = ((PictureBox^)sender)->TabIndex - 7]->Image == nullptr)
								 {
									 TB2[left = ((PictureBox^)sender)->TabIndex - 7]->BackColor = System::Drawing::Color::Blue;//подсветочка							
									 t = ((PictureBox^)sender);//в пустой пикч заносим тот на кот нажали
									 now = 1;//был совершен 1 клик
								 }
							 }
							 if (((PictureBox^)sender)->TabIndex % 8 != 0)//индекс кратен 7(справа)
							 {
								 if (TB2[right = ((PictureBox^)sender)->TabIndex - 9]->Image == nullptr)
								 {
									 TB2[right = ((PictureBox^)sender)->TabIndex - 9]->BackColor = System::Drawing::Color::Blue;
									 t = ((PictureBox^)sender);//в пустой пикч заносим тот на кот нажали
									 now = 1;//был совершен 1 клик
								 }
							 }
						 }
					 }
				 }
			 }

			 void secondclick(PictureBox^ sender)
			 {
				 if (((PictureBox^)sender)->Text == t->Text) //сравнение цветов
				 {
					 TB2[left]->BackColor = System::Drawing::Color::DarkGray;//делаем обратно синие серыми левые
					 TB2[right]->BackColor = System::Drawing::Color::DarkGray;//правые
					 firstclick((PictureBox^)sender);
				 }
				 if (((PictureBox^)sender)->BackColor == System::Drawing::Color::Blue)//если текущ пикч синий то мы возможно можем сюда походить наверное александр игоревич но это не точно
				 {
					 		 
					 if (((PictureBox^)sender)->Image == nullptr)//если на текущ пикч нет картинки 
					 {
						 //if(t->Text == ((PictureBox^)sender)->Text)
						 ((PictureBox^)sender)->Image = t->Image;//передаем на него картинку 
						 ((PictureBox^)sender)->Text = t->Text;//и передаем текст(цвет шашки)
						 t->Image = nullptr;//обнул€ем картинку
						 t->Text = "";//обнул€ем текст
						 now = 0;//обнул€ем клик

						 TB2[left]->BackColor = System::Drawing::Color::DarkGray;//делаем обратно синие серыми левые
						 TB2[right]->BackColor = System::Drawing::Color::DarkGray;//правые
						 current = current*(-1);//мен€етс€ ход
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