// Aaron Albrecht

#include <iostream>
#include <string>
using namespace std;
//creating the class chadaClock with private variables and public methods
class chadaClock {
private:
	int hours;
	int minutes;
	int seconds;

public:        
    void setSeconds(int secondsvar) {  //sets the seconds variable
		seconds = secondsvar;
	}
	void setMinutes(int minutesvar) {  //sets the minutes variable
		minutes = minutesvar;
	}
	void setHours(int hoursvar) {  //sets the hours variable
		hours = hoursvar;
	}
	int getSeconds() {  //returns the seconds variable
		return seconds;
	}
	int getMinutes() {  //returns the minutes variable
		return minutes;
	}
	int getHours() {  //returns the hours variable
		return hours;
	}
    //method to convert a number to a string and adds a leading 0 if the number is less than 10
    string twoDigitString(int n) {
        string number = std::to_string(n);
        if (n < 10) {
            number = "0" + number;
        }
        return number;
    }
	//method to create a string of characters of length n
    string nCharString(int n, char c) {
        string charString = "";
        for (int i = 0; i < n; ++i) {
            charString += c;
        }
        return charString;
    }
    //method to return the time in 24 hour format
    string formatTime24(int h, int m, int s) {
        string hours = twoDigitString(h);
        string minutes = twoDigitString(m);
        string seconds = twoDigitString(s);
        string time = hours.append(":").append(minutes).append(":").append(seconds);

        return time;
    }
	//method to return the time in 12 hour format with AM or PM
    string formatTime12(int h, int m, int s) {
        string hours = "";
        string minutes = twoDigitString(m);
        string seconds = twoDigitString(s);
        string ampm = "";
        if (h >= 0 && h < 12) {
            if (h == 0) {
                hours = twoDigitString(12);
            }
            else {
                hours = twoDigitString(h);
            }
            ampm = " A M";
        }
        else {
            if (h == 12) {
                hours = twoDigitString(12);
            }
            else {
                hours = twoDigitString(h - 12);
            }
            ampm = " P M";
        }

        string time = hours.append(":").append(minutes).append(":").append(seconds).append(ampm);

        return time;
    }
    //method to print the main menu
    void printMenu() {
        cout << nCharString(27, '*') << endl;
        cout << "* 1 - Add One Hour        *" << endl;
        cout << "* 2 - Add One Minute      *" << endl;
        cout << "* 3 - Add One Second      *" << endl;
        cout << "* 4 - Exit Program        *" << endl;
        cout << nCharString(27, '*') << endl;
    }
	//method to display both the 12 and 24 hour clocks side by side
    void displayClocks(int h, int m, int s) {
        cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
        cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*   ";
        cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
        cout << endl;
        cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*   ";
        cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
        cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    }
    //method to add 1 second to the clock
    void addOneSecond() {
        if (getSeconds() <= 58) {
            setSeconds(getSeconds() + 1);
        }
        else {
            setSeconds(0);
            addOneMinute();
        }
    }
	//method to add 1 minute to the clock
    void addOneMinute() {
        if (getMinutes() <= 58) {
            setMinutes(getMinutes() + 1);
        }
        else {
            setMinutes(0);
            addOneHour();
        }
    }
	//method to add 1 hour to the clock
    void addOneHour() {
        if (getHours() <= 22) {
            setHours(getHours() + 1);
        }
        else {
            setHours(0);
        }
    }
    //method to allow a user to input the initial time
	void initialize() {
		cout << "Please enter the hour" << endl;
		cin >> hours;
		cout << "Please enter the minutes" << endl;
		cin >> minutes;
		cout << "Please enter the seconds" << endl;
		cin >> seconds;
	}
	
};
//main program segment that utilizes the chadaClock class
int main() {
    int choice = 0;
	chadaClock clock;
	clock.initialize();  //calls the method to initialize the clock with user input

	while (choice != 4) {  //the main while loop that runs until option 4 is selected
		clock.printMenu();
		cout << endl;
        cin >> choice;
        switch (choice) {
            case 1:
				clock.addOneHour();  //calls the method to add one hour to the clock
                break;
            case 2:
				clock.addOneMinute();  //calls the method to add one minute to the clock
                break;
            case 3:
				clock.addOneSecond();  //calls the method to add one second to the clock
                break;
            case 4:
                break; //exits menu
            default:
                cout << "Invalid choice, please try again." << endl;
                break;  //in case an invalid choice is entered
        }
        if (choice != 4) {
            clock.displayClocks(clock.getHours(), clock.getMinutes(), clock.getSeconds());
        }
    }
    cout << "You have exited the program" << endl;  //message displayed showing the program ended
    
    return 0;

}