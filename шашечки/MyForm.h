#pragma once 

namespace ������� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	/// <summary> 
	/// ������ ��� MyForm 
	/// </summary> 
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// 
			//TODO: �������� ��� ������������ 
			// 
		}

	protected:
		/// <summary> 
		/// ���������� ��� ������������ �������. 
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
		/// ������������ ���������� ������������. 
		/// </summary> 
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code 
		/// <summary> 
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����. 
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
			this->Text = L"����� �������";
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

		for (int i = 0; i < 8; i++)//������
		{
			for (int j = 0; j < 8; j++)//�������
			{
				TB2[a] = gcnew PictureBox();
				this->Controls->Add(TB2[a]);
				if (i % 2 == 0)//���� ������ ���
				{
					if (j % 2 == 0)//���� ������� ���
					{
						TB2[a]->BackColor = System::Drawing::Color::White;
					}
					else
					{
						TB2[a]->BackColor = System::Drawing::Color::DarkGray;
					}
				}
				else//���� ������ �����
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
				TB2[a]->TabIndex = a; //������ ������ 
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
			 int current = 1;//1 ����� -1 ������
			 int now = 0;//1 ����
			 int push = 0;//������ �� ������ ��� � �
			 int left = 1, right = 1;//��������� ����� � ������ �� �����
			 PictureBox^ t = nullptr;//������ ����������
			 void podsvetkarightwhite(PictureBox^ sender)
			 {
				
			 }
			 void podsvetkaleftwhite(PictureBox^ sender)
			 {

			 }
			/* void leftdown(PictureBox^ sender)
			 {
				 if (((PictureBox^)sender)->Text != (TB2[left = ((PictureBox^)sender)->TabIndex + 7]->Text))//����� ����� �� ����� ����� � �����
				 {
					 if (TB2[left + 7]->Image == nullptr)
					 {
						 TB2[left = left + 7]->BackColor = System::Drawing::Color::Blue;
						 if (left +7 < 63)//����� �� �� ������� �� ������� ������� 58+7
						 {
							 if (TB2[left + 7]->Image != nullptr)
							 {
								 leftdown(TB2[left]);
							 }
						 }

					 }

				 }
				 if (((PictureBox^)sender)->Text != (TB2[right = ((PictureBox^)sender)->TabIndex + 9]->Text))//����� ����� �� ����� ����� � �����
				 {
					 if (TB2[right + 9]->Image == nullptr)
					 {
						 TB2[right = right + 9]->BackColor = System::Drawing::Color::Blue;
						 if (right + 9 < 63)//����� �� �� ������� �� ������� ������� 58+7
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
				 if (((PictureBox^)sender)->Text != (TB2[right = ((PictureBox^)sender)->TabIndex + 9]->Text))//����� ����� �� ����� ����� � �����
				 {
					 if (TB2[right + 9]->Image == nullptr)
					 {
						 TB2[right = right + 9]->BackColor = System::Drawing::Color::Blue;
						 if (right != 58)//����� �� �� ������� �� ������� ������� 58+7
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
				 if (((PictureBox^)sender)->Image != nullptr)//������ ����
				 {
					 if (current == 1)//�������� �� �� ��� ������ ������ ������ �����
					 {
						 if (((PictureBox^)sender)->Text == "white")
						 {
							 if (((PictureBox^)sender)->TabIndex % 8 != 0)//������ ������ 8(�����)
							 {
								 if (TB2[left = ((PictureBox^)sender)->TabIndex + 7]->Image != nullptr)
								 {
									 //rightdown((PictureBox^)sender);
								 }
								 if (TB2[left = ((PictureBox^)sender)->TabIndex + 7]->Image == nullptr)
								 {
									 TB2[left = ((PictureBox^)sender)->TabIndex + 7]->BackColor = System::Drawing::Color::Blue;//�����������							
									 t = ((PictureBox^)sender);//� ������ ���� ������� ��� �� ��� ������
									 now = 1;//��� �������� 1 ����
								 }
							 }
							 if ((((PictureBox^)sender)->TabIndex + 1) % 8 != 0)//������ ������ 7(������)
							 {
								 if (TB2[right = ((PictureBox^)sender)->TabIndex + 9]->Image == nullptr)
								 {
									 TB2[right = ((PictureBox^)sender)->TabIndex + 9]->BackColor = System::Drawing::Color::Blue;
									 t = ((PictureBox^)sender);//� ������ ���� ������� ��� �� ��� ������
									 now = 1;//��� �������� 1 ����
								 }
							 }
						 }
					 }
					 else
					 {
						 if (((PictureBox^)sender)->Text == "black")
						 {
							 if ((((PictureBox^)sender)->TabIndex + 1 ) % 8 != 0)//������ ������ 8(�����)
							 {
								 if (TB2[left = ((PictureBox^)sender)->TabIndex - 7]->Image == nullptr)
								 {
									 TB2[left = ((PictureBox^)sender)->TabIndex - 7]->BackColor = System::Drawing::Color::Blue;//�����������							
									 t = ((PictureBox^)sender);//� ������ ���� ������� ��� �� ��� ������
									 now = 1;//��� �������� 1 ����
								 }
							 }
							 if (((PictureBox^)sender)->TabIndex % 8 != 0)//������ ������ 7(������)
							 {
								 if (TB2[right = ((PictureBox^)sender)->TabIndex - 9]->Image == nullptr)
								 {
									 TB2[right = ((PictureBox^)sender)->TabIndex - 9]->BackColor = System::Drawing::Color::Blue;
									 t = ((PictureBox^)sender);//� ������ ���� ������� ��� �� ��� ������
									 now = 1;//��� �������� 1 ����
								 }
							 }
						 }
					 }
				 }
			 }

			 void secondclick(PictureBox^ sender)
			 {
				 if (((PictureBox^)sender)->Text == t->Text) //��������� ������
				 {
					 TB2[left]->BackColor = System::Drawing::Color::DarkGray;//������ ������� ����� ������ �����
					 TB2[right]->BackColor = System::Drawing::Color::DarkGray;//������
					 firstclick((PictureBox^)sender);
				 }
				 if (((PictureBox^)sender)->BackColor == System::Drawing::Color::Blue)//���� ����� ���� ����� �� �� �������� ����� ���� �������� �������� ��������� �������� �� ��� �� �����
				 {
					 		 
					 if (((PictureBox^)sender)->Image == nullptr)//���� �� ����� ���� ��� �������� 
					 {
						 //if(t->Text == ((PictureBox^)sender)->Text)
						 ((PictureBox^)sender)->Image = t->Image;//�������� �� ���� �������� 
						 ((PictureBox^)sender)->Text = t->Text;//� �������� �����(���� �����)
						 t->Image = nullptr;//�������� ��������
						 t->Text = "";//�������� �����
						 now = 0;//�������� ����

						 TB2[left]->BackColor = System::Drawing::Color::DarkGray;//������ ������� ����� ������ �����
						 TB2[right]->BackColor = System::Drawing::Color::DarkGray;//������
						 current = current*(-1);//�������� ���
					 }
				 }
			 }
	private: System::Void pictureBox2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (now == 0)//������ �� ���� ���������
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