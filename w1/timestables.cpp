#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
  cout << "Please enter your name: ";
  string name;
  cin >> name;

  string answer;
  cout << "\n" << name << ", are you ready to do some times tables? \n";
  cin >> answer;

  if ((answer == "yes") || ( answer == "y" ))
  {	//A
    int count = 0;
    int maxCount = 5;
    cout << "There we go....\n";
    cout << "TIMETABLE CALCULATIONS\n";
    srand(time(0));
    while (count < maxCount){
      int n1(rand() % 10); 
      int n2(rand() % 10); 
      cout << "\nWhat is " << n1 << " * " << n2 << "? ";
      int product;
      cin >> product;
      while (product != (n1 * n2))
      {
        cout << "\nError: Try again! \n";
        cout << "\nWhat is " << n1 << " * " << n2 << "? ";
        cin >> product;
      }
      cout << "Correct! Only " << maxCount - count -1 << " questions left\n";
      count++; 
      }
    cout << "welldone, all correct\n";
    }
  else 
  {
    cout << "Maybe some other time...\n";
  }

  cout << "\n\n";
  //system("pause");
  return 0;
}
