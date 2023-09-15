/*
This program asks the user to input a phone number.
Then, it outputs the number according to the international standard for US phone numbers.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int NumberOfDigits(string, int);
string StringOfDigits(string, int);
string AlterStringOfDigits(string, int, int);
void printFormattedString(string);

int main() {
	string userInputString;

	cout << "Please enter a phone number: ";
	getline(cin, userInputString);
	int userInputLength = userInputString.length();

	int numberOfDigitsInInput = NumberOfDigits(userInputString, userInputLength);
	string stringOfDigitsInInput = StringOfDigits(userInputString, userInputLength);
	string correctedDigitString = AlterStringOfDigits(stringOfDigitsInInput, userInputLength, numberOfDigitsInInput);
	printFormattedString(correctedDigitString);

	return 0;
}



int NumberOfDigits(string stringToAnalyze, int MAX_INPUT_SIZE) {
	int numDigits = 0;
	for (int counter = 0; counter < MAX_INPUT_SIZE; counter += 1) {
		if (isdigit(stringToAnalyze[counter])) {
			numDigits += 1;
		}
	}
	return numDigits;
}

string StringOfDigits(string stringToAnalyze, int MAX_INPUT_SIZE) {
	string digitString = "";
	for (int counter = 0; counter < MAX_INPUT_SIZE; counter += 1) {
		if (isdigit(stringToAnalyze[counter])) {
			digitString += stringToAnalyze[counter];
		}
	}
	return digitString;
}

string AlterStringOfDigits(string stringToAnalyze, int MAX_INPUT_SIZE, int numDigits) {
	int counter;
	string correctedDigitString = "";
	if (numDigits >= 10) {
		for (counter = 0; counter < 10; counter += 1) {
			correctedDigitString += stringToAnalyze[counter];
		}
	} else {
		for (counter = 0; counter < numDigits; counter += 1) {
			correctedDigitString += stringToAnalyze[counter];
		}
		for (counter = numDigits; counter < 10; counter += 1) {
			correctedDigitString += 'x';
		}
	}
	return correctedDigitString;
}

void printFormattedString(string stringToPrint) {
	cout << "+1-";
	for (int counter = 0; counter < 10; counter += 1) {
		cout << stringToPrint[counter];
		if (counter == 2 || counter == 5) {
			cout << "-";
		}
	}
}