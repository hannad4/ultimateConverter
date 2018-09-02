/*============================================================================
Date        : 5/9/2017
Course      : CSC-215
File Name   : ultimateConverter.cpp
Version/Rev : 2.3
Description : This program converts values from many number systems and
              teaches of such conversions.
==============================================================================*/

#include <iostream>                          // Include input/output library
#include <fstream>                           // Include f-stream so an output file can be written
#include <cmath>                             // Include cmath for math operations
#include <string>                           //  Include string for user inputs
#include <windows.h>                        //  Including windows.h allows for the program to be frozen so not too much info is shown on screen at once (system library)

using namespace std;                        //  Using the standard namespace

int decimalToBinary() {					// decimal to binary excersizes
	int number = 0;						// number will hold user input
	int numberCopy = 0;				// keep a copy of number for the output file
	int remainder = 0;				// remainder will hold the remainder in calculations
	int indexx = 0;				// index will be the index in the array (index is key word so use indexx)
	int result[8];			// array with 8 places that is called result
    cout << "Enter a decimal number between 0 and 255: " << endl;			// prompt for input and take it in
    cin >> number;
    if (number < 0 or number > 255) {					// make sure number is in range for 8 bits
    	cout << "The number you entered was not between 0 and 255. Try again" << endl;
    	decimalToBinary();			// if incorrect program will repeat this section
    	return 0;			// return 0 for safety precaution
    }
    else {
    	numberCopy = number;			// keep copy of number
        while (number!=0) 			// calculationn will run as long as number is not 0
        {
            remainder = number % 2; 			// calculate remainder each time
            number = number/2; 			// divide by 2 (infinite loop avoided here)
            result[indexx] = remainder; 		// building up the array
            indexx++; 			// build up index so as to not overwrite any values
        }

        indexx = 7;					// reset index to work down
        cout << numberCopy << " in binary is ";					// start printing out answer
        while (indexx >= 0)			// while loop will run until indexx index is below 0
           {
        	if (result[indexx] == 0 or result[indexx] == 1) {			// integer manipulation in array can have unexpected outcomes due to memory management
        		cout << result[indexx];						// as long as the result is 0 or 1, the index will have been built properly
        	}
        	else {							// otherwise, the result index value will not be a 0 as desired, so set index value to 0
        		result[indexx] = 0;
        		cout << result[indexx];			// output the 0 so the 8 bits are seen on screen
        	}
               indexx--;				// decrement indexx so loop does not run forever
           }

    	ofstream resultFile;								// Create a object called resultFile
    	resultFile.open("Decimal To Binary - Results.txt", ios::app);			// Create a text file to include all of the users inputs and results (open it in append mode)
    	resultFile << "The binary number you entered was " << numberCopy;			// Append the users input to it
    	resultFile << "\nThat number in decimal notation was " << result[7] << result[6] << result[5] << result[4] << result[3] << result[2] << result[1] << result[0] << "\n\n\n";		// Append the result to it
    	resultFile.close();												// DO NOT keep the file open
    	cout << "\nWould you like to try again with a different number? y/n" << endl;		// see if user wants to repeat
    	string repeat;				// take in repeat (not used until here, no point in defining it up above
    	cin >> repeat;
    	if (repeat == "y") {				// if yes, then repeat
    		decimalToBinary();
    		return 0;
    	}
    	else {			// if not then end
    		cout << "OK! An output file with all your entries has been created in the program folder.\nGoodbye!" << endl;
    		return 0;
    	}
    	return 0;			// return for failsafe
       }
    return 0;			// failsafe
    }


int decimalToBinaryINTRO() {			// Intro section includes a bunch of cout statements to explain what the numbering system is
	cout << "The largest possible decimal value for a binary number is 255" << endl;
	Sleep(3000);
	cout << "Think of a number between 0 and 255" << endl;
	cout << "If that number divided by 128 has a remainder of 1 or greater..." << endl;
	cout << "Put a 1 for the first digit. If the remainder is less than 1, then put a 0. Then take your number and subtract it from 128. That is your new number" << endl;
	Sleep(3000);
	cout << "Repeat the process for your new number, but now divide it by 64. Get the resulting new number" << endl;
	Sleep(3000);
	cout << "Repeat it again, but now divide by 32." << endl;
	Sleep(3000);
	cout << "Repeat, but now divide by 16. " << endl;
	Sleep(3000);
	cout << "Then by 4. Then by 2. Then by 1." << endl;
	Sleep(3000);
	cout << "You should have 8 numbers now, all either 1 or 0. Put them together. That is your binary number" << endl;
	cout << "\nLet's practice with actual numbers" << endl;
	decimalToBinary();
	return 0;
}


