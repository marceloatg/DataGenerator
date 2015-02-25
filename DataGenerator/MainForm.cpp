#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace DataGenerator;
using System::Void;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	DataGenerator::MainForm form;
	Application::Run(%form);
}

MainForm::MainForm(void)
{
	InitializeComponent();
	
	this->comboBox->SelectedIndex = 0;
	this->numberOfFiles = 1;
	this->fileName = gcnew String(L"");
	this->rdb_binary->Checked = true;
	this->rdb_randomData->Checked = true;
	this->rdb_1KB->Checked = true;
}

MainForm::~MainForm()
{
	if (components)
	{
		delete components;
	}
}

Void MainForm::txb_fileName_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	for (size_t i = 0; i < this->txb_fileName->Text->Length; i++)
	{
		if (this->txb_fileName->Text[i] == ' '  ||
			this->txb_fileName->Text[i] == '.'  ||
			this->txb_fileName->Text[i] == '\\' ||
			this->txb_fileName->Text[i] == '/'  ||
			this->txb_fileName->Text[i] == ':'  ||
			this->txb_fileName->Text[i] == '*'  ||
			this->txb_fileName->Text[i] == '?'  ||
			this->txb_fileName->Text[i] == '\"' ||
			this->txb_fileName->Text[i] == '<'  ||
			this->txb_fileName->Text[i] == '>'  ||
			this->txb_fileName->Text[i] == '|')
		{
			this->txb_fileName->Text = this->txb_fileName->Text->Remove(i);
			this->txb_fileName->SelectionStart = i;
			this->txb_fileName->SelectionLength = 0;
		}
	}

	this->fileName = gcnew String(this->txb_fileName->Text + L"." + this->txb_fileExtension->Text);
}

Void MainForm::txb_fileExtension_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	for (size_t i = 0; i < this->txb_fileExtension->Text->Length; i++)
	{
		if (this->txb_fileExtension->Text[i] == ' '  ||
			this->txb_fileExtension->Text[i] == '.'  ||
			this->txb_fileExtension->Text[i] == ','  ||
			this->txb_fileExtension->Text[i] == '\\' ||
			this->txb_fileExtension->Text[i] == '/'  ||
			this->txb_fileExtension->Text[i] == ':'  ||
			this->txb_fileExtension->Text[i] == '*'  ||
			this->txb_fileExtension->Text[i] == '?'  ||
			this->txb_fileExtension->Text[i] == '\"' ||
			this->txb_fileExtension->Text[i] == '<'  ||
			this->txb_fileExtension->Text[i] == '>'  ||
			this->txb_fileExtension->Text[i] == '|')
		{
			this->txb_fileExtension->Text = this->txb_fileExtension->Text->Remove(i);
			this->txb_fileExtension->SelectionStart = i;
			this->txb_fileExtension->SelectionLength = 0;
		}
	}

	this->fileName = gcnew String(this->txb_fileName->Text + L"." + this->txb_fileExtension->Text);
}

