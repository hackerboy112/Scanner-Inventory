#include <iostream>
#include <fstream>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include "Inventory.h"


void addInventory(Mode &currentMode);
void removeInventory(Mode& currentMode);
void readInventory();

int main() {


	Mode currentMode = ADD_SCAN; //program starts in Add mode

	while (true) {

	switch (currentMode) {

	case ADD_SCAN:
		addInventory(currentMode);
		break;

	case REMOVE_SCAN:
		removeInventory(currentMode);
		break;

	case READ_SCAN:
		std::cout << "Reading from file: \n " << std::endl;
		readInventory();
		break;

	case IDLE_MODE:
		std::cout << "Going into sleep mode. " << std::endl;
		//add sleep logic.
		return 0;

	default:
		std::cout << "Unknown mode, exiting program." << std::endl;
		return 0;
		}
	}
	return 0;
}