int binaryToDecimal() {					// Exercise portion of binary to decimal example
	cout << "Let us consider a binary value\nThink of an 8 bit binary number and type it in" << endl;
	cout << "But before you hit enter, try to convert that number by youself, then check if you are right" << endl;
	cout << "Enter an 8-bit binary value now (0 or 1 only): " << endl;
	char numbers[8];		// Create a character array of 8 spaces (Allows for user to type in all the numbers at once
	cin >> numbers;			// Take in users binary numbers in array format
	int counter = 0;		// Counter will know how many digits to consider
	int reversecounter = 7;	// Array spot 0 will need to have the exponent be 7, so reverse counter handles that
	int total = 0;			// Total adds up the result
	while (counter < 8) {	// While loop does the calculation efficiently
		if ((numbers[counter] - 48 == 1) or (numbers[counter] - 48 == 0)) {		// ASCII table shows that the character 1 and the integer 1 is off by 48 spaces
			total = total + ( numbers[counter] - 48 ) * pow(2, reversecounter); // Perform exponential calculation while accounting for the variable type shift (from ASCII)
			counter++;				// Increment the counter up to 7
			reversecounter--;       // Decrement the reverse counter down to 0 so loop will eventually end
		}
		else {			// If the user typed in numbers besides a 0 or a 1, the program will not function
			cout << "You entered a number besides a 0 or a 1, try again\n\n\n" << endl;
			Sleep(3500);
			binaryToDecimal();		// Repeat this section of code so that they can try again
			return 0;				// Return 0 so code does not break
		}
	}
	cout << "The number " << numbers << " in decimal notation is: " << total << endl;  // Assuming all previous conditions are met, the calculation will be made
	ofstream resultFile;								// Create a object called resultFile
	resultFile.open("Binary to Decimal - Results.txt", ios::app);			// Create a text file to include all of the users inputs and results (open it in append mode)
	resultFile << "The binary number you entered was " << numbers;			// Append the users input to it
	resultFile << "\nThat number in decimal notation was " << total << "\n\n\n";		// Append the result to it
	resultFile.close();												// DO NOT keep the file open
	string repeatSection = "";					// Provide user with an option to repeat this section of the program
	cout << "Would you like to try this excerise again with a different number? y/n" << endl;
	cin >> repeatSection;			// Take in the repeat option
	if (repeatSection == "y" or repeatSection == "Yes") {
		cout << "OK! Let's try again with a different number\n\n\n" << endl;
		binaryToDecimal();				// If yes, then this section of the program will repeat
		return 0;					// Return 0 so code does not break
	}
	else {				// If not, program will end
		cout << "OK! Hopefully you've learned some stuff with this program!" << endl;
		cout << "For your reference, you can find a record with all of your inputs in a file called 'Results' " << endl;
		cout << "It is saved in this programs folder" << endl;
		Sleep(1500);
		cout << "Thanks for using this program! Goodbye!" << endl;
		return 0;
	}
}


int binaryToDecimalINTRO() {    // Introdcution section includes a bunch of cout statements to explain what the numbering system is
	string introRepeat = "";    // Create a variable for giving the user an option to repeat the explanation
	// BEGIN INTRODUCTION:
	cout << "Let us consider 8 bit binary values\nThis pretty much means we will consider 8 digit binary numbers" << endl;
	Sleep(2500);
	cout << "Since this is our first time exploring these numbers, let us consider only positive numbers\n" << endl;
	Sleep(2500);
	cout << "Binary only accepts either 0 or 1. When you enter a number, the following computation will be performed from right to left:" << endl;
	cout << "(Your Number) * (2^(Digit value)) " << endl;
	cout << "Digit value represents whatever the digit number is from right to left, minus 1" << endl;
	Sleep(2700);
	cout << "For example, the number\n00001011\nwill calculate the following for each digit number\n" << endl;
	cout << "[1 * (2^0)]   +   [1 * (2^1)]    +    [0 * (2^2)]    +    [1 * (2^3)]" << endl << endl;
	cout << "This pattern will continue on and on until all the digits are accounted for. " << endl;
	Sleep(2500);
	cout << "Does that make sense? y/n" << endl;		// Ask the user to confirm that they can follow along
	cin >> introRepeat;
	if (introRepeat == "y" or introRepeat == "yes") {	// If they can, then we will continue to the excersize portion
		cout << "Ok! Let's explore some more!\n" << endl;
		Sleep(2500);
		binaryToDecimal();						// This function is the excersize portion for this numbering system
		return 0;								// Return 0 so code does not break
	}
	else {								// If it doesn't make sense, this introduction section will repeat
		cout << "That's ok! Lets go over it again" << endl;
		Sleep(3000);
		binaryToDecimalINTRO();
		return 0;						// Return 0 so code does not break
	}

}


