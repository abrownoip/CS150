#include <iostream>

using namespace std;

int main()
{
    ///Declare and assign needed variables: one array for sales per day
    ///one integer for totalSales
    int sales[7];
    int totalSales = 0;

    ///For loop to go thru each index of the sales array, prompting the user for input
    ///then saving the value from the index to totalSales
    for(int counter = 0; counter <= 6; counter++)
    {
        cout << "Enter the sales for day "<< counter + 1 << ": $";
        cin >> sales[counter];
        totalSales += sales[counter];
    }

    ///Output totalSales after daily sales have been added together
    cout << endl << "Total Sales: $" << totalSales << endl;
    return 0;
}
