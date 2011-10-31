#include <iostream>
#include <cstdlib>
#include <cassert>//for assert
#include <algorithm>//for min
using namespace std;

int recursion_gcd(int a, int b, int test_number);

int main()
{
  cout << "The gcd of 30 and 105 is " << recursion_gcd(30, 105, min(30, 105)) << ".\n";
  return EXIT_SUCCESS;
}

int recursion_gcd(int a, int b, int test_number)
{
	assert(a >= 0 && b >= 0);
	if (a % test_number == 0 && b % test_number == 0){
		return test_number;
	}
	return recursion_gcd(a, b, --test_number);
}