int decimalToOctal() {												     // Conversion code
	int number;								// create integer called number
	int result = 0;						// create integer called result
	cout << "Try entering any positive integer number: " << endl;			// prompt for input
	cin >> number;					// number holds input
	cout << number << " in octal is ";		// start printing the answer
	int remaining;				// create remainder variable
	int i = 1;			// incrementing variable
	while (number != 0) {			// loop will run as long as number is not 0
		remaining = number % 8;				// remainder modulus with 8
		number /= 8;			// divide number (avoid infinite loop)
		result += remaining * i;			// build up result
		i *= 10;			// increment i
	}
	cout << result;		// finish printing result
	string again = ""; 			// take in input to repeat
	cout << "\nWould you like to try again with a different number? y/n" << endl;
	cin >> again; 			// if yes, will repeat, if no then goodbye
	if (again == "y") {
		decimalToOctal();
		return 0;
	}
	else {
		cout << "Hope this program helped! Goodbye!" << endl;
		return 0; 			// failsafe
	}
	return 0; 		// failsafe
}


int decimalToOctalINTRO() {										// INTRO
	string introRepeat = "";    // Create a variable for giving the user an option to repeat the explanation
	// BEGIN INTRODUCTION:
	cout << "Similar to how 'deci' in 'decimal' means 10, 'octal' means 8" << endl;
	Sleep(2500);
	cout << "This means that each number place in octal carries some values times 8^(place value)" << endl;
	Sleep(2500);
	cout << "Each place value for octal numbers can have a number that is in the range 0-9" << endl;
	Sleep(2500);
	cout << "To convert from decimal to 8- bit octal, you just need to take the number you have and divide it by 8^7" << endl;
	Sleep(2500);
	cout << "Whatever the whole number part in the result is your first digit" << endl;
	Sleep(2500);
	cout << "Now do some subtraction; (Number you originally had - (number from division * (8*7)) = new number" << endl;
	Sleep(2500);
	cout << "Repeat the above steps, but now you should use 8^6. Keep doing this until you reach 8^0" << endl;
	Sleep(2500);
	cout << "Does that make sense? y/n" << endl;		// Ask the user to confirm that they can follow along
	cin >> introRepeat;
	if (introRepeat == "y" or introRepeat == "yes") {	// If they can, then we will continue to the excersize portion
		cout << "Ok! Let's explore some more!\n" << endl;
		Sleep(2500);
		decimalToOctal();						// This function is the excersize portion for this numbering system
		return 0;								// Return 0 so code does not break
	}
	else {								// If it doesn't make sense, this introduction section will repeat
		cout << "That's ok! Lets go over it again" << endl;
		Sleep(3000);
		decimalToOctalINTRO();
		return 0;						// Return 0 so code does not break
	}
}


