#pragma once

#include <iostream>
#include <msclr\marshal_cppstd.h>

#include "Generator.h"

namespace DataGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace std;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	/// <summary>
	/// Class constructor.
	/// </summary>
	public: MainForm(void);

	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	protected: ~MainForm();

	private: String^ fileName;

	private: string* path;

	private: string* pattern;

	private: unsigned int system;

	private: MAGNITUDE magnitude;

	private: double size;

	private: DATATYPE datatype;

	private: unsigned long long bufferSize;

	private: unsigned long long numberOfFiles;

	private: int suffix;

	private: Generator generator;

	private: int second;

	private: int minute;

	private: int hour;

	private: string stdString_to_systemString(String^ source);

	private: string* stdString_to_systemPointerString(String^ source);

#pragma region Windows components generated code
	private: System::Windows::Forms::Label^  lbl_suffix;
	private: System::Windows::Forms::ComboBox^  comboBox_suffix;
	private: System::Windows::Forms::Button^  btn_cancel;
	private: System::Windows::Forms::Label^  lbl_elapsedTime;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::PictureBox^  img_dataType;
	private: System::Windows::Forms::ToolTip^  toolTip;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker;
	private: System::Windows::Forms::Label^  lbl_CreatingFile;
	private: System::Windows::Forms::ProgressBar^  progressBar;
	private: System::Windows::Forms::Label^  lbl_bufferSize;
	private: System::Windows::Forms::Panel^  panel_bufferSize;
	private: System::Windows::Forms::RadioButton^  rdb_4MB;
	private: System::Windows::Forms::RadioButton^  rdb_256KB;
	private: System::Windows::Forms::RadioButton^  rdb_1MB;
	private: System::Windows::Forms::RadioButton^  rdb_64KB;
	private: System::Windows::Forms::RadioButton^  rdb_1KB;
	private: System::Windows::Forms::RadioButton^  rdb_8KB;
	private: System::Windows::Forms::Button^  btn_generate;
	private: System::Windows::Forms::Label^  lbl_fileName;
	private: System::Windows::Forms::Label^  lbl_fileExtension;
	private: System::Windows::Forms::RadioButton^  rdb_randomData;
	private: System::Windows::Forms::RadioButton^  rdb_repetitionStrings;
	private: System::Windows::Forms::Label^  lbl_repeatProcess;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown;
	private: System::Windows::Forms::Label^  lbl_typeData;
	private: System::Windows::Forms::TextBox^  txb_fileName;
	private: System::Windows::Forms::TextBox^  txb_fileExtension;
	private: System::Windows::Forms::TextBox^  txb_repetitionString;
	private: System::Windows::Forms::Label^  lbl_fileSize;
	private: System::Windows::Forms::TextBox^  txb_fileSize;
	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::Label^  lbl_numericSystem;
	private: System::Windows::Forms::Panel^  panel_numericSystem;
	private: System::Windows::Forms::RadioButton^  rdb_binary;
	private: System::Windows::Forms::RadioButton^  rdb_metric;
	private: System::Windows::Forms::RadioButton^  rdb_repetitionHexadecimal;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;
	private: System::ComponentModel::IContainer^  components;