Void MainForm::txb_fileSize_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	bool decimal = false;

	for (size_t i = 0; i < this->txb_fileSize->Text->Length; i++)
	{
		if (!(this->txb_fileSize->Text[i] == '0' ||
			this->txb_fileSize->Text[i] == '1' ||
			this->txb_fileSize->Text[i] == '2' ||
			this->txb_fileSize->Text[i] == '3' ||
			this->txb_fileSize->Text[i] == '4' ||
			this->txb_fileSize->Text[i] == '5' ||
			this->txb_fileSize->Text[i] == '6' ||
			this->txb_fileSize->Text[i] == '7' ||
			this->txb_fileSize->Text[i] == '8' ||
			this->txb_fileSize->Text[i] == '9' ||
			this->txb_fileSize->Text[i] == '.' ||
			this->txb_fileSize->Text[i] == ','
			))
		{
			this->txb_fileSize->Text = this->txb_fileSize->Text->Remove(i);
			this->txb_fileSize->SelectionStart = i;
			this->txb_fileSize->SelectionLength = 0;
		}
		else if ((this->txb_fileSize->Text[i] == '.' || this->txb_fileSize->Text[i] == ',') && decimal)
		{
			this->txb_fileSize->Text = this->txb_fileSize->Text->Remove(i);
			this->txb_fileSize->SelectionStart = i;
			this->txb_fileSize->SelectionLength = 0;
		}
		else if (this->txb_fileSize->Text[i] == '.' || this->txb_fileSize->Text[i] == ',')
		{
			decimal = true;
			if(this->txb_fileSize->Text[i] == '.')
			{
				String^ comma = ",";
				String^ period = ".";
				this->txb_fileSize->Text = this->txb_fileSize->Text->Replace(period, comma);
				this->txb_fileSize->SelectionStart = i + 1;
				this->txb_fileSize->SelectionLength = 0;
			}
		}
	}

	if ((decimal && this->txb_fileSize->Text->Length > 1) ||
		(!decimal && this->txb_fileSize->Text->Length > 0))
	{
		this->size = Convert::ToSingle(this->txb_fileSize->Text);
	}
	else this->size = 0.0f;
}

Void MainForm::comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	switch (this->comboBox->SelectedIndex)
	{
		case 0:
			this->magnitude = BYTES;
			break;

		case 1:
			this->magnitude = KILOBYTES;
			break;

		case 2:
			this->magnitude = MEGABYTES;
			break;

		case 3:
			this->magnitude = GIGABYTES;
			break;

		case 4:
			this->magnitude = TERABYTES;
			break;

		case 5:
			this->magnitude = PETABYTES;
			break;

		case 6:
			this->magnitude = EXABYTES;
			break;
	}
}

Void MainForm::rdb_binary_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_binary->Checked)
	{
		this->system = 1024;

		if (rdb_1KB->Checked)
		{
			rdb_1KB->Checked = false;
			rdb_1KB->Checked = true;
		}
		else if (rdb_8KB->Checked)
		{
			rdb_8KB->Checked = false;
			rdb_8KB->Checked = true;
		}
		else if (rdb_64KB->Checked)
		{
			rdb_64KB->Checked = false;
			rdb_64KB->Checked = true;
		}
		else if (rdb_256KB->Checked)
		{
			rdb_256KB->Checked = false;
			rdb_256KB->Checked = true;
		}
		else if (rdb_1MB->Checked)
		{
			rdb_1MB->Checked = false;
			rdb_1MB->Checked = true;
		}
		else if (rdb_4MB->Checked)
		{
			rdb_4MB->Checked = false;
			rdb_4MB->Checked = true;
		}
	}
}

Void MainForm::rdb_metric_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_metric->Checked)
	{
		this->system = 1000;

		if (rdb_1KB->Checked)
		{
			rdb_1KB->Checked = false;
			rdb_1KB->Checked = true;
		}
		else if (rdb_8KB->Checked)
		{
			rdb_8KB->Checked = false;
			rdb_8KB->Checked = true;
		}
		else if (rdb_64KB->Checked)
		{
			rdb_64KB->Checked = false;
			rdb_64KB->Checked = true;
		}
		else if (rdb_256KB->Checked)
		{
			rdb_256KB->Checked = false;
			rdb_256KB->Checked = true;
		}
		else if (rdb_1MB->Checked)
		{
			rdb_1MB->Checked = false;
			rdb_1MB->Checked = true;
		}
		else if (rdb_4MB->Checked)
		{
			rdb_4MB->Checked = false;
			rdb_4MB->Checked = true;
		}
	}
}

Void MainForm::rdb_randomData_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_randomData->Checked)
	{
		this->datatype = RANDOM;
		this->txb_repetitionString->Text = L"";
		this->txb_repetitionString->Enabled = false;
	}
}

Void MainForm::rdb_repetitionStrings_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_repetitionStrings->Checked)
	{
		this->datatype = STRING;
		this->txb_repetitionString->Enabled = true;
	}
}