int octalToDecimal() {												     // Conversion code
	cout << "Enter an 8 bit octal number " << endl;
	cout << "For example, if you wanted to type in 15, type in 00000015: " << endl;
	char numbers[8];		// Create a character array of 8 spaces (Allows for user to type in all the numbers at once
	cin >> numbers;			// Take in users octal numbers in array format
	int counter = 0;		// Counter will know how many digits to consider
	int reversecounter = 7;	// Array spot 0 will need to have the exponent be 7, so reverse counter handles that
	int total = 0;			// Total adds up the result
	while (counter < 8) {	// While loop does the calculation efficiently
		total = total + ( numbers[counter] - 48 ) * pow(8, reversecounter); // Perform exponential calculation while accounting for the variable type shift (from ASCII)
		counter++;				// Increment the counter up to 7
		reversecounter--;       // Decrement the reverse counter down to 0 so loop will eventually end
	}
	cout << "The octal number " << numbers << " in decimal notation is: " << total << endl;  // Assuming all previous conditions are met, the calculation will be made
	ofstream resultFile;								// Create a object called resultFile
	resultFile.open("Octal to Decimal - Results.txt", ios::app);			// Create a text file to include all of the users inputs and results (open it in append mode)
	resultFile << "The octal number you entered was " << numbers;			// Append the users input to it
	resultFile << "\nThat number in decimal notation was " << total << "\n\n\n";		// Append the result to it
	resultFile.close();												// DO NOT keep the file open
	string repeatSection = "";					// Provide user with an option to repeat this section of the program
	cout << "Would you like to try this excerise again with a different number? y/n" << endl;
	cin >> repeatSection;			// Take in the repeat option
	if (repeatSection == "y" or repeatSection == "Yes") {
		cout << "OK! Let's try again with a different number\n\n\n" << endl;
		octalToDecimal();				// If yes, then this section of the program will repeat
		return 0;					// Return 0 so code does not break
	}
	else {				// If not, program will end
		cout << "OK! Hopefully you've learned some stuff with this program!" << endl;
		cout << "For your reference, you can find a record with all of your inputs in a file called 'Results' " << endl;
		cout << "It is saved in this programs folder" << endl;
		Sleep(1500);
		cout << "Thanks for using this program! Goodbye!" << endl;
		return 0;
	}
}


int octalToDecimalINTRO() {									// INTRO
	cout << "Converting from octal to decimal is easy " << endl;
	Sleep(2500);
	cout << "The last digit you have corresponds to the (8^1) place" << endl;
	Sleep(2500);
	cout << "The next place is (8^2)" << endl;
	Sleep(2500);
	cout << "Then so on and so forth" << endl;
	Sleep(2500);
	cout << "Each time, just take the number that you have in that place and multiply it by the corresponding place" << endl;
	Sleep(2500);
	cout << "Add all of the numbers together" << endl;
	Sleep(2500);
	cout << "Now let's actually try it out" << endl;
	octalToDecimal();
	return 0;
}


int decimalToHexadecimal() {							// Conversion code
	cout << "Enter a decimal number that you want to see in hex" << endl; // prompt for input
	long int decimalNum;                                     // define some variables
	long int quotient;
	char resultNumber[100];							// define char resultNumber
	cin >> decimalNum;								// take in the decimal number of the user
	quotient = decimalNum;					// give quotient value of decimalNum
	int i = 1;					// int i will be 1
	int j;					// defint j and temporary num
	int temporaryNum;
	while (quotient != 0) {				// section of code will run until quotient = 0
		temporaryNum = quotient % 16;				// use modulus with 16 to get remainder
		if (temporaryNum < 10) {					// make sure that the number is not below 10 (if so, then numerical digits are shown on screen)
			temporaryNum = temporaryNum + 48;		// character manipulation (ASCII table)
		}
		else {
			temporaryNum = temporaryNum + 55;			// Otherwise, letters must be shown on screen
		}
		resultNumber[i++] = temporaryNum;				// build up resultNumber array using the temporary num value
		quotient = quotient / 16;					// divide quotient by 16 to progress code
	}
	cout << "The number " << decimalNum << " in hex is: " ;			// print out result using a for loop
	for (j = i - 1; j > 0; j--) {
		cout << resultNumber[j];
	}
	cout << "\n\nWould you like to try again with a different number? y/n" << endl;			// see if user wants to try again with different number
	string repeatDecHex;
	cin >> repeatDecHex;
	if (repeatDecHex == "y") {				// repeat program
		cout << "\n\n\n";
		decimalToHexadecimal();
	}
	else {						// end program
		return 0;
	}
	return 0;			// failsafe
}


int decimalToHexadecimalINTRO() {					// INTRO
	cout << "To convert a decimal into hexadecimal,\ndivide the decimal number by 16" << endl;
	Sleep(2500);
	cout << "Be sure to write down the remainder using this chart" << endl;
	Sleep(2500);
	cout << "Hexadecimal: 0  1  2  3  4  5  6  7  8  9  A   B   C   D   E   F" << endl;
	cout << "Decimal:     0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15 " << endl;
	Sleep(2500);
	cout << "Repeat the process until you get to a remainder of 0\nWhatever your remainder numbers are will be your hexadecimal numbers" << endl;
	Sleep(2500);
	cout << "Let's practice with real numbers" << endl;
	decimalToHexadecimal();
	return 0;
}


