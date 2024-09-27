#include <iostream>
using namespace std;


void secsToHMS(int);


int main(){
  secsToHMS(3723);
  return 0;
}


void secsToHMS(int secsIn){
  int hours, mins, secs;
  hours = secsIn / 3600;
  secsIn = secsIn%3600;
  mins = secsIn / 60;
  secsIn = secsIn%60;
  secs = secsIn/60;
  cout << "Time is: " << hours << ":" << mins << ":" << secs;
}
