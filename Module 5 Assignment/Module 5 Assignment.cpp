// Aaron Albrecht		June 2, 2026

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//function to convert fahrenheit to celsius
double convertToCelsius(double fahrenheit) {
	return (fahrenheit - 32) * 5.0 / 9.0;
}
//main program body
int main() {
	//declares the instream file and checks if it was opened successfully
	ifstream inFile("FahrenheitTemperature.txt");
	if (!inFile) {
		cerr << "File could not be opened" << endl;
		return 1;
	}
	else {
		cout << "File was opened successfully" << endl;
	}
	//declares the outstream file and checks if it was opened successfully
	ofstream outFile("CelsiusTemperature.txt");
	if (!outFile) {
		cerr << "File could not be opened" << endl;
		return 1;
	}
	else {
		cout << "File was created successfully" << endl;
	}

	//declartion of variables
	vector<string> cities;
	vector<double> celsiusTemperatures;
	string city;
	double fahrenheit;
	double celsius;

	//loop to read the city and fahrenheit temperature, convert to celsius, and store in the corresponding vectors
	do {
		inFile >> city >> fahrenheit;
		celsius = convertToCelsius(fahrenheit);
		cities.push_back(city);
		celsiusTemperatures.push_back(celsius);
		//clears the new line so the next info can be read correctly
		getline(inFile, city);
	} while (!inFile.eof());

	//loop to write the city and celsius temperature to the new file
	for (int i = 0; i < cities.size(); i++) {
		outFile << fixed << setprecision(2) << cities[i] << " " << celsiusTemperatures[i] << endl;
	}

	//confirmation statement that the was written to the file
	cout << "City and celsius temperature data written" << endl;

	//closes the outfile stream
	inFile.close();
	outFile.close();
	
	return 0;
}
