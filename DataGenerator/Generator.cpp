#include "Generator.h"

using namespace DataGenerator;

Generator::Generator(void)
{
	this->returnMessage = OK;
	this->magnitude = 0;
}

Generator::~Generator(void)
{
}

RETURN_MESSAGE Generator::execute(unsigned int system,
								  MAGNITUDE magnitude,
								  double size,
								  string* path,
								  DATATYPE dataType,
								  string* pattern,
								  unsigned long long bufferSize,
								  unsigned long long numberOfFiles,
								  int suffix,
								  BackgroundWorker^  backgroundWorker)
{
	this->backgroundWorker = backgroundWorker;

	// verifying buffer size
	this->bufferSize = bufferSize;
	if (this->bufferSize <= 0)
	{
		this->returnMessage = BUFFER_SIZE_ERROR;
		return returnMessage;
	}

	// Parsing magnitude
	if (parseMagnitude(system, magnitude) != OK) return returnMessage;

	// verifying size
	this->size = size * this->magnitude;
	if (this->size <= 0)
	{
		this->returnMessage = SIZE_ERROR;
		return returnMessage;
	}

	// declaring time keeping variables
	LARGE_INTEGER  frequency;
	LARGE_INTEGER  startBuffer, startProcess;
	LARGE_INTEGER endBuffer, endProcess;
	double elapsedBufferTime, elapsedProcessTime;

	// get ticks per second.
	QueryPerformanceFrequency(&frequency);

	// start timers
	QueryPerformanceCounter(&startBuffer);
	QueryPerformanceCounter(&startProcess);
	cout << "Creating buffer..." << endl;

	// creating patter to be written within buffer
	switch (dataType)
	{
		case DataGenerator::RANDOM:
			createPatternRandom();
			break;
		
		case DataGenerator::STRING:
			createPatternString(pattern);
			break;
		
		case DataGenerator::HEXADECIMAL:
			createPatternHexadecimal(pattern);
			break;
	}

	// creating buffer for write operation
	createBuffer();

	// stop buffer timer.
	QueryPerformanceCounter(&endBuffer);

	// compute and print the elapsed buffer time in millisec.
	elapsedBufferTime = (endBuffer.QuadPart - startBuffer.QuadPart) * 1000.0f / frequency.QuadPart;
	cout << "Buffer created in: " << (elapsedBufferTime/1000) << " seconds." << endl << "Creating file: " << endl;

	// creating the file(s)
	if (numberOfFiles == 1)
	{
		if (createSingleFile(path) != OK) return returnMessage;
	}
	else
	{
		if (createMultipleFiles(path, numberOfFiles, suffix) != OK) return returnMessage;
	}
	
	// stop process timer.
	QueryPerformanceCounter(&endProcess);

	// compute and print the elapsed process time in millisec.
	elapsedProcessTime = (endProcess.QuadPart - startProcess.QuadPart) * 1000.0f / frequency.QuadPart;
	cout << "File created in: " << (elapsedProcessTime / 1000) << " seconds." << endl << "Creating file: " << endl;

	// deleting buffer.
	if (remove("buffer.bin") != 0)
	{
		this->returnMessage = BUFFER_DELETION_ERROR;
		return returnMessage;
	}
		
	this->returnMessage = OK;
	return returnMessage;
}

RETURN_MESSAGE Generator::parseMagnitude(unsigned int system, MAGNITUDE magnitude)
{
	switch (magnitude)
	{
		case BYTES:
			this->magnitude = 1ULL;
			break;

		case KILOBYTES:
			if (system == 1024) this->magnitude = 1024ULL;
			else if (system == 1000) this->magnitude = 1000ULL;
			break;

		case MEGABYTES:
			if (system == 1024) this->magnitude = 1048576ULL;
			else if (system == 1000) this->magnitude = 1000000ULL;
			break;

		case GIGABYTES:
			if (system == 1024) this->magnitude = 1073741824ULL;
			else if (system == 1000) this->magnitude = 1000000000ULL;
			break;

		case TERABYTES:
			if (system == 1024) this->magnitude = 1099511627776ULL;
			else if (system == 1000) this->magnitude = 1000000000000ULL;
			break;

		case PETABYTES:
			if (system == 1024) this->magnitude = 1125899906842624ULL;
			else if (system == 1000) this->magnitude = 1000000000000000ULL;
			break;

		case EXABYTES:
			if (system == 1024) this->magnitude = 1152921504606846976ULL;
			else if (system == 1000) this->magnitude = 1000000000000000000ULL;
			break;

		default:
			break;
	}

	// verifying magnitude
	if (this->magnitude == 0)
	{
		this->returnMessage = MAGNITUDE_ERROR;
		return returnMessage;
	}
	else
	{
		this->returnMessage = OK;
		return returnMessage;
	}
}

