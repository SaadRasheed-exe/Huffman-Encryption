#pragma once
#include "huffman.h"
#include <Windows.h>
#include <string>

namespace ProjectDS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	using namespace System::IO;
	using namespace::System::Text;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
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
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ Encrypt;
	private: System::Windows::Forms::Button^ Decrypt;
	private: System::Windows::Forms::Button^ Clear;
	private: System::Windows::Forms::Button^ Browse;
	private: System::Windows::Forms::Button^ save;

	private:
		huffmanCompression* obj;
		String^ Fname;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


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
		void MarshalString(String^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->Encrypt = (gcnew System::Windows::Forms::Button());
			this->Decrypt = (gcnew System::Windows::Forms::Button());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->Browse = (gcnew System::Windows::Forms::Button());
			this->save = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Info;
			this->richTextBox1->Location = System::Drawing::Point(365, 56);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(637, 110);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->richTextBox2->Location = System::Drawing::Point(12, 325);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(282, 61);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			this->richTextBox2->UseWaitCursor = true;
			// 
			// Encrypt
			// 
			this->Encrypt->BackColor = System::Drawing::Color::Khaki;
			this->Encrypt->Location = System::Drawing::Point(355, 392);
			this->Encrypt->Name = L"Encrypt";
			this->Encrypt->Size = System::Drawing::Size(140, 37);
			this->Encrypt->TabIndex = 2;
			this->Encrypt->Text = L"Encrypt";
			this->Encrypt->UseVisualStyleBackColor = false;
			this->Encrypt->Click += gcnew System::EventHandler(this, &MyForm::Encrypt_Click);
			// 
			// Decrypt
			// 
			this->Decrypt->BackColor = System::Drawing::Color::Khaki;
			this->Decrypt->Location = System::Drawing::Point(530, 392);
			this->Decrypt->Name = L"Decrypt";
			this->Decrypt->Size = System::Drawing::Size(140, 37);
			this->Decrypt->TabIndex = 3;
			this->Decrypt->Text = L"Decrypt";
			this->Decrypt->UseVisualStyleBackColor = false;
			this->Decrypt->Click += gcnew System::EventHandler(this, &MyForm::Decrypt_Click);
			// 
			// Clear
			// 
			this->Clear->BackColor = System::Drawing::Color::Khaki;
			this->Clear->Location = System::Drawing::Point(872, 392);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(140, 37);
			this->Clear->TabIndex = 4;
			this->Clear->Text = L"Clear";
			this->Clear->UseVisualStyleBackColor = false;
			this->Clear->Click += gcnew System::EventHandler(this, &MyForm::Clear_Click);
			// 
			// Browse
			// 
			this->Browse->BackColor = System::Drawing::Color::LightSkyBlue;
			this->Browse->Location = System::Drawing::Point(89, 392);
			this->Browse->Name = L"Browse";
			this->Browse->Size = System::Drawing::Size(140, 37);
			this->Browse->TabIndex = 5;
			this->Browse->Text = L"Browse";
			this->Browse->UseVisualStyleBackColor = false;
			this->Browse->Click += gcnew System::EventHandler(this, &MyForm::Browse_Click);
			// 
			// save
			// 
			this->save->BackColor = System::Drawing::Color::Khaki;
			this->save->Location = System::Drawing::Point(703, 392);
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(140, 37);
			this->save->TabIndex = 6;
			this->save->Text = L"Save to File";
			this->save->UseVisualStyleBackColor = false;
			this->save->Click += gcnew System::EventHandler(this, &MyForm::save_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::SystemColors::Info;
			this->richTextBox3->Location = System::Drawing::Point(355, 233);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(657, 113);
			this->richTextBox3->TabIndex = 7;
			this->richTextBox3->Text = L"";
			this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox3_TextChanged);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->richTextBox1);
			this->panel1->Controls->Add(this->Encrypt);
			this->panel1->Controls->Add(this->Decrypt);
			this->panel1->Controls->Add(this->save);
			this->panel1->Controls->Add(this->richTextBox3);
			this->panel1->Controls->Add(this->Clear);
			this->panel1->Controls->Add(this->richTextBox2);
			this->panel1->Controls->Add(this->Browse);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1033, 475);
			this->panel1->TabIndex = 8;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::RoyalBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 298);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(173, 24);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Upload a File";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Coral;
			this->label2->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(361, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(186, 24);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Original Text:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Coral;
			this->label1->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(361, 206);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(361, 24);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Encrypted / Decrypted Text:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1034, 477);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
		void ReadFileToTextBox(System::String^ filepath)
		{
			System::String^ text = System::IO::File::ReadAllText(filepath);
			richTextBox1->Text = text;
		}
		void WriteFileFromTextBox(System::String^ data)
		{
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
			saveFileDialog1->DefaultExt = "txt";
			saveFileDialog1->ShowDialog();
			System::String^ path = saveFileDialog1->FileName;
			System::IO::File::WriteAllText(path, data);

		}
#pragma endregion
	
private: System::Void Encrypt_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string data;
	MarshalString(richTextBox1->Text, data);
	std::string comp = obj->compressString(data);
	richTextBox3->Text = gcnew String(comp.c_str());
	
}
private: System::Void Browse_Click(System::Object^ sender, System::EventArgs^ e) {

	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	openFileDialog1->InitialDirectory = "C:\\Users\\HP\\source\\repos\\dsGUI";
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;


	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//richTextBox1->LoadFile(openFileDialog1->FileName, RichTextBoxStreamType::PlainText);
		//Fname = openFileDialog1->FileName;
		richTextBox2->Text = openFileDialog1->FileName;
		ReadFileToTextBox(openFileDialog1->FileName);
	}
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void Clear_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox1->Text = " ";
	richTextBox2->Text = " ";
	richTextBox3->Text = " ";
}
private: System::Void Decrypt_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string data;
	MarshalString(richTextBox1->Text, data);
	

	std::string decomp = obj->decompressString(data);
	richTextBox3->Text = gcnew String(decomp.c_str());

	//MessageBox::Show("Text is not Encrypted yet!");

}
private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void save_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
	saveFileDialog1->DefaultExt = "txt";
	saveFileDialog1->ShowDialog();
	System::String^ path = saveFileDialog1->FileName;
	System::String^ data = richTextBox3->Text;
	System::IO::File::WriteAllText(path, data);
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
