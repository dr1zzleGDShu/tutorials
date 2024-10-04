#include <iostream>
using namespace std;
int calcAgeMain()
{
  int birthYear;
  cout << "Enter your birth year: ";
  cin >> birthYear;
  cout << "This year you are (or will be) " << 1901 - birthYear << endl;
  return 0;
}
