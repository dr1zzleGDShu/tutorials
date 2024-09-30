#include <iostream>
#include <iomanip>
using namespace std;


void secsToHMS(int);


int main(){
  int secsInputted;
  cout << "Enter a time in seconds: ";
  cin >> secsInputted;
  secsToHMS(secsInputted);
  return 0;
}

  /*
  if (intIn < 1){return "00";}
  else if (intIn < 11){return (const char*)("0"+intIn);}
  return (const char*)intIn;*/


void formatAndOutputInt(int intIn){
  //char toOut[2] = {'0','0'};
  if (intIn < 1){cout << "00";}
  else if (intIn < 10){cout << "0" << intIn;}
  else {cout << intIn;}
}


void secsToHMS(int secsIn){
  const char* hours; const char* mins; const char* secs;
  cout << "Time is: ";
  //hours = 
  formatAndOutputInt(secsIn / 3600);
  secsIn = secsIn%3600;
  cout << ":";
  //mins = 
  formatAndOutputInt(secsIn / 60);
  secsIn = secsIn%60;
  cout << ":";
  //secs = 
  formatAndOutputInt(secsIn);
  cout << endl;
  //cout << "Time is: " << hours << ":" << mins << ":" << secs << endl;
}
