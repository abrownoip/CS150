#include <iostream>
#include <iomanip>

using namespace std;

///Function prototypes for getting adjusted rent and getting the profit
double getAdjustedRent(int, int, double, double);
double getProfit(int, double, double);

int main()
{
	///Declaration and assignment of needed variables
	int 	totalUnits = 0,
			rentedUnits = 0,
			vacantUnits = 0,
			finalRentedUnits = 0;
	double 	rentPerUnit = 0.0,
			increaseRent = 0.0,
			maintenanceCostPerUnit = 0.0,
			profit = 0.0,
			finalAdjustedRent = 0.0,
			adjustedRent = 0.0,
			totalIncreasedRent = 0.0,
			totalRent = 0.0, 
			maintenanceCost = 0.0;	

	///User prompts for information
	cout << "Enter the number of units: ";
	cin >> totalUnits;
	cout << endl;
	cout << "Enter rent for each unit: ";
	cin >> rentPerUnit;	
	cout << endl;
	cout << "Enter maintenance expense for each rented unit: ";
	cin >> maintenanceCostPerUnit;
	cout << endl;
	cout << "Enter the amount of rent increase per unit: ";
	cin >> increaseRent;
	cout << endl;

	///Set maxprofit equal to zero before loop begins to do comparison at end of loop
	double maxProfit = 0.0;

	///For loop starting with 0 units rented and running until units rented <= total units, incrementing each time	
	for(rentedUnits = 0; rentedUnits <= totalUnits; rentedUnits++)
	{
		///Call the getAdjustedRent function and save the return to adjustedRent
		adjustedRent =  getAdjustedRent(totalUnits, rentedUnits, increaseRent, rentPerUnit);

		///Call the getProfit function and save to profit
		profit = getProfit(rentedUnits, adjustedRent, maintenanceCostPerUnit);

		///If statement to determine if the current profit is greater than max profit, if so save
		///current profit to max profit, save adjusted rent to final adjusted rent, and save rented units
		///to final rented units
		///If not, continue with for loop
		if(profit > maxProfit)
		{
			maxProfit = profit;
			finalAdjustedRent = adjustedRent;
			finalRentedUnits = rentedUnits;
		}

	}
	///Output the max profit, final adjusted rent and final rented units from if statement
	cout << showpoint << fixed << setprecision(2);
	cout << "Maximum amount of units to rent: " << finalRentedUnits << endl;
	cout << "Adjusted rent per unit: $" << finalAdjustedRent << endl;
	cout << "Maximum profit: $" << maxProfit << endl << endl;
	return 0;
}

///Definition of get adjusted rent to calculate and return the adjusted rent
double getAdjustedRent(int totalUnits, int rentedUnits, double increaseRent, double rentPerUnit)
{
	///Declaration and assignment of needed variables
	int vacantUnits = 0;
	double totalIncreasedRent = 0;
	double adjustedRent = 0;
	vacantUnits = totalUnits - rentedUnits;
	totalIncreasedRent = increaseRent * vacantUnits;
	adjustedRent = rentPerUnit + totalIncreasedRent;
	return adjustedRent;
}

///Definition of get profit to calculate and return the total profit
double getProfit(int rentedUnits, double adjustedRent, double maintenanceCostPerUnit)
{
	///Declaration and assignment of needed variables
	double totalRent = 0;
	double maintenanceCost = 0;
	double profit = 0;
	totalRent =  rentedUnits * adjustedRent;
	maintenanceCost = rentedUnits * maintenanceCostPerUnit;
	profit = totalRent - maintenanceCost;
	return profit;
}