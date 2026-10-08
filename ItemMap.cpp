//Implementation file for the itemMap class

#include "ItemMap.h"

//constructor for the itemMap class
itemMap::itemMap() {}
//function to display the main menu options to the user
void itemMap::displayMenu() {
	cout << "Main Menu:" << endl;
	cout << "1. Search Item" << endl;
	cout << "2. Print Frequency List" << endl;
	cout << "3. Print Frequency Histogram" << endl;
	cout << "4. Exit" << endl;
}
//function to search for an item and display its frequency
void itemMap::searchItem(const string& itemName) {
	auto search = item.find(itemName);
	if (search != item.end()) {
		cout << search->first << " " << search->second << endl;
	}
	else {
		cout << "Item not found" << endl;
	}
}
//function to print the frequency list of items
void itemMap::printFrequencyList() {
	cout << "Item Frequency List:" << endl;
	for (const auto& pair : item) {
		cout << pair.first << " " << pair.second << endl;
	}
}
//function to print the frequency histogram of items
void itemMap::printFrequencyHistogram() {
	cout << "Item Frequency Histogram:" << endl;
	for (const auto& pair : item) {
		cout << right << setw(20) << pair.first << ": ";
		cout << left;
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
}
//function to add an item and its frequency to the map
void itemMap::addItem(const string itemName, int frequency) {
	item[itemName] = frequency;
}
//function to get the item map
map<string, int> itemMap::getItem() {
	return item;
}
//function to save to a file
void itemMap::saveToFile(const string& filename) {
	ofstream outFile(filename);
	for (const auto& pair : item) {
		outFile << pair.first << " " << pair.second << endl;
	}
	outFile.close();
}
//function to load from a file
void itemMap::loadFromFile(const string& filename) {
	ifstream inFile(filename);
	if (!inFile) {
		cerr << "File could not be loaded" << endl;
	}
	else {
		cout << "File opened successfully!" << endl;
	}
	string groceryItem;
	int count = 0;
	while (inFile >> groceryItem) {
		if (item[groceryItem]) {
			item[groceryItem]++;
		}
		else {
			item[groceryItem] = 1;
		}
	}
	
	inFile.close();
}