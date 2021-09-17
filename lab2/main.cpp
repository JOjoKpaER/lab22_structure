#include <vector>

#include "Main.h"
#include "FileLoader.h"
#include "Menu.cpp"

int main() {
	std::vector<datetime> *array = new std::vector<datetime>;
	FileLoader* fl = new FileLoader("Input.txt", "Output.txt", array);
	fl->openFileInput();
	fl->readFile();
	MenuHandler(fl, array);
	return 0;
}