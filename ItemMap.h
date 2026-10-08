//This is the header file for the itemTracker class

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

class itemMap {
//private member variable to store item names and frequencies in a map
private:
	map<string, int> item;
//public member functions to perform various operations on the item tracker
public:
	itemMap();
	void addItem(const string itemName, int frequency);
	map<string, int> getItem();
	void displayMenu();
	void searchItem(const string& itemName);
	void printFrequencyList();
	void printFrequencyHistogram();
	void saveToFile(const string& filename);
	void loadFromFile(const string& filename);
};