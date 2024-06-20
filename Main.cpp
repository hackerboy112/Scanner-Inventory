#include <iostream>
#include <fstream>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>

#include "Inventory.h"


int main() {
	
	std::cout << "Scan a random barcode, enter (x) to change mode. ";
	addInventory();
	system("cls");
	std::cout << "Saving EAN to file\n";

	
	std::cout << "Reading from file: \n ";
	readInventory();

	return 0;
}