Void MainForm::rdb_repetitionHexadecimal_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_repetitionHexadecimal->Checked)
	{
		this->datatype = HEXADECIMAL;
		this->txb_repetitionString->Enabled = true;
	}
}

Void MainForm::rdb_1KB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_1KB->Checked) this->bufferSize = 1ULL * (unsigned long)this->system;
}

Void MainForm::rdb_8KB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_8KB->Checked) this->bufferSize = 8ULL * (unsigned long)this->system;
}

Void MainForm::rdb_64KB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_64KB->Checked) this->bufferSize = 64ULL * (unsigned long)this->system;
}

Void MainForm::rdb_256KB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_256KB->Checked) this->bufferSize = 256ULL * (unsigned long)this->system;
}

Void MainForm::rdb_1MB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_1MB->Checked) this->bufferSize = 1ULL * ((unsigned long)this->system * (unsigned long)this->system);
}

Void MainForm::rdb_4MB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->rdb_4MB->Checked) this->bufferSize = 4ULL * ((unsigned long)this->system * (unsigned long)this->system);
}

Void  MainForm::btn_generate_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	// verifying file name
	if (this->txb_fileName->Text->Length < 3 || this->txb_fileExtension->Text->Length < 1)
	{
		MessageBox::Show("The fields “file name” and “file extension” do not form an appropriate file name. Please correct those fields before executing the generator.",
						 "Error",
						 MessageBoxButtons::OK,
						 MessageBoxIcon::Error);

		return;
	}

	// verifying file size
	if (this->size <= 0)
	{
		MessageBox::Show("The field “file size” does not have an appropriate file size. Please correct this field before executing the generator.",
						 "Error",
						 MessageBoxButtons::OK,
						 MessageBoxIcon::Error);

		return;
	}
	else if (this->magnitude == BYTES && this->size < 1)
	{
		MessageBox::Show("The field “file size” does not have an appropriate file size. Please correct this field before executing the generator.",
						 "Error",
						 MessageBoxButtons::OK,
						 MessageBoxIcon::Error);

		this->txb_fileSize->Text = L"1";

		return;
	}

	// verifying string entered
	if (this->rdb_repetitionStrings->Checked == true && this->txb_repetitionString->Text == L"")
	{
		MessageBox::Show("Please enter a valid string pattern before executing the generator.",
						 "Error",
						 MessageBoxButtons::OK,
						 MessageBoxIcon::Error);

		return;
	}
	else if (this->rdb_repetitionHexadecimal->Checked == true && this->txb_repetitionString->Text == L"")
	{
		MessageBox::Show("Please enter a valid hexadecimal value(s) before executing the generator.",
						 "Error",
						 MessageBoxButtons::OK,
						 MessageBoxIcon::Error);

		return;
	}

	// defining file path
	if (this->folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ aux = gcnew String(this->folderBrowserDialog->SelectedPath + "\\" + this->fileName);
		aux = aux->Replace(L"\\", L"\\\\");
		this->path = stdString_to_systemPointerString(aux);

		// adjusting UI
		this->btn_generate->Visible = false;
		this->btn_cancel->Visible = true;
		this->lbl_CreatingFile->Visible = true;
		this->lbl_elapsedTime->Visible = true;
		this->progressBar->Visible = true;
		this->lbl_elapsedTime->Text = L"Elapsed time:    00:00:00";
		this->lbl_CreatingFile->Text = L"Creating file: 1/" + this->numberOfFiles;
		this->second = this->minute = this->hour = 0;
		this->timer->Start();

		// Kickoff the worker thread to begin it's DoWork function.
		backgroundWorker->RunWorkerAsync();
	}
}

string MainForm::stdString_to_systemString(String^ source)
{
	msclr::interop::marshal_context context;
	string result = context.marshal_as<std::string>(source);
	return result;
}