RETURN_MESSAGE Generator::createPatternRandom(void)
{
	// creating the patter to be written
	patternSize = bufferSize;
	pattern = new uint8_t[patternSize];

	// creating the remainder to be written
	remainderSize = size - (bufferSize * (size / bufferSize));
	remainder = new uint8_t[remainderSize];

	srand(time(NULL));

	for (auto i = 0; i < patternSize; i++)
	{
		pattern[i] = rand() % 256;
	}

	for (auto i = 0; i < remainderSize; i++)
	{
		remainder[i] = pattern[i];
	}

	return OK;
}

RETURN_MESSAGE Generator::createPatternString(string* pattern)
{
	// creating the patter to be written
	this->patternSize = 1;
	while (this->patternSize < pattern->length()) this->patternSize *= 2;
	this->pattern = new uint8_t[patternSize]{0x00};

	// creating the remainder to be written
	this->remainderSize = this->size - (this->bufferSize * (this->size / this->bufferSize));
	this->remainder = new uint8_t[this->remainderSize];

	for (auto i = 0; i < pattern->length(); i++)
	{
		this->pattern[i] = (uint8_t)pattern->at(i);
	}

	for (auto i = pattern->length(); i < this->patternSize; i++)
	{
		this->pattern[i] = 0x00;
	}

	for (auto i = 0; i < this->remainderSize; i++)
	{
		this->remainder[i] = this->pattern[i % this->patternSize];
	}

	return OK;
}

RETURN_MESSAGE Generator::createPatternHexadecimal(string* pattern)
{
	this->returnMessage = OK;
	return returnMessage;
}

RETURN_MESSAGE Generator::createBuffer(void)
{
	// declaring file output stream.
	ofstream buffer;
	unsigned long long length = bufferSize / patternSize;

	// opening file
	buffer.open("buffer.bin", ios::out | ios::binary | ofstream::trunc);

	// verifying file
	if (!buffer.is_open())
	{
		buffer.close();
		delete this->pattern;
		delete this->remainder;
		this->returnMessage = BUFFER_ERROR;
		return returnMessage;
	}

	// write pattern in disk
	if (patternSize == bufferSize)
	{
		buffer.write(reinterpret_cast<const char*>(&pattern[0]), patternSize * sizeof(uint8_t));
	}
	else
	{
		for (unsigned long i = 0; i < length; i++)
		{
			for (unsigned long j = 0; j < patternSize; j++)
			{
				buffer.write(reinterpret_cast<const char*>(&pattern[j]), sizeof(uint8_t));
			}
		}
	}

	buffer.close();
	delete this->pattern;
	this->returnMessage = OK;
	return returnMessage;
}

RETURN_MESSAGE Generator::createSingleFile(string* path)
{
	// declaring file streams.
	ofstream file;
	ifstream buffer;

	// opening files
	file.open(*path, ios::out | ios::binary | ofstream::trunc);
	buffer.open("buffer.bin", ofstream::in | ofstream::binary);

	// verifying file
	if (!file.is_open())
	{
		file.close();
		buffer.close();
		delete this->remainder;
		this->returnMessage = OUTPUT_FILE_ERROR;
		return returnMessage;
	}

	unsigned long long repetitions;
	repetitions = size / bufferSize;

	unsigned long long percentage = 0;

	for (unsigned long long i = 0ULL; i < repetitions; i++)
	{
		buffer.seekg(0, buffer.beg);
		file << buffer.rdbuf();       

		if (((100ULL * i) / repetitions) > percentage)
		{
			percentage = ((100ULL * i) / repetitions);
			backgroundWorker->ReportProgress(percentage);
		}
		
		if (backgroundWorker->CancellationPending)
		{
			file.close();
			buffer.close();

			// deleting remainder.
			delete this->remainder;

			// deleting file.
			if (remove(path->c_str()) != 0)
			{
				this->returnMessage = FILE_DELETION_ERROR;
				return returnMessage;
			}

			this->returnMessage = CANCEL_REQUEST;
			backgroundWorker->ReportProgress(0);
			return returnMessage;
		}
	}

	if (remainderSize)
	{
		file.write(reinterpret_cast<const char*>(&remainder[0]), remainderSize * sizeof(uint8_t));
	}

	file.close();
	buffer.close();

	delete this->remainder;
	this->returnMessage = OK;

	//Report 100% completion on operation completed
	backgroundWorker->ReportProgress(100);
	return returnMessage;
}

