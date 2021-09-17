#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

#include"Main.h"
#include"FileLoader.h"

static FileLoader *fl;
static std::vector<datetime> *array;

enum Function {
	PRINT,
	NEXT,
	PREVIOUS, 
	PRINTBYYEAR,
	END,
	NONE
};

static void print();
static void next(int x);
static void prev(int x);
static void printByYear();

static void MenuHandler(FileLoader *_fl, std::vector<datetime> *_array) {
	fl = _fl;
	array = _array;
	std::string Actions[] = { //5
		"Print",
		"Next",
		"Previous",
		"Print by year",
		"Close"
	};
	std::string SelectionMessage = "Select next action:\n";
	for (int i = 0; i < 5; i++) {
		SelectionMessage += "\n" + Actions[i];
	}
	SelectionMessage += "\n";
	std::string SelectedAction;
	////////////////////////////////////////////////////////////////////////////////////////
	bool cls = true;
	while (cls) {
		std::cout << SelectionMessage;
		std::getline(std::cin, SelectedAction);
		Function func = NONE;
		for (int i = 0; i < 5; i++) {
			if (SelectedAction == Actions[i]) {
				func = Function(i);
				break;
			}
		}
		switch (func) {
		case(PRINT):
		{
			print();
			break;
		}
		case(NEXT):
		{
			std::cout << "Enter position of the date after which next would be displayed\n";
			int x;
			bool b = true;
			do {
				std::cin >> x;
				if (std::cin.fail() || x < 0) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value proceeded, please enter again\n");
					b = true;
				}
				else
				{
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			next(x);
			break;
		}
		case(PREVIOUS):
		{
			std::cout << "Enter position of the date after which previous would be displayed\n";
			int x;
			bool b = true;
			do {
				std::cin >> x;
				if (std::cin.fail() || x < 0) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value proceeded, please enter again\n");
					b = true;
				}
				else
				{
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			prev(x);
			break;
		}
		case(PRINTBYYEAR):
		{
			printByYear();
			break;
		}
		case(END):
		{
			printf("Program will be closed\n");
			return;
		}
		default: {
			printf("Cannot procceed inputed function\n");
			Sleep(delay);
			break;
		}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////
}

static void print() {
	if (array->empty())	return;
	std::vector<datetime>::iterator iter = array->begin();
	int i = 1;
	do{
		std::cout << "#" << i++ << " " << iter->get() << " ";
		if (iter != array->begin()) {
			iter--;
			std::cout << iter->get() << " ";
			iter++;
		}
		if (iter != array->end()-1) {
			iter++;
			std::cout << iter->get() << " ";
			iter--;
		}
		std::cout << "\n";
		iter++;
	} while (iter != array->end());
	return;
}

static void next(int x) {
	if (array->empty()) return;
	if (x < 0) return;
	if (x > array->size() - 2) return;
		std::cout << "#" << x+1 << " " << array->at(x).get() << " ";
		if (x > 0) {
			std::cout << array->at(x-1).get() << " ";
		}
		if (x < array->size() - 2) {
			std::cout << array->at(x+1).get() << " ";
		}
		std::cout << "\n";
	return;
}

static void prev(int x) {
	if (array->empty()) return;
	if (x < 2) return;
	if (x > array->size()) return;
	std::cout << "#" << x-1 << " " << array->at(x - 1).get() << " ";
	if (x > 1) {
		std::cout << array->at(x - 2).get() << " ";
	}
	if (x < array->size()) {
		std::cout << array->at(x).get() << " ";
	}
	std::cout << "\n";
	
	return;
}

static void printByYear() {
	if (array->empty())	return;
	std::vector<datetime>::iterator iter = array->begin();
	int i = 1;
	do {
		if (iter != array->begin()) {
			iter--;
			unsigned short l = iter->year;
			iter++;
			unsigned short r = iter->year;
			if (l != r) {
				iter++;
				continue;
			}
		}
		std::cout << "#" << i++ << " " << iter->get() << " ";
		if (iter != array->begin()) {
			iter--;
			std::cout << iter->get() << " ";
			iter++;
		}
		if (iter != array->end() - 1) {
			iter++;
			std::cout << iter->get() << " ";
			iter--;
		}
		std::cout << "\n";
		iter++;
	} while (iter != array->end());
	return;
}