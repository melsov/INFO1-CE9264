#include <iostream>//for cin, cout, clear, ignore, <<, >>                                                    
#include <cstdlib>
#include <climits>//for INT_MAX                                                                              
using namespace std;

int main()
{
  cout << "How many potatoes can you peel in 1 hour?\n";
  int fast;
  cin >> fast;

  if (!cin) {
    cerr << "That wasn't a number.\n";
    return EXIT_FAILURE;
  }

  cout << "For how many hours do you plan to peel potatoes?\n";
  int hrs;//uninitialized variable                                                                           
  cin >> hrs;

  if (!cin) {
    cerr << "That wasn't a number!!\n";
    return EXIT_FAILURE;
  }


  cout << "You will peel " << fast * hrs << " potatoes.\n";
  return EXIT_SUCCESS;
}
