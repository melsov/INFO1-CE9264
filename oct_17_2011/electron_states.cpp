#include <iostream>
#include <string>
using namespace std;

/*
Output all possible states of electrons with principal quantum number (n) <= 5 
*/



int main()
{
	for (int n = 1; n <= 5; ++n) {
		for (int l = n - 1; l >= 0; --l) {
			for (int m = -l; m <= l; ++m) {
				cout << "{ " << n << ", " << l << ", " << m << ", " << "-.5" << "}\n";
				cout << "{ " << n << ", " << l << ", " << m << ", " << ".5" << "}\n";
			}
		}
	}
}
