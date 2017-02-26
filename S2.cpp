#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
  int tc = 100, i;
  time_t t;
  /* Intializes random number generator */
  srand((unsigned) time(&t));
  cout << tc << endl;
  for (i = 1; i<= tc; i++)
  {
    cout << rand() << "  ";
  }
  cout << endl;
  return 0;
}
