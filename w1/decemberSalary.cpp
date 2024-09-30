#include <iostream>
using namespace std;


int calcAnnualSalary(int);
int calcDecSalary(int);


int main(){
  int salPoints;
  cout << "Enter Salary points: ";
  cin >> salPoints;
  cout << "Annual salary is £" << calcAnnualSalary(salPoints) << endl;
  cout << "December salary is £" << calcDecSalary(salPoints) << endl;
  return 0;
}



int calcAnnualSalary(int pointsIn){
  int baseSal = pointsIn*2000;
  return baseSal*1.025;
}


int calcDecSalary(int pointsIn){
  int baseSal = pointsIn*2000;
  int bonus = (baseSal*1.025)-baseSal;
  return (baseSal/12)+bonus;
}
