#include <iostream>
#include <fstream>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>

#ifndef INVENTORY_H
#define INVENTORY_H

enum Mode {
	ADD_SCAN,
	REMOVE_SCAN,
	READ_SCAN,
	IDLE_MODE
};


void addInventory(Mode& currentMode) {
	std::cout << "Current Mode: Add.\nType and enter: \n(x) for removal mode. \n(s) for sleep mode.\n\n" 
			  << "\t\tScan to add barcodes. \n" << std::endl;

	std::string EAN;
	std::ofstream myfile("values.txt", std::ios::app);

	if (myfile.is_open()) {
		std::vector<std::string> lines;

		while (true) {
			std::getline(std::cin, EAN); // Read the entire line
			if (EAN == "x" || EAN == "X") {
				currentMode = REMOVE_SCAN;
				break; // Exit the loop
			}
			if (EAN == "s" || EAN == "S") {
				currentMode = IDLE_MODE;
				break;
			}


			if (!EAN.empty()) {
				lines.push_back(EAN); // Add the EAN to the vector
			}
		}

		system("cls");
		// Save the collected EANs to the file
		for (const auto& code : lines) {
			std::cout << "Saved EAN to file\n" << std::endl;
			myfile << code << "\n"; // Write each EAN to the file
		}

		myfile.close();
	
	}
	else {
		std::cout << "Can't open file." << std::endl;
	}
}


void removeInventory(Mode& currentMode) {
    std::cout << "Current Mode: Remove\nType and enter: \n(x) for add mode. \n(s) for sleep mode."
        << "\n\n\t\tScan to remove barcodes.\n" << std::endl;

    std::string EAN;

    // Read user input for mode switch and search for matching EAN
    while (true) {
        std::getline(std::cin, EAN);
        if (EAN == "x" || EAN == "X") {
            currentMode = ADD_SCAN;
            return;
        }
        if (EAN == "s" || EAN == "S") {
            currentMode = IDLE_MODE;
            return;
        }
        if (!EAN.empty()) {
            break;
        }
    }

    std::ifstream myfile("values.txt", std::ios::in);
    if (!myfile) {
        std::cout << "Can't open file." << std::endl;
        return;
    }

    std::string line;
    std::vector<std::string> lines;
    bool match = false;

    while (getline(myfile, line)) {
        if (line == EAN) {
            match = true;
        }
        else {
            lines.push_back(line);
        }
    }
    myfile.close();
    system("cls");

    if (match) {
        std::cout << EAN << " was removed. " << std::endl;

        std::ofstream outfile("values.txt");
        if (!outfile) {
            std::cout << "Can't open file for writing." << std::endl;
            return;
        }
        for (const auto& entry : lines) {
            outfile << entry << "\n";
        }
    }
    else {
        std::cout << "EAN not found." << std::endl;
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
#endif
