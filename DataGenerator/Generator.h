#pragma once

#include <ctime>
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdint>
#include <cstdlib>
#include <windows.h>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;

using System::ComponentModel::BackgroundWorker;

namespace DataGenerator {

	enum RETURN_MESSAGE
	{
		OK,
		MAGNITUDE_ERROR,
		BUFFER_SIZE_ERROR,
		SIZE_ERROR,
		OUTPUT_FILE_ERROR,
		BUFFER_ERROR,
		BUFFER_DELETION_ERROR,
		FILE_DELETION_ERROR,
		CANCEL_REQUEST
	};

	enum MAGNITUDE
	{
		BYTES     = 0,
		KILOBYTES = 1,
		MEGABYTES = 2,
		GIGABYTES = 3,
		TERABYTES = 4,
		PETABYTES = 5,
		EXABYTES  = 6
	};

	enum DATATYPE
	{
		RANDOM,
		STRING,
		HEXADECIMAL
	};

	ref class Generator
	{
	public:
		/// <summary>
		/// Class constructor.
		/// </summary>
		Generator(void);

		/// <summary>
		/// Class destructor.
		/// </summary>
		virtual ~Generator(void);

		RETURN_MESSAGE execute(unsigned int system, 
							   MAGNITUDE magnitude, 
							   double size, 
							   string* path,
							   DATATYPE dataType,
							   string* pattern, 
							   unsigned long long bufferSize,
							   unsigned long long numberOfFiles,
							   int suffix,
							   BackgroundWorker^  backgroundWorker);

	private:
		BackgroundWorker^  backgroundWorker;

		RETURN_MESSAGE returnMessage;

		unsigned long long magnitude;

		unsigned long long size;

		unsigned long long bufferSize;

		uint8_t* pattern;

		unsigned long long patternSize;

		uint8_t* remainder;

		unsigned long long remainderSize;

		RETURN_MESSAGE parseMagnitude(unsigned int system, MAGNITUDE magnitude);

		RETURN_MESSAGE createBuffer(void);
		
		RETURN_MESSAGE createPatternRandom(void);

		RETURN_MESSAGE createPatternString(string* pattern);

		RETURN_MESSAGE createPatternHexadecimal(string* pattern);

		RETURN_MESSAGE createSingleFile(string* path);

		RETURN_MESSAGE createMultipleFiles(string* path, unsigned long long numberOfFiles, int suffix);

		string* stdString_to_systemPointerString(String^ source);
	};
}