string* MainForm::stdString_to_systemPointerString(String^ source)
{
	msclr::interop::marshal_context context;
	string* result = new string(context.marshal_as<std::string>(source));
	return result;
}

Void MainForm::backgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	switch (this->generator.execute(this->system,
		    this->magnitude,
			this->size,
			this->path,
			this->datatype,
			this->pattern,
			this->bufferSize,
			this->numberOfFiles,
			this->suffix,
			this->backgroundWorker))
	{
		case OK:
			cout << "Execution: OK" << endl << endl;
			break;

		case MAGNITUDE_ERROR:
			cout << "Execution: MAGNITUDE_ERROR" << endl << endl;
			break;

		case BUFFER_SIZE_ERROR:
			cout << "Execution: MAGNITUDE_ERROR" << endl << endl;
			break;

		case SIZE_ERROR:
			cout << "Execution: SIZE_ERROR" << endl << endl;
			break;

		case OUTPUT_FILE_ERROR:
			cout << "Execution: OUTPUT_FILE_ERROR" << endl << endl;
			break;

		case BUFFER_ERROR:
			cout << "Execution: BUFFER_ERROR" << endl << endl;
			break;

		case BUFFER_DELETION_ERROR:
			cout << "Execution: BUFFER_DELETION_ERROR" << endl << endl;
			break;

		case FILE_DELETION_ERROR:
			cout << "Execution: FILE_DELETION_ERROR" << endl << endl;
			break;
	}

	return;
}

Void MainForm::backgroundWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
{
	progressBar->Value = e->ProgressPercentage;

	if (this->numberOfFiles > 1)
	{
		float aux = (((float)e->ProgressPercentage * (float)this->numberOfFiles) / 100);
		int currentFile = aux;

		this->lbl_CreatingFile->Text = L"Creating file: " + currentFile + "/" + this->numberOfFiles;
	}

	return;
}

Void MainForm::backgroundWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
{
	this->btn_generate->Visible = true;
	this->btn_cancel->Visible = false;
	this->lbl_CreatingFile->Visible = false;
	this->lbl_elapsedTime->Visible = false;
	this->progressBar->Visible = false;
	this->progressBar->Value = 0;
	this->timer->Stop();

	delete this->path;

	return;
}

Void MainForm::timer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	this->second++;

	if (this->second == 60)
	{
		this->second = 0;
		this->minute++;
	}

	if (this->minute == 60)
	{
		this->minute = 0;
		this->hour++;
	}

	TimeSpan time = TimeSpan(this->hour, this->minute, this->second);

	this->lbl_elapsedTime->Text = String::Format("Elapsed time: {0, 11}", time);

	return;
}

Void MainForm::btn_cancel_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (backgroundWorker->IsBusy)
	{
		// Notify the worker thread that a cancel has been requested.
		// The cancel will not actually happen until the thread in the
		// DoWork checks the backgroundWorker->CancellationPending flag. 
		backgroundWorker->CancelAsync();
	}

	return;
}

Void MainForm::numericUpDown_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!this->comboBox_suffix->Enabled && this->numericUpDown->Value > 1)
	{
		this->comboBox_suffix->SelectedIndex = 0;
		this->comboBox_suffix->Enabled = true;
	}
	else if (this->comboBox_suffix->Enabled && this->numericUpDown->Value == 1)
	{
		this->comboBox_suffix->SelectedIndex = -1;
		this->comboBox_suffix->Enabled = false;
	}

	this->numberOfFiles = (unsigned long long)this->numericUpDown->Value;
	return;
}

Void MainForm::comboBox_suffix_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->suffix = this->comboBox_suffix->SelectedIndex;
	return;
}

Void MainForm::txb_repetitionString_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->datatype == STRING)
	{
		delete this->pattern;
		this->pattern = stdString_to_systemPointerString(this->txb_repetitionString->Text);
	}
	else if (this->datatype == HEXADECIMAL)
	{
		// MAGIC GOES HERE
	}
	else
	{
		pattern = new string("RANDOM");
	}

	return;
}