RETURN_MESSAGE Generator::createMultipleFiles(string* path, unsigned long long numberOfFiles, int suffix)
{
	// declaring file streams.
	ofstream file;
	ifstream buffer;
	String^ aux;
	string* auxPath;

	for (auto fileNumber = 0; fileNumber < numberOfFiles; fileNumber++)
	{
		switch (suffix)
		{
			case 0:
				aux = gcnew String(path->c_str());
				aux = aux->Replace(L".", L"_" + fileNumber + L".");
				auxPath = stdString_to_systemPointerString(aux);
				break;

			case 1:
				aux = gcnew String(path->c_str());
				aux = aux->Replace(L".", L"-" + fileNumber + L".");
				auxPath = stdString_to_systemPointerString(aux);
				break;

			case 2:
				aux = gcnew String(path->c_str());
				aux = aux->Replace(L".", L" " + fileNumber + L".");
				auxPath = stdString_to_systemPointerString(aux);
				break;

			case 3:
				aux = gcnew String(path->c_str());
				aux = aux->Replace(L".", L" (" + fileNumber + L").");
				auxPath = stdString_to_systemPointerString(aux);
				break;

			case 4:
				aux = gcnew String(path->c_str());
				aux = aux->Replace(L".", L" [" + fileNumber + L"].");
				auxPath = stdString_to_systemPointerString(aux);
				break;
		}

		// opening files
		file.open(*auxPath, ios::out | ios::binary | ofstream::trunc);
		buffer.open("buffer.bin", ofstream::in | ofstream::binary);

		// verifying file
		if (!file.is_open())
		{
			file.close();
			buffer.close();
			delete this->remainder;
			return OUTPUT_FILE_ERROR;
		}

		unsigned long long percentage = 0;
		unsigned long long repetitions;
		repetitions = size / bufferSize;

		for (unsigned long long i = 0ULL; i < repetitions; i++)
		{
			buffer.seekg(0, buffer.beg);
			file << buffer.rdbuf();

			if (backgroundWorker->CancellationPending)
			{
				file.close();
				buffer.close();

				// deleting remainder.
				delete this->remainder;

				// deleting file.
				if (remove(path->c_str()) != 0)
				{
					this->returnMessage = FILE_DELETION_ERROR;
					return returnMessage;
				}

				backgroundWorker->ReportProgress(0);
				return CANCEL_REQUEST;
			}
		}

		if (remainderSize)
		{
			file.write(reinterpret_cast<const char*>(&remainder[0]), remainderSize * sizeof(uint8_t));
		}

		file.close();
		buffer.close();

		if (backgroundWorker->CancellationPending)
		{
			// deleting remainder.
			delete this->remainder;

			// deleting file.
			if (remove(path->c_str()) != 0)
			{
				this->returnMessage = FILE_DELETION_ERROR;
				return returnMessage;
			}

			backgroundWorker->ReportProgress(0);
			return CANCEL_REQUEST;
		}

		if (((100ULL * fileNumber) / numberOfFiles) > percentage)
		{
			percentage = ((100ULL * fileNumber) / numberOfFiles);
			backgroundWorker->ReportProgress(percentage);
		}
	}

	delete this->remainder;
	this->returnMessage = OK;

	//Report 100% completion on operation completed
	backgroundWorker->ReportProgress(100);
	return returnMessage;
}

string* Generator::stdString_to_systemPointerString(String^ source)
{
	msclr::interop::marshal_context context;
	string* result = new string(context.marshal_as<std::string>(source));
	return result;
}