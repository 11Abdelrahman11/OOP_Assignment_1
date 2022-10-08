#include <iostream>
#include "BigDecimalInt.h"
using namespace std;

bool operator>(BigDecimalInt first, BigDecimalInt second) {
    if ( first.num.size() == second.num.size() && first.sign == second.sign ) {
		if( second.sign == '-'){
			for (size_t i = 0; i < first.num.size(); i++)
			{
				if (second.num[i] < first.num[i]) {
					return false;
				}
				else if (second.num[i] > first.num[i]) {
					return true;
				}
			}
			return false;
		}
		else {
			for (size_t i = 0; i < first.num.size(); i++)
			{
				if (second.num[i] < first.num[i]) {
					return true;
				}
				else if (second.num[i] > first.num[i]) {
					return false;
				}
			}
			return false;
		}
		
    }
	
    return ! ( first < second );
}

ostream& operator<<(ostream& os, BigDecimalInt first) {
	first.print();
	return os;
}


BigDecimalInt operator-( BigDecimalInt first ,BigDecimalInt second) {

	char si; 

	if (first.sign == second.sign ) {
		if (first.sign == '+') {
			if (first < second) {
				BigDecimalInt ci = second - first;
				ci.sign = '-';
				return ci;
			}
			else {
				si = '+';
			}
		}
		else {
			if (first > second) {
				first.sign = '+';
				second.sign = '+';
				BigDecimalInt ci = second - first;
				first.sign = '-';
				second.sign = '-';
				ci.sign = '+';
				return ci;

			}
			else {
				first.sign = '+';
				second.sign = '+';
				BigDecimalInt ci = first - second;
				first.sign = '-';
				second.sign = '-';
				ci.sign = '-';
				return ci;
			}
			
		}
		
	}
	else if (first.sign == '-' && second.sign == '+') {
			first.sign = '+';
			BigDecimalInt ci = first + second;
			first.sign = '-';
			ci.sign = '-';
			return ci;
	}
	else {
		second.sign = '+';
		BigDecimalInt ci = first + second;
		second.sign = '-';
		ci.sign = '+';
		return ci;
	}



	int i, j, sub;
	string final = "";
	string use = "";
	i = first.num.size() - 1;
	j = second.num.size() - 1;
	while (i >= 0 || j >= 0) {
		if (j < 0) {
			sub = first.num[i];

		}
		else {
			sub = first.num[i] - second.num[j];

		}
		if (0 > sub) {
			int x = i - 1;


			while (x != 0 && first.num[x] == 0) {
				first.num[x] = 9;
				--x;
			}
			first.num[x] -= 1;
			first.num[i] += 10;

			sub = first.num[i] - second.num[j];


		}

		use = to_string(sub);
		use += final;
		final = use;
		use = "";
		--i;
		--j;

	}

	while (final.length() != 1)
	{
		if (final[0] == '0') {
			final.erase(0, 1);
		}
		else {
			break;
		}

	}

	BigDecimalInt s(final);
	s.sign = si;
	return s;
}

int main()
{

	
	BigDecimalInt x1("113456789011345678901134567890");
	/* -2 - (- 5 )*/
	BigDecimalInt x2("123456789012345678901234567890");
	cout << x1 + x2;
	
	
	
    
}
