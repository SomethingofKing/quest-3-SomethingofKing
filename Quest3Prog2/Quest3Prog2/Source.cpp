#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


	class Fraction
	{
	private:

		int numerator, denominator;
	public:
		Fraction()
		{
			this->numerator = 0;  //placeholders
			this->denominator = 0;
		}
		Fraction(int numerator, int denominator)
		{
			this->numerator = numerator;
			this->denominator = denominator;
		}

		int getNumerator()
		{
			return this->numerator;
		}
		int getDenominator()
		{
			return this->denominator;
		}

		void setNumerator(int num)
		{
			this->numerator = num;
		}
		void setDenominator(int denom)
		{
			this->denominator = denom;
		}
		void reduce()
		{
			int min;
			// find the minimum of the denom and numer
			min = denominator < numerator ? denominator : numerator;
			for (int i = 2; i <= min; i++)
			{
				while ((numerator % i == 0) && (denominator % i == 0))
				{
					numerator /= i;
					denominator /= i;
				}
			}

		}

		Fraction operator+(Fraction addition)
		{
			Fraction fraction(numerator*addition.denominator + denominator * addition.numerator, denominator*addition.denominator);
			fraction.reduce();
			return fraction;
		}

		Fraction operator-(Fraction subtraction)
		{
			Fraction fraction(numerator*subtraction.denominator - denominator * subtraction.numerator, denominator*subtraction.denominator);


			if (fraction.getDenominator() < 0 || fraction.getNumerator() < 0)
			{
				fraction.setNumerator(-1 * fraction.getNumerator());
				fraction.reduce();
				fraction.setNumerator(-1 * fraction.getNumerator());

			}
			else
			{
				fraction.reduce();
			}
			return fraction;
		}


		Fraction operator*(Fraction multiplication)
		{
			Fraction fraction(numerator*multiplication.numerator, denominator*multiplication.denominator);
			fraction.reduce();
			return fraction;
		}

		Fraction operator/(Fraction division)
		{
			Fraction fraction(numerator*division.denominator, denominator*division.numerator);
			fraction.reduce();
			return fraction;
		}

		void Print()
		{
			cout << numerator << "/" << denominator << endl;
		}

		
	};

	class CSVReader {
		string fileName;
		string delimeter;

	public:
		CSVReader(string filename, string delm = ",") :
			fileName(filename), delimeter(delm)
		{ }
	};


	int main(){
		return 0;
	}