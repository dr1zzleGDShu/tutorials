#include <iostream>	//for cin >> and cout <<
#include <iomanip>	//for i/o manipulators
#include <tuple>
using namespace std;


tuple<float,float> readInImperialMeasurement();
float convertFeetAndInchesIntoMetres(tuple<float,float>);
void showMetricMeasurement(float);
float calculateTotalInches(tuple<float,float>);
float convertInchesToMetres(float);


// implements convertLengthFromImperialToMetric program
int unitConversionMain()
{
  showMetricMeasurement(convertFeetAndInchesIntoMetres(readInImperialMeasurement()));
  return 0;
}



tuple<float,float> readInImperialMeasurement(){
  float feet, inches;
  cout << "Enter the number of feet: ";
  cin >> feet; 
  cout << "Enter the number of inches: ";
  cin >> inches;
  tuple<float, float> toRet (feet,inches);
  return toRet;
}



float convertFeetAndInchesIntoMetres(tuple<float,float> inVars){
  return convertInchesToMetres(calculateTotalInches(inVars));
}



void showMetricMeasurement(float lenIn){
  cout.setf(ios::fixed);
  cout << setprecision(2);
  cout << "The length is: " << lenIn << " metres\n" << endl;
}



float calculateTotalInches(tuple<float,float> inVars){
  float feet = get<0>(inVars);
  float inches = get<1>(inVars);
  float inchesPerFoot = 12;
  //get the measure in inches
  float lengthInInches = (feet * inchesPerFoot) + inches;
  return lengthInInches;
}
  



float convertInchesToMetres(float inchesIn){
  // invars = feet, inches
  float cmsPerInch = 2.54;
  //convert it to metres
  float lengthInMs = (inchesIn * cmsPerInch) / 100;
  return lengthInMs;
}
  