#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btn_generate = (gcnew System::Windows::Forms::Button());
			this->lbl_fileName = (gcnew System::Windows::Forms::Label());
			this->lbl_fileExtension = (gcnew System::Windows::Forms::Label());
			this->rdb_randomData = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_repetitionStrings = (gcnew System::Windows::Forms::RadioButton());
			this->lbl_repeatProcess = (gcnew System::Windows::Forms::Label());
			this->numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl_typeData = (gcnew System::Windows::Forms::Label());
			this->txb_fileName = (gcnew System::Windows::Forms::TextBox());
			this->txb_fileExtension = (gcnew System::Windows::Forms::TextBox());
			this->txb_repetitionString = (gcnew System::Windows::Forms::TextBox());
			this->lbl_fileSize = (gcnew System::Windows::Forms::Label());
			this->txb_fileSize = (gcnew System::Windows::Forms::TextBox());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_numericSystem = (gcnew System::Windows::Forms::Label());
			this->panel_numericSystem = (gcnew System::Windows::Forms::Panel());
			this->rdb_binary = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_metric = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_repetitionHexadecimal = (gcnew System::Windows::Forms::RadioButton());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->lbl_bufferSize = (gcnew System::Windows::Forms::Label());
			this->panel_bufferSize = (gcnew System::Windows::Forms::Panel());
			this->rdb_4MB = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_256KB = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_1MB = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_64KB = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_1KB = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_8KB = (gcnew System::Windows::Forms::RadioButton());
			this->img_dataType = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->backgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->lbl_CreatingFile = (gcnew System::Windows::Forms::Label());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->lbl_elapsedTime = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->lbl_suffix = (gcnew System::Windows::Forms::Label());
			this->comboBox_suffix = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->BeginInit();
			this->panel_numericSystem->SuspendLayout();
			this->panel_bufferSize->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_dataType))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_generate
			// 
			this->btn_generate->Location = System::Drawing::Point(160, 615);
			this->btn_generate->Name = L"btn_generate";
			this->btn_generate->Size = System::Drawing::Size(100, 35);
			this->btn_generate->TabIndex = 0;
			this->btn_generate->Text = L"Generate";
			this->btn_generate->UseVisualStyleBackColor = true;
			this->btn_generate->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::btn_generate_MouseClick);
			// 
			// lbl_fileName
			// 
			this->lbl_fileName->AutoSize = true;
			this->lbl_fileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_fileName->Location = System::Drawing::Point(13, 19);
			this->lbl_fileName->Name = L"lbl_fileName";
			this->lbl_fileName->Size = System::Drawing::Size(73, 17);
			this->lbl_fileName->TabIndex = 1;
			this->lbl_fileName->Text = L"File name:";
			// 
			// lbl_fileExtension
			// 
			this->lbl_fileExtension->AutoSize = true;
			this->lbl_fileExtension->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_fileExtension->Location = System::Drawing::Point(12, 51);
			this->lbl_fileExtension->Name = L"lbl_fileExtension";
			this->lbl_fileExtension->Size = System::Drawing::Size(98, 17);
			this->lbl_fileExtension->TabIndex = 2;
			this->lbl_fileExtension->Text = L"File extension:";
			// 
			// rdb_randomData
			// 
			this->rdb_randomData->AutoSize = true;
			this->rdb_randomData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_randomData->Location = System::Drawing::Point(16, 228);
			this->rdb_randomData->Name = L"rdb_randomData";
			this->rdb_randomData->Size = System::Drawing::Size(100, 19);
			this->rdb_randomData->TabIndex = 3;
			this->rdb_randomData->Text = L"Random data";
			this->rdb_randomData->UseVisualStyleBackColor = true;
			this->rdb_randomData->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_randomData_CheckedChanged);
			// 
			// rdb_repetitionStrings
			// 
			this->rdb_repetitionStrings->AutoSize = true;
			this->rdb_repetitionStrings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rdb_repetitionStrings->Location = System::Drawing::Point(119, 228);
			this->rdb_repetitionStrings->Name = L"rdb_repetitionStrings";
			this->rdb_repetitionStrings->Size = System::Drawing::Size(111, 19);
			this->rdb_repetitionStrings->TabIndex = 4;
			this->rdb_repetitionStrings->Text = L"String repetition";
			this->rdb_repetitionStrings->UseVisualStyleBackColor = true;
			this->rdb_repetitionStrings->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_repetitionStrings_CheckedChanged);
			// 
			// lbl_repeatProcess
			// 
			this->lbl_repeatProcess->AutoSize = true;
			this->lbl_repeatProcess->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_repeatProcess->Location = System::Drawing::Point(13, 409);
			this->lbl_repeatProcess->Name = L"lbl_repeatProcess";
			this->lbl_repeatProcess->Size = System::Drawing::Size(107, 17);
			this->lbl_repeatProcess->TabIndex = 5;
			this->lbl_repeatProcess->Text = L"Number of files:";
			// 
			// numericUpDown
			// 
			this->numericUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown->Location = System::Drawing::Point(131, 406);
			this->numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000000, 0, 0, 0 });
			this->numericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown->Name = L"numericUpDown";
			this->numericUpDown->Size = System::Drawing::Size(99, 23);
			this->numericUpDown->TabIndex = 6;
			this->numericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDown_ValueChanged);
			// 
			// lbl_typeData
			// 
			this->lbl_typeData->AutoSize = true;
			this->lbl_typeData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_typeData->Location = System::Drawing::Point(13, 197);
			this->lbl_typeData->Name = L"lbl_typeData";
			this->lbl_typeData->Size = System::Drawing::Size(92, 17);
			this->lbl_typeData->TabIndex = 7;
			this->lbl_typeData->Text = L"Type of data:";
			// 
			// txb_fileName
			// 
			this->txb_fileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txb_fileName->Location = System::Drawing::Point(120, 16);
			this->txb_fileName->MaxLength = 256;
			this->txb_fileName->Name = L"txb_fileName";
			this->txb_fileName->Size = System::Drawing::Size(261, 22);
			this->txb_fileName->TabIndex = 8;
			this->txb_fileName->TextChanged += gcnew System::EventHandler(this, &MainForm::txb_fileName_TextChanged);
			// 
			// txb_fileExtension
			// 
			this->txb_fileExtension->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txb_fileExtension->Location = System::Drawing::Point(120, 49);
			this->txb_fileExtension->MaxLength = 256;
			this->txb_fileExtension->Name = L"txb_fileExtension";
			this->txb_fileExtension->Size = System::Drawing::Size(261, 22);
			this->txb_fileExtension->TabIndex = 9;
			this->txb_fileExtension->TextChanged += gcnew System::EventHandler(this, &MainForm::txb_fileExtension_TextChanged);
			// 
			// txb_repetitionString
			// 
			this->txb_repetitionString->Enabled = false;
			this->txb_repetitionString->Location = System::Drawing::Point(16, 266);
			this->txb_repetitionString->MaxLength = 3072;
			this->txb_repetitionString->Multiline = true;
			this->txb_repetitionString->Name = L"txb_repetitionString";
			this->txb_repetitionString->Size = System::Drawing::Size(365, 121);
			this->txb_repetitionString->TabIndex = 10;
			this->txb_repetitionString->TextChanged += gcnew System::EventHandler(this, &MainForm::txb_repetitionString_TextChanged);
			// 
			// lbl_fileSize
			// 
			this->lbl_fileSize->AutoSize = true;
			this->lbl_fileSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_fileSize->Location = System::Drawing::Point(13, 85);
			this->lbl_fileSize->Name = L"lbl_fileSize";
			this->lbl_fileSize->Size = System::Drawing::Size(63, 17);
			this->lbl_fileSize->TabIndex = 11;
			this->lbl_fileSize->Text = L"File size:";
			// 
			// txb_fileSize
			// 
			this->txb_fileSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txb_fileSize->Location = System::Drawing::Point(120, 82);
			this->txb_fileSize->MaxLength = 256;
			this->txb_fileSize->Name = L"txb_fileSize";
			this->txb_fileSize->Size = System::Drawing::Size(152, 22);
			this->txb_fileSize->TabIndex = 12;
			this->txb_fileSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txb_fileSize->TextChanged += gcnew System::EventHandler(this, &MainForm::txb_fileSize_TextChanged);
			// 
			// comboBox
			// 
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Bytes", L"Kilobytes", L"Megabytes", L"Gigabytes",
					L"Terabytes", L"Petabytes", L"Exabytes"
			});
			this->comboBox->Location = System::Drawing::Point(282, 82);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(103, 24);
			this->comboBox->TabIndex = 13;
			this->comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox_SelectedIndexChanged);
			// 
			// lbl_numericSystem
			// 
			this->lbl_numericSystem->AutoSize = true;
			this->lbl_numericSystem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_numericSystem->Location = System::Drawing::Point(12, 118);
			this->lbl_numericSystem->Name = L"lbl_numericSystem";
			this->lbl_numericSystem->Size = System::Drawing::Size(112, 17);
			this->lbl_numericSystem->TabIndex = 14;
			this->lbl_numericSystem->Text = L"Numeric system:";
			// 
			// panel_numericSystem
			// 
			this->panel_numericSystem->Controls->Add(this->rdb_binary);
			this->panel_numericSystem->Controls->Add(this->rdb_metric);
			this->panel_numericSystem->Location = System::Drawing::Point(121, 117);
			this->panel_numericSystem->Name = L"panel_numericSystem";
			this->panel_numericSystem->Size = System::Drawing::Size(261, 51);
			this->panel_numericSystem->TabIndex = 15;
			// 
			// rdb_binary
			// 
			this->rdb_binary->AutoSize = true;
			this->rdb_binary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_binary->Location = System::Drawing::Point(19, 1);
			this->rdb_binary->Name = L"rdb_binary";
			this->rdb_binary->Size = System::Drawing::Size(180, 20);
			this->rdb_binary->TabIndex = 1;
			this->rdb_binary->Text = L"Binary (1 KB = 1024 Bytes)";
			this->rdb_binary->UseVisualStyleBackColor = true;
			this->rdb_binary->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_binary_CheckedChanged);
			// 
			// rdb_metric
			// 
			this->rdb_metric->AutoSize = true;
			this->rdb_metric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_metric->Location = System::Drawing::Point(19, 26);
			this->rdb_metric->Name = L"rdb_metric";
			this->rdb_metric->Size = System::Drawing::Size(181, 20);
			this->rdb_metric->TabIndex = 0;
			this->rdb_metric->Text = L"Metric  (1 KB = 1000 Bytes)";
			this->rdb_metric->UseVisualStyleBackColor = true;
			this->rdb_metric->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_metric_CheckedChanged);
			// 
			// rdb_repetitionHexadecimal
			// 
			this->rdb_repetitionHexadecimal->AutoSize = true;
			this->rdb_repetitionHexadecimal->Enabled = false;
			this->rdb_repetitionHexadecimal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rdb_repetitionHexadecimal->Location = System::Drawing::Point(233, 228);
			this->rdb_repetitionHexadecimal->Name = L"rdb_repetitionHexadecimal";
			this->rdb_repetitionHexadecimal->Size = System::Drawing::Size(152, 19);
			this->rdb_repetitionHexadecimal->TabIndex = 16;
			this->rdb_repetitionHexadecimal->Text = L"Hexadecimal repetition";
			this->rdb_repetitionHexadecimal->UseVisualStyleBackColor = true;
			this->rdb_repetitionHexadecimal->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_repetitionHexadecimal_CheckedChanged);
			// 
			// folderBrowserDialog
			// 
			this->folderBrowserDialog->Description = L"Select folder to save the file(s):";
			// 
			// lbl_bufferSize
			// 
			this->lbl_bufferSize->AutoSize = true;
			this->lbl_bufferSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_bufferSize->Location = System::Drawing::Point(12, 464);
			this->lbl_bufferSize->Name = L"lbl_bufferSize";
			this->lbl_bufferSize->Size = System::Drawing::Size(79, 17);
			this->lbl_bufferSize->TabIndex = 17;
			this->lbl_bufferSize->Text = L"Buffer size:";
			// 
			// panel_bufferSize
			// 
			this->panel_bufferSize->Controls->Add(this->rdb_4MB);
			this->panel_bufferSize->Controls->Add(this->rdb_256KB);
			this->panel_bufferSize->Controls->Add(this->rdb_1MB);
			this->panel_bufferSize->Controls->Add(this->rdb_64KB);
			this->panel_bufferSize->Controls->Add(this->rdb_1KB);
			this->panel_bufferSize->Controls->Add(this->rdb_8KB);
			this->panel_bufferSize->Location = System::Drawing::Point(15, 481);
			this->panel_bufferSize->Name = L"panel_bufferSize";
			this->panel_bufferSize->Size = System::Drawing::Size(366, 37);
			this->panel_bufferSize->TabIndex = 19;
			// 
			// rdb_4MB
			// 
			this->rdb_4MB->AutoSize = true;
			this->rdb_4MB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_4MB->Location = System::Drawing::Point(307, 16);
			this->rdb_4MB->Name = L"rdb_4MB";
			this->rdb_4MB->Size = System::Drawing::Size(54, 19);
			this->rdb_4MB->TabIndex = 19;
			this->rdb_4MB->Text = L"4 MB";
			this->rdb_4MB->UseVisualStyleBackColor = true;
			this->rdb_4MB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_4MB_CheckedChanged);
			// 
			// rdb_256KB
			// 
			this->rdb_256KB->AutoSize = true;
			this->rdb_256KB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_256KB->Location = System::Drawing::Point(175, 16);
			this->rdb_256KB->Name = L"rdb_256KB";
			this->rdb_256KB->Size = System::Drawing::Size(65, 19);
			this->rdb_256KB->TabIndex = 17;
			this->rdb_256KB->Text = L"256 KB";
			this->rdb_256KB->UseVisualStyleBackColor = true;
			this->rdb_256KB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_256KB_CheckedChanged);
			// 
			// rdb_1MB
			// 
			this->rdb_1MB->AutoSize = true;
			this->rdb_1MB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_1MB->Location = System::Drawing::Point(245, 16);
			this->rdb_1MB->Name = L"rdb_1MB";
			this->rdb_1MB->Size = System::Drawing::Size(57, 19);
			this->rdb_1MB->TabIndex = 18;
			this->rdb_1MB->Text = L" 1 MB";
			this->rdb_1MB->UseVisualStyleBackColor = true;
			this->rdb_1MB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_1MB_CheckedChanged);
			// 
			// rdb_64KB
			// 
			this->rdb_64KB->AutoSize = true;
			this->rdb_64KB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_64KB->Location = System::Drawing::Point(112, 16);
			this->rdb_64KB->Name = L"rdb_64KB";
			this->rdb_64KB->Size = System::Drawing::Size(58, 19);
			this->rdb_64KB->TabIndex = 16;
			this->rdb_64KB->Text = L"64 KB";
			this->rdb_64KB->UseVisualStyleBackColor = true;
			this->rdb_64KB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_64KB_CheckedChanged);
			// 
			// rdb_1KB
			// 
			this->rdb_1KB->AutoSize = true;
			this->rdb_1KB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_1KB->Location = System::Drawing::Point(0, 16);
			this->rdb_1KB->Name = L"rdb_1KB";
			this->rdb_1KB->Size = System::Drawing::Size(51, 19);
			this->rdb_1KB->TabIndex = 3;
			this->rdb_1KB->Text = L"1 KB";
			this->rdb_1KB->UseVisualStyleBackColor = true;
			this->rdb_1KB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_1KB_CheckedChanged);
			// 
			// rdb_8KB
			// 
			this->rdb_8KB->AutoSize = true;
			this->rdb_8KB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_8KB->Location = System::Drawing::Point(56, 16);
			this->rdb_8KB->Name = L"rdb_8KB";
			this->rdb_8KB->Size = System::Drawing::Size(51, 19);
			this->rdb_8KB->TabIndex = 4;
			this->rdb_8KB->Text = L"8 KB";
			this->rdb_8KB->UseVisualStyleBackColor = true;
			this->rdb_8KB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdb_8KB_CheckedChanged);
			// 
			// img_dataType
			// 
			this->img_dataType->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"img_dataType.Image")));
			this->img_dataType->Location = System::Drawing::Point(362, 197);
			this->img_dataType->Name = L"img_dataType";
			this->img_dataType->Size = System::Drawing::Size(20, 20);
			this->img_dataType->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->img_dataType->TabIndex = 20;
			this->img_dataType->TabStop = false;
			this->toolTip->SetToolTip(this->img_dataType, resources->GetString(L"img_dataType.ToolTip"));
			// 
			// toolTip
			// 
			this->toolTip->AutoPopDelay = 30000;
			this->toolTip->InitialDelay = 500;
			this->toolTip->ReshowDelay = 100;
			// 
			// backgroundWorker
			// 
			this->backgroundWorker->WorkerReportsProgress = true;
			this->backgroundWorker->WorkerSupportsCancellation = true;
			this->backgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::backgroundWorker_DoWork);
			this->backgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::backgroundWorker_ProgressChanged);
			this->backgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::backgroundWorker_RunWorkerCompleted);
			// 
			// lbl_CreatingFile
			// 
			this->lbl_CreatingFile->AutoSize = true;
			this->lbl_CreatingFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_CreatingFile->Location = System::Drawing::Point(18, 545);
			this->lbl_CreatingFile->Name = L"lbl_CreatingFile";
			this->lbl_CreatingFile->Size = System::Drawing::Size(87, 17);
			this->lbl_CreatingFile->TabIndex = 21;
			this->lbl_CreatingFile->Text = L"Creating file:";
			this->lbl_CreatingFile->Visible = false;
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(21, 572);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(360, 23);
			this->progressBar->TabIndex = 22;
			this->progressBar->Visible = false;
			// 
			// lbl_elapsedTime
			// 
			this->lbl_elapsedTime->AutoSize = true;
			this->lbl_elapsedTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_elapsedTime->Location = System::Drawing::Point(224, 545);
			this->lbl_elapsedTime->Name = L"lbl_elapsedTime";
			this->lbl_elapsedTime->Size = System::Drawing::Size(93, 17);
			this->lbl_elapsedTime->TabIndex = 23;
			this->lbl_elapsedTime->Text = L"Elapsed time:";
			this->lbl_elapsedTime->Visible = false;
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MainForm::timer_Tick);
			// 
			// btn_cancel
			// 
			this->btn_cancel->Location = System::Drawing::Point(160, 615);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(100, 35);
			this->btn_cancel->TabIndex = 24;
			this->btn_cancel->Text = L"Cancel";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Visible = false;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &MainForm::btn_cancel_Click);
			// 
			// lbl_suffix
			// 
			this->lbl_suffix->AutoSize = true;
			this->lbl_suffix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_suffix->Location = System::Drawing::Point(271, 408);
			this->lbl_suffix->Name = L"lbl_suffix";
			this->lbl_suffix->Size = System::Drawing::Size(46, 17);
			this->lbl_suffix->TabIndex = 25;
			this->lbl_suffix->Text = L"Suffix:";
			// 
			// comboBox_suffix
			// 
			this->comboBox_suffix->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_suffix->Enabled = false;
			this->comboBox_suffix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox_suffix->FormattingEnabled = true;
			this->comboBox_suffix->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"_1", L"-1", L" 1", L" (1)", L" [1]" });
			this->comboBox_suffix->Location = System::Drawing::Point(322, 405);
			this->comboBox_suffix->Name = L"comboBox_suffix";
			this->comboBox_suffix->Size = System::Drawing::Size(63, 24);
			this->comboBox_suffix->TabIndex = 26;
			this->comboBox_suffix->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox_suffix_SelectedIndexChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(404, 662);
			this->Controls->Add(this->comboBox_suffix);
			this->Controls->Add(this->lbl_suffix);
			this->Controls->Add(this->lbl_elapsedTime);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->lbl_CreatingFile);
			this->Controls->Add(this->img_dataType);
			this->Controls->Add(this->panel_bufferSize);
			this->Controls->Add(this->lbl_bufferSize);
			this->Controls->Add(this->rdb_repetitionHexadecimal);
			this->Controls->Add(this->panel_numericSystem);
			this->Controls->Add(this->lbl_numericSystem);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->txb_fileSize);
			this->Controls->Add(this->lbl_fileSize);
			this->Controls->Add(this->txb_repetitionString);
			this->Controls->Add(this->txb_fileExtension);
			this->Controls->Add(this->txb_fileName);
			this->Controls->Add(this->lbl_typeData);
			this->Controls->Add(this->numericUpDown);
			this->Controls->Add(this->lbl_repeatProcess);
			this->Controls->Add(this->rdb_repetitionStrings);
			this->Controls->Add(this->rdb_randomData);
			this->Controls->Add(this->lbl_fileExtension);
			this->Controls->Add(this->lbl_fileName);
			this->Controls->Add(this->btn_generate);
			this->Controls->Add(this->btn_cancel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(420, 600);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Data Generator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->EndInit();
			this->panel_numericSystem->ResumeLayout(false);
			this->panel_numericSystem->PerformLayout();
			this->panel_bufferSize->ResumeLayout(false);
			this->panel_bufferSize->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_dataType))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Windows Events generated code
	private: System::Void btn_generate_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void txb_fileName_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void txb_fileSize_TextChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void txb_fileExtension_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void rdb_binary_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void rdb_metric_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void rdb_randomData_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void rdb_repetitionStrings_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void rdb_repetitionHexadecimal_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void rdb_1KB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void rdb_8KB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void rdb_64KB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void rdb_256KB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void rdb_1MB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void rdb_4MB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void numericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void comboBox_suffix_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void txb_repetitionString_TextChanged(System::Object^  sender, System::EventArgs^  e);

	/// <summary>
	/// Time consuming operations go here </br>
	/// i.e. Database operations,Reporting
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
    private: System::Void backgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
	
	/// <summary>
	/// Notification is performed here to the progress bar
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
    private: System::Void backgroundWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
   
	/// <summary>
	/// On completed do the appropriate task
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
    private: System::Void backgroundWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);

	/// <summary>
	/// On specific time interval elapsed
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e);

	/// <summary>
	/// Stop the routine of file creation. The file is deleted in the process.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	private: System::Void btn_cancel_Click(System::Object^  sender, System::EventArgs^  e);
#pragma endregion
};
}
