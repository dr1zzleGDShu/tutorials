#include <iostream>
using namespace std;


float calcAnnualSalary(int);
float calcDecSalary(int);


int main(){
  int salPoints;
  cout << "Enter Salary points: ";
  cin >> salPoints;
  cout << "Annual salary is £" << calcAnnualSalary(salPoints) << endl;
  cout << "December salary is £" << calcDecSalary(salPoints) << endl;
  return 0;
}



float calcAnnualSalary(int pointsIn){
  float baseSal = pointsIn*2000;
  return baseSal*1.025;
}


float calcDecSalary(int pointsIn){
  float baseSal = pointsIn*2000;
  float bonus = (baseSal*1.025)-baseSal;
  return (baseSal/12)+bonus;
}