int hexadecimalToDecimal() {									        // Conversion code
	int userNum;
	string repeatHexDec;
	cout << "Enter a number you would like to see (from hexadecimal to decimal)" << endl;
	cin >> hex >> userNum;								// take in the users number as a hex value
	cout << "That number in decimal is: ";
	cout << dec << userNum;								// output it as a decimal value
	cout << "\nWould you like to try again with a different number? y/n" << endl;			// prompt for repeat
	cin >> repeatHexDec;
	if (repeatHexDec == "y") {
		cout << "\n\n\n";
		hexadecimalToDecimal();				// repeat
		return 0;
	}
	else {
		return 0;					// end program
	}
	return 0;					// failsafe
}


int hexadecimalToDecimalINTRO() {
	cout << "Hexadecimal means that there is 16 different\ncharacters that hold number values" << endl;
	Sleep(2500);
	cout << "The numbers are 0-9, then A-F" << endl;
	Sleep(2500);
	cout << "A corresponds to 10, B corresponds to 11\nC corresponds to 12, and so on and so forth" << endl;
	Sleep(2500);
	cout << "Each place value corresponds to 15^(place value - 1)" << endl;
	cout << "After you write out your number, you can add up all the terms" << endl;
	Sleep(2500);
	cout << "Lets some actual calculations" << endl;
	hexadecimalToDecimal();
	return 0;
}


// INTRODUCTION AND MENU NAVIGATION CODE //
int main() {
	cout << "Welcome to Ultimate Converter.\nThis program aims to teach you the many types of numbering systems for computers & computations" << endl;  // Basic intro
	Sleep(3000);
	cout << "\n\nPlease Choose one of the following options (enter the option's name followed by the enter key)" << endl;    // Prompt for input
	Sleep(1500);
	// MENU:
	cout << "Decimal to Binary      [1]" << endl;
	cout << "Binary to Decimal      [2]" << endl;
	cout << "Decimal to Octal       [3]" << endl;
	cout << "Octal to Decimal       [4]" << endl;
	cout << "Decimal to Hexadecimal [5]" << endl;
	cout << "Hexadecimal to Decimal [6]" << endl;

	string menuChoice;				     // Create variable for menu choice
	menuChoice.clear();					// Clear the choice to prevent a false loop with if statements
	getline(cin, menuChoice);			// Take in the whole line that user types


	if (menuChoice == "decimal to binary" or menuChoice == "Decimal to Binary" or menuChoice == "1") {    // Option 1
		cout << "OK! Let's talk about Decimal to Binary systems\n" << endl;
		Sleep(1500);
		decimalToBinaryINTRO();
	}

	else if (menuChoice == "binary to decimal" or menuChoice == "Binary to Decimal" or menuChoice == "2") {    // Option 2
		cout << "OK! Let's talk about Binary to Decimal systems\n" << endl;
		Sleep(1500);
		binaryToDecimalINTRO();							// Go to explanation section of numbering system
	}

	else if (menuChoice == "decimal to octal" or menuChoice == "Decimal to Octal" or menuChoice == "3") {                           // Option 3
		cout << "OK! Let's talk about Decimal to Octal systems\n" << endl;
		Sleep(1500);
		decimalToOctalINTRO();
	}

	else if (menuChoice == "octal to decimal" or menuChoice == "Octal to Decimal" or menuChoice == "4") {                          // Option 4
		cout << "OK! Let's talk about Octal to Decimal systems\n" << endl;
		Sleep(1500);
		octalToDecimalINTRO();
	}

	else if (menuChoice == "Decimal to Hexadecimal" or menuChoice == "decimal to hexadecimal" or menuChoice == "5") {             // Option 5
		cout << "OK! Let's talk about Decimal to Hexadecimal systems\n" << endl;
		Sleep(1500);
		decimalToHexadecimalINTRO();
	}

	else if (menuChoice == "Hexadecimal to Decimal" or menuChoice == "hexadecimal to decimal" or menuChoice == "6") {             // Option 6
		cout << "OK! Let's talk about Hexadecimal to Decimal systems\n" << endl;
		Sleep(1500);
		hexadecimalToDecimalINTRO();
	}

	else {                                                                             // Failsafe in case user doesn't pick proper option
		cout << "Sorry, you didn't pick an option. Let's restart the program to try again!\n\n\n" << endl;
		Sleep(1500);
		main();							// If user didn't pick a proper option, main will run again
	}
	return 0;
}
