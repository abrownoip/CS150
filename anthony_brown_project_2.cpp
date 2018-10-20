///Including the iostream and fstream headers
#include <iostream>
#include <fstream>
#include <iomanip>

///Using the standard namespace
using namespace std;


///Defining the main function
int main (){

	///Declaring and assigning needed variables
	double weightOfMouseGrams = 0.0;
	double artificialColorsDoseMouseGrams = 0.0;
	double weightOfChildGrams = 0.0;
	double doseForChild = 0.0;
	double numberOfCandyBars = 0.0;

	///Declare and assign constant
	const int colorsGramsPerCandy = 2;
	ofstream outFile;

	///Begin starting prompts and user input
	cout << "Enter the weight of the mouse in grams" << endl;
	cin >> weightOfMouseGrams;
	cout << "Enter the Artificial Colors dose for the mouse in grams" << endl;
	cin >> artificialColorsDoseMouseGrams;
	cout << "Enter the weight of the child in grams" << endl;
	cin >> weightOfChildGrams;
	cout << endl;

	///Begin output of parameters and associated units
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "For these parameters:" << endl;

	///Fill empty space with dots, output floats in fixed notation always showing two decimal places
	///Using left and right for page justification
	cout << setfill('.') << fixed << showpoint << setprecision(2);
	cout << left << "mouse weight: " << setw(40) 
		<< right << " " << weightOfMouseGrams << " grams" << endl;
	cout << left << "Artificial Colors dose for the mouse: " << setw(16) 
		<< right << " " << artificialColorsDoseMouseGrams << " grams" << endl;
	cout << left << "Child weight: " <<  setw(40) 
		<<  right  << " " << weightOfChildGrams << " grams" << endl;

	///Calculate the dose for a child
	doseForChild = artificialColorsDoseMouseGrams * (weightOfChildGrams / weightOfMouseGrams);
	cout << left << "The Artificial Colors dose for the child is: " << setw(9) 
		<< right << " "  << doseForChild << " grams" << endl;

	///Calculate the number of harmful candy bars
	numberOfCandyBars = doseForChild / colorsGramsPerCandy;
	cout << left << "Number of candy bars that can harm a child: " << setw(10) << right << " " << numberOfCandyBars << " candy bars" << endl;

	///Open the needed output file
	outFile.open("output.txt");

	///Output the following to the output file
	outFile << endl;
	outFile << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	/*Setfill to have empty space taken up by dots between parameter and units, output floats in fixed notation, 
	always show the decimal point to two decimals*/
	outFile <<  setfill('.') << fixed << showpoint << setprecision(2);
	outFile << "For these parameters:" << endl;
	outFile << left << "mouse weight: " << setw(40) << right << " " << weightOfMouseGrams << " grams" << endl;
	outFile << left << "Artificial Colors dose for the mouse: " << setw(16) 
		<< right << " " << artificialColorsDoseMouseGrams << " grams" << endl;
	outFile << left << "Child weight: " <<  setw(40) 
		<< right << " " << weightOfChildGrams << " grams" << endl;
	outFile << left << "The Artificial Colors dose for the child is: " << setw(9) 
		<< right << " " << doseForChild << " grams" << endl;
	outFile << left << "Number of candy bars that can harm a child: " << setw(10) 
		<< right << " " << numberOfCandyBars << " candy bars" << endl;

	///Close the output file
	outFile.close();

	return 0;
}