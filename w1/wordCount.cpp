/* This program counts the number of words in a piece of text. 
We'll assume that 
(a) it can only read in and process characters in text one at a time.
(b) words are separated by a single space 
(c) the last word in the text ends with a period '.'.
*/

#include <iostream>					//include input/output library
using namespace std;				//using standard namespace

int numberOfWords;					//declare variables
char letter;

/* count number of words in a piece of text
**/
int main()
{
	cout << "\nThis program counts the number of words in a text ";
	cout << "\n(ending with '.', single spaces between words) ";
	cout << "\n-------------------------------------------------\n";
	numberOfWords = 0;					//initialise variables
	cout << "\nEnter a line of text: ";
	cin.get(letter);					//read any character (even space)...
	while (letter != '.') 			// ... and count words
	{
		if (letter == ' ')
			numberOfWords = numberOfWords + 1;
		cin.get(letter);
	}
	if (numberOfWords >= 0)
		numberOfWords = numberOfWords + 1;	//take last word into account
	cout << "\nNumber of words: " << numberOfWords << ".\n";	//result
	//system("pause" );  				//to hold the output screen
	return(0);
}
