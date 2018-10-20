#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>

using namespace std;

int main()
{
	///Declaration and assignment of constants
	const float O_ATOMIC_WEIGHT = 15.9994;
	const float C_ATOMIC_WEIGHT = 12.011;
	const float N_ATOMIC_WEIGHT = 14.00674;
	const float S_ATOMIC_WEIGHT = 32.066;
	const float H_ATOMIC_WEIGHT = 1.00794;

	///Declaration and assignment of needed variables
	string aminoAcid = "";
	int numOxygenAtoms = 0, numCarbonAtoms = 0, numNitrogenAtoms = 0, numSulfurAtoms = 0, numHydrogenAtoms = 0;
	float molecularWeight = 0.0, averageWeight = 0.0;

	///Declaration of file stream variable
	fstream outData;

	///User prompts for information
	cout << "Enter amino acid: " << endl;
	getline(cin, aminoAcid);
	cout << "Enter number of oxygen atoms: " << endl;
	cin >> numOxygenAtoms;
	cout << "Enter number of carbon atoms: " << endl;
	cin >> numCarbonAtoms;
	cout << "Enter number of nitrogen atoms: " << endl;
	cin >> numNitrogenAtoms;
	cout << "Enter number of sulfur atoms: " << endl;
	cin >> numSulfurAtoms;
	cout << "Enter number of hydrogen atoms: " << endl;
	cin >> numHydrogenAtoms;

	///Output of entered information
	cout << setfill('.');
	cout << "The Results:" << endl;
	cout << left << "Name of amino acid: " << setw(50) << right << " " << aminoAcid << endl;
	cout << left << "Number of oxygen atoms: " << setw(46) << right << " " << numOxygenAtoms << endl;
	cout << left << "Number of carbon atoms: " << setw(46) << right << " " << numCarbonAtoms << endl;
	cout << left << "Number of nitrogen atoms: " << setw(44) << right << " " << numNitrogenAtoms << endl;
	cout << left << "Number of sulfur atoms: " << setw(46) << right << " " << numSulfurAtoms << endl;
	cout << left << "Number of hydrogen atoms: " << setw(44) << right << " " << numHydrogenAtoms << endl;

	///Calculation to get molecular weight from user entered information
	molecularWeight = (numOxygenAtoms * O_ATOMIC_WEIGHT) +
	 (numCarbonAtoms * C_ATOMIC_WEIGHT) +
	  (numNitrogenAtoms * N_ATOMIC_WEIGHT) +
	   (numSulfurAtoms * S_ATOMIC_WEIGHT) +
	    (numHydrogenAtoms * H_ATOMIC_WEIGHT);

	cout << left << "The molecular weight of the amino acid: " << setw(30) << right << " " << molecularWeight << endl;

	///Calculation to get average weight of atoms in molecule
	averageWeight = molecularWeight / (numOxygenAtoms + numCarbonAtoms +
		numNitrogenAtoms + numSulfurAtoms + numHydrogenAtoms);

	cout << left << "The average weight of the atoms in the amino acid: " << setw(19) << right << " " << averageWeight << endl;

	///Open the needed output file using fstream
	outData.open("outputFile.txt");

	outData << setfill('.');
	outData << "The Results:" << endl;
	outData << left << "Name of amino acid: " << setw(50) << right << " " << aminoAcid << endl;
	outData << left << "Number of oxygen atoms: " << setw(46) << right << " " << numOxygenAtoms << endl;
	outData << left << "Number of carbon atoms: " << setw(46) << right << " " << numCarbonAtoms << endl;
	outData << left << "Number of nitrogen atoms: " << setw(44) << right << " " << numNitrogenAtoms << endl;
	outData << left << "Number of sulfur atoms: " << setw(46) << right << " " << numSulfurAtoms << endl;
	outData << left << "Number of hydrogen atoms: " << setw(44) << right << " " << numHydrogenAtoms << endl;

	outData << left << "The molecular weight of the amino acid: " << setw(30) << right << " " << molecularWeight << endl;
	outData << left << "The average weight of the atoms in the amino acid: " << setw(19) << right << " " << averageWeight << endl;	

	///Close the output file
	outData.close();

	return 0;
}