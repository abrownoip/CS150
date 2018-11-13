#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

	///Declaring and assigning required variables
	double airTemperature = 0.0, windVelocityMPH = 0.0, windChill = 0.0;
	ofstream outFile;

	///User prompts for air temperature and wind velocity
	cout << "Enter temperature in degrees Fahrenheit: ";
	cin >> airTemperature;
	cout << "Enter wind velocity in miles per hour: ";
	cin >> windVelocityMPH;
	cout << endl << endl;
	cout << fixed << showpoint << setprecision(2);

	///Formatted outputs
	cout << "The temperature " << setw(17) << setfill('.') << " " << right << airTemperature << " degrees Fahrenheit" << endl;
	cout << "The velocity " << setw(20) << setfill('.') << " " << right << windVelocityMPH << " miles per hour" << endl;

	////Calculating windchill and formatting the ouptut
	windChill = 35.74 + (0.6215 * airTemperature) - (35.75 * (pow(windVelocityMPH,0.16))) + (0.4275 * airTemperature) * (pow(windVelocityMPH,0.16));
	cout << "The Wind Chill Index " << setw(12) << setfill('.') << " " << right << windChill << " degrees Fahrenheit" << endl << endl << endl;

	///Beginning of if/else statements determining if frostbite will occur and at what time period
	if ((windChill < -19) && (windChill > -48))
	{
		cout << setw(55) << setfill('*') << right << " " << endl;
		cout << "*" << setw(53) << setfill(' ') << "*" << endl;
		cout << "* Warning: Frostbit will occur in 30 minutes or less *" << endl;
		cout << "*" << setw(53) << setfill(' ') << "*" << endl;
		cout << setw(55) << setfill('*') << right << " " << endl << endl;
	}
	else if (windChill < -48)
	{
		cout << setw(55) << setfill('*') << right << " " << endl;
		cout << "*" << setw(53) << setfill(' ') << "*" << endl;
		cout << "* Warning: Frostbite will occur in 5 minutes or less *" << endl;
		cout << "*" << setw(53) << setfill(' ') << "*" << endl;
		cout << setw(55) << setfill('*') << right << " " << endl << endl;
	}
	
	///Opening the output file
	outFile.open("outputFile.txt");

	///Sending the same output as above to the output file
	outFile << fixed << showpoint << setprecision(2);
	outFile << "The temperature " << setw(17) << setfill('.') << " " << right << airTemperature << " degrees Fahrenheit" << endl;
	outFile << "The velocity " << setw(20) << setfill('.') << " " << right << windVelocityMPH << " miles per hour" << endl;
	outFile << "The Wind Chill Index " << setw(12) << setfill('.') << " " << right << windChill << " degrees Fahrenheit" << endl << endl << endl;
	
	///Same if/else as above except going to the output file
	if ((windChill < -19) && (windChill > -48))
	{
		outFile << setw(55) << setfill('*') << right << " " << endl;
		outFile << "*" << setw(53) << setfill(' ') << "*" << endl;
		outFile << "* Warning: Frostbit will occur in 30 minutes or less *" << endl;
		outFile << "*" << setw(53) << setfill(' ') << "*" << endl;
		outFile << setw(55) << setfill('*') << right << " " << endl << endl;
	}
	else if (windChill < -48)
	{
		outFile << setw(55) << setfill('*') << right << " " << endl;
		outFile << "*" << setw(53) << setfill(' ') << "*" << endl;
		outFile << "* Warning: Frostbite will occur in 5 minutes or less *" << endl;
		outFile << "*" << setw(53) << setfill(' ') << "*" << endl;
		outFile << setw(55) << setfill('*') << right << " " << endl << endl;
	}
	
	///Closing the output file
	outFile.close();

	return 0;
}