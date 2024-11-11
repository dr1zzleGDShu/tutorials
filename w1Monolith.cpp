#include <iostream>
#include <iomanip>
#include <tuple>
#include <cmath>

using namespace std;

namespace salaryHw {
	using namespace std;


	float calculateAnnualBaseSalary(int); //work out annual salary (no bonus)
	float calculateChristmasBonus(float); //work out Christmas bonus
	float calculateAnnualSalary(float, float); //work out final annual salary
	float calculateDecemberSalary(float, float); //work out December salary
	int myClampInt(int, int, int);


	int salaryHwMain()			//computeDecemberSalary
	{

		//read in the salary point
		cout << "Enter the salary point: ";
		int salaryPoint;
		cin >> salaryPoint;
		salaryPoint = myClampInt(1, 24, salaryPoint);
		const float annualBaseSalary = calculateAnnualBaseSalary(salaryPoint);
		//produce Christmas bonus
		const float christmasBonus = calculateChristmasBonus(annualBaseSalary);
		//produce final annual salary (incl. bonus)
		const float annualSalary = calculateAnnualSalary(annualBaseSalary, christmasBonus);
		//produce December salary (incl. bonus)
		const float decemberSalary = calculateDecemberSalary(annualBaseSalary, christmasBonus);

		const unsigned char poundSign(156);

		//output annual salary
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout << "Annual salary is: " << poundSign << annualSalary << endl;
		//output December salary
		cout << "December monthly salary is: " << poundSign << decemberSalary << endl;

		return 0;
	}



	float calculateAnnualBaseSalary(int pointsIn) {
		const float scalePointValue(2000.0f);
		//produce annual base salary (without bonus)
		return pointsIn * scalePointValue;
	}


	float calculateChristmasBonus(float annualBaseSalaryIn) {
		/*
		const float bonusRate(2.5f);
		return ((annualBaseSalaryIn * bonusRate) / 100.0f);
		*/
		return (annualBaseSalaryIn * 0.025);// - annualBaseSalaryIn; 
	}


	float calculateAnnualSalary(float annualBaseSalaryIn, float christmasBonusIn) {
		return annualBaseSalaryIn + christmasBonusIn;
	}


	float calculateDecemberSalary(float annualBaseSalary, float christmasBonus) {
		const float monthlySalary(annualBaseSalary / 12);
		return monthlySalary + christmasBonus;
	}


	int myClampInt(int minIn, int maxIn, int valueIn) {
		return (minIn <= valueIn) ? ((maxIn >= valueIn) ? valueIn : maxIn) : minIn;
	}

}

namespace calcDiscount {
	//float produceDiscountedPrice(tuple<float, float>);
	float produceDiscountedPrice();
	//tuple<float, float> getDiscountValues();
	void getDiscountValues();


	float myFloatClamp(float varIn, float minVar, float maxVar) {
		if (varIn < minVar) {
			return minVar;
		}
		else if (varIn > maxVar) {
			return maxVar;
		}
		return varIn;
	}


	int discountCalcMain() {
		//cout << produceDiscountedPrice(getDiscountValues());
		cout << produceDiscountedPrice();
		cout << endl;
		return 0;
	}


	//tuple<float, float> getDiscountValues() {
	void getDiscountValues(float& origPrice, float& discountPercent) {
		cout << "Input the value to discount\n£ ";

		//float origPrice;
		cin >> origPrice;
		cout << "Input the percent to discount\n";
		//float discountPercent;
		cin >> discountPercent;

		origPrice = abs(origPrice);

		discountPercent = myFloatClamp(discountPercent, 0, 100);

		//return tuple<float, float>(origPrice, discountPercent);
	}

	//float produceDiscountedPrice(tuple<float, float> inVars) {
	float produceDiscountedPrice() {

		float origPrice, discountPercent;

		getDiscountValues(origPrice, discountPercent);

		//float priceIn = get<0>(inVars);  float discountPercentIn = get<1>(inVars);

		float priceOut, discountValue;
		discountValue = origPrice * (discountPercent * 0.01);
		priceOut = origPrice - discountValue;

		priceOut = roundf(priceOut * 100) / 100; // round to nearest penny
		cout << "Final value after discount £"; // amazing bodge to get the formatting right
		return priceOut;
	}

}

namespace wc {
	using namespace std;				//using standard namespace

	int numberOfWords;					//declare variables
	char letter;
	char lastLetter = ' ';


	/* count number of words in a piece of text
	**/
	int wordCountMain()
	{
		cout << "\nThis program counts the number of words in a text ";
		cout << "\n(ending with '.', single spaces between words) ";
		cout << "\n-------------------------------------------------\n";
		numberOfWords = 0;					//initialise variables
		cout << "\nEnter a line of text: ";
		cin.get(letter);					//read any character (even space)...
		while (letter != '.') 			// ... and count words
		{
			if (letter == ' ') {
				//cout << "8" << letter << lastLetter << "8\n";
				if (lastLetter != letter) {
					numberOfWords = numberOfWords + 1;
					//cout << "\nword counted\n";
				}
			}

			lastLetter = letter;
			cin.get(letter);

		}
		if (numberOfWords >= 0)
			numberOfWords = numberOfWords + 1;	//take last word into account
		cout << "\nNumber of words: " << numberOfWords << ".\n";	//result
		//system("pause" );  				//to hold the output screen
		return(0);
	}

}

namespace unitConvert {
	using namespace std;


	tuple<float, float> readInImperialMeasurement();
	float convertFeetAndInchesIntoMetres(tuple<float, float>);
	void showMetricMeasurement(float);
	float calculateTotalInches(tuple<float, float>);
	float convertInchesToMetres(float);


	// implements convertLengthFromImperialToMetric program
	int unitConversionMain()
	{
		showMetricMeasurement(convertFeetAndInchesIntoMetres(readInImperialMeasurement()));
		return 0;
	}



	tuple<float, float> readInImperialMeasurement() {
		float feet, inches;
		cout << "Enter the number of feet: ";
		cin >> feet;
		cout << "Enter the number of inches: ";
		cin >> inches;
		tuple<float, float> toRet(feet, inches);
		return toRet;
	}



	float convertFeetAndInchesIntoMetres(tuple<float, float> inVars) {
		return convertInchesToMetres(calculateTotalInches(inVars));
	}



	void showMetricMeasurement(float lenIn) {
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout << "The length is: " << lenIn << " metres\n" << endl;
	}



	float calculateTotalInches(tuple<float, float> inVars) {
		float feet = get<0>(inVars);
		float inches = get<1>(inVars);
		float inchesPerFoot = 12;
		//get the measure in inches
		float lengthInInches = (feet * inchesPerFoot) + inches;
		return lengthInInches;
	}




	float convertInchesToMetres(float inchesIn) {
		// invars = feet, inches
		float cmsPerInch = 2.54;
		//convert it to metres
		float lengthInMs = (inchesIn * cmsPerInch) / 100;
		return lengthInMs;
	}

}

namespace calcAge {
	int calcAgeMain()
	{
		int birthYear;
		cout << "Enter your birth year: ";
		cin >> birthYear;
		cout << "This year you are (or will be) " << birthYear - 1901 << endl;
		return 0;
	}

}

int main() {
	//salaryHw::salaryHwMain();
	calcDiscount::discountCalcMain();
	//
	//wc::wordCountMain();
	//unitConvert::unitConversionMain();
	//calcAge::calcAgeMain();
	system("pause");

}