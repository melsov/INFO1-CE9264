#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	//Output graph paper.
	
	cout << "How many rows (e.g., 10)? \n";
	int nrows = 4;	//initialized for easier troubleshooting
	cin >> nrows;
	
	cout << "How many columns (e.g., 10)? \n";
	int ncols = 3;	
	cin >> ncols;
	
	cout << "How many characters wide is each column?\n";
	int charpercol = 5;
	cin >> charpercol;
	
	cout << "How many characters high is each row?\n";
	int charperrow = 5;
	cin >> charperrow;
	
	cout << "Graph paper with " << nrows << " rows, " << ncols << " columns, " << charpercol << " characters per column, " << charperrow << " characters per row: \n";
	
	for (int i=0; i< nrows; ++i)
	{
		for (int j = 0; j < ncols; ++j) 
		{
			cout << "+";
				for (int b=0; b < charpercol; ++b) 
				{
					cout << "-";
				}
		}
		cout << "\n";
		
		for (int e=0; e< charperrow; ++e) 
		{
			for (int j = 0; j < ncols; ++j) 
			{
				cout << "|";
				for (int b=0; b < charpercol; ++b) 
				{
					cout << " ";
				}
			}
			cout << "\n";
		}
	}
	
	return EXIT_SUCCESS;
}