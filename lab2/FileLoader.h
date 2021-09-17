#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

#include "Main.h"

class FileLoader
{
private:

	std::string FilePathInput;
	std::string FilePathOutput;

	std::ifstream *FileInput;
	std::ofstream *FileOutput;

	std::vector<datetime> *array;

public:

	FileLoader(std::string PathInput, std::string PathOutput, std::vector<datetime> *_array) {
		
		FilePathInput = PathInput;
		FilePathOutput = PathOutput;
		array = _array;
	}

	~FileLoader() {
		if (FileInput)
			FileInput->close();
		if (FileOutput)
			FileOutput->close();
	}

	void openFileInput() {;
		FileInput = new std::ifstream(FilePathInput);
		if (!FileInput->is_open())
		{
			printf("Cannot open file\n");
			FileInput = nullptr;
			return;
		}
	}

	void closeFileInput() {
		if (!FileInput) return;
		if (FileInput->is_open()) {
			FileInput->close();
		}
	}

	void openFileOutput() {
		FileOutput = new std::ofstream(FilePathOutput);
		if (!FileOutput->is_open())
		{
			printf("Cannot open file\n");
			FileOutput = nullptr;
			return;
		}
	}

	void closeFileOutput() {
		if (!FileOutput) return;
		if (FileOutput->is_open()) {
			FileOutput->close();
		}
	}

	bool readFile() {
		if (!FileInput) {
			printf("Cannot open file\n");
			return false;
		}
		std::string line;
		datetime *t = nullptr;
		while (std::getline(*FileInput, line)) {
			if (line.empty()) {
				continue;
			}
			unsigned short sec = std::stoi(line.substr(0, line.find(" ")));
			line.erase(0, line.find(" ") + 1);
			unsigned short min = std::stoi(line.substr(0, line.find(" ")));
			line.erase(0, line.find(" ") + 1);
			unsigned short hr = std::stoi(line.substr(0, line.find(" ")));
			line.erase(0, line.find(" ") + 1);
			unsigned short day = std::stoi(line.substr(0, line.find(" ")));
			line.erase(0, line.find(" ") + 1);
			unsigned short mth = std::stoi(line.substr(0, line.find(" ")));
			line.erase(0, line.find(" ") + 1);
			unsigned short year = std::stoi(line);
			datetime date = datetime(sec, min, hr, day, mth, year, t, nullptr);
			if (date.second && date.minute && date.hour && date.day && date.month && date.year) {
				array->push_back(date);
				t = &date;
			}
		}
		
		return true;
	}

	bool wtiteFile() {
		if (!FileOutput) {
			printf("Cannot write file\n");
			return false;
		}
		FileOutput->clear();
		
		return true;
	}
};

