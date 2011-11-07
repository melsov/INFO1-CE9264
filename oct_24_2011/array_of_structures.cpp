#include <iostream>
#include <cstdlib>
#include <string>//for string
using namespace std;

struct batter {
  string name;
  int average;
};

int main()
{
	cout << "=-=-=-=BASEBALL GAME SIMULATOR=-=-=-=\n";
	batter roster[] = 
	{
		{"Casey", 344},
		{"Bloomfield", 545},
		{"Barry", 344},
		{"Canseco", 233},
		{"Pujols", 355},
		{"Carter", 255},
	};
	const size_t n = sizeof roster / sizeof roster[0];

	srand(static_cast<unsigned>(time(0)));
	
	int outs = 0;
	for (size_t i = 0; i < n; ++i)
	{
	  if (roster[i].average >= rand() % 1000)
	  {
		  cout << roster[i].name << " got a hit";  
	  }
	  else 
	  {
		  cout << roster[i].name << " made an out";
		  ++outs;
	  }

	  cout << "\n";
		if (outs == 3) 
		{
			cout << "The inning is over";
			break;
		}
	}
	

  return EXIT_SUCCESS;
}
