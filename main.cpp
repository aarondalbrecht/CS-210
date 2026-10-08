//	Aaron Albrecht

#include "ItemMap.h"

int main() {
	int menuChoice = 0;
	itemMap tracker;
	
	tracker.loadFromFile("CS210_Project_Three_Input_File.txt");

	while (menuChoice != 4) {
		tracker.displayMenu();
		cout << "Enter your choice: ";
		cin >> menuChoice;
		switch (menuChoice) {
		case 1: {
			string itemName;
			cout << "Enter item name to search: ";
			cin >> itemName;
			tracker.searchItem(itemName);
			break;
		}
		case 2:
			tracker.printFrequencyList();
			break;
		case 3:
			tracker.printFrequencyHistogram();
			break;
		case 4:
			cout << "Exiting program. Data saved to file." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	tracker.saveToFile("frequency.dat");
	
	return 0;
}