#include <iostream>
#include <fstream>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>


void addInventory() {
	std::string EAN;
	std::ofstream myfile("values.txt", std::ios::app);

	if (myfile.is_open()) {
		std::vector<std::string> lines;

		while (true) {
			std::getline(std::cin, EAN); // Read the entire line
			if (EAN == "x" || EAN == "X") {
				break;	// Exit the loop if 'x' or 'X' is entered
			}
			if (!EAN.empty()) {
				lines.push_back(EAN); // Add the EAN to the vector
			}
		}
		for (const auto& code : lines) {
			myfile << code << "\n"; // Write each EAN to the file
		}
		myfile.close();
	}
	else {
		std::cout << "Can't open file." << std::endl;
	}
}




void readInventory() {

	std::ifstream myfile("values.txt", std::ios::in);
	std::string line;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			std::cout << line << "\n";
		}
		myfile.close();
	}
	else {
		std::cout << "Can't open file. ";
	}
}
