#include "BigDecimalInt.h"



bool BigDecimalInt::check_number(string s)
{
	sign = '+';
	for (size_t i = 0; i < s.length(); i++)
	{
		if (i == 0) {
			if (!( s[i] == '+' || s[i] == '-' || isdigit(s[i]))) {

				return false;
			}
			else if(s[i] == '+' || s[i] == '-') {
				sign = s[i];
				has_sign = true;
			}
		}
		else {
			if ( !(isdigit( s[i]) ) ) {
				return false;
			}
		}
	}

	return true;
}


BigDecimalInt::BigDecimalInt( string number )
{

	if (!check_number(number)) {
		cout << "invalid number" << endl;
	}
	else {
		string x;
		for (size_t i = 0; i < number.length(); i++)
		{
			if ( i==0 && has_sign ) {
				continue;
			}
			else {
				x = number[i];
				num.push_back(stoi(x));
			}
		}
		
	}
}


BigDecimalInt::BigDecimalInt(int number) : BigDecimalInt( to_string(number) )
{

}

BigDecimalInt::BigDecimalInt()
{
}


BigDecimalInt BigDecimalInt::operator+(BigDecimalInt second)
{

	BigDecimalInt f , p;
	f.num = num;
	f.sign = sign;
	f.has_sign = has_sign;
	if (sign == '+' && second.sign == '-') {
		second.sign = '+';
		 p = f - second;
		 second.sign = '-';
		 return p;
		 /* here */
	}
	else if (sign == '-' && second.sign == '+') {
		f.sign = '+';
		p = second - f;
		f.sign = '-';
		return p;


	}










	int i, j;
	bool our = false;
	if (second.num.size() > num.size()) {
		i = second.num.size() - 1;
		j = num.size() - 1;
	}
	else {
		our = true;
		i = num.size() - 1;
		j = second.num.size() - 1;

	}

	int sum = 0;
	string final = "";
	string use = "";

	while (i >= 0 || j >= 0)
	{
		if (our) {
			if ( j < 0 ) {
				sum = num[i];

			}
			else {
				sum = num[i] + second.num[j];

			}
			
			use = to_string(sum % 10);
			sum /= 10;        
			use += final;  
			final = use;				 
			use = "";

			if (sum  > 0 ) {

				if ( i == 0 ) {
					use = to_string(sum % 10);
					use += final;
					final = use;
					use = "";
				}
				else {
					num[i - 1] += sum % 10;

				}

			}
			--i;
			--j;
		}
		else {
			if ( j < 0) {
				sum = second.num[i];

			}
			else {
				sum = num[j] + second.num[i];

			}
			use = to_string(sum % 10);
			use += final;
			final = use;
			use = "";
			sum /= 10;
			if (sum > 0) {

				if (i == 0) {
					use = to_string(sum % 10);
					use += final;
					final = use;
					use = "";
				}
				else {
					second.num[i - 1] += sum % 10;

				}

			}
			--i;
			--j;
		}
		 
			
	}



	while (true)
	{
		if (final[0] == '0') {
			final.erase(0,1);
		}
		else {
			break;
		}

	}


	BigDecimalInt s ( final );
	if (second.sign == '-' && sign == '-') {
		s.sign = '-';
	}
	
	return s;

}


void BigDecimalInt::print()
{
	if (sign == '-') {
		cout << sign;

	}


	for (size_t i = 0; i < num.size(); i++)
	{

		cout << num[i];
	}


	cout << endl;
}


bool BigDecimalInt::operator<(BigDecimalInt second)/*  first < second    */
{
	while (num.size() != 1 )
	{
		if (num[0] == 0) {
			num.erase(num.begin());
		}
		else {
			break;
		}

	}


	while (second.num.size() != 1)
	{
		if (second.num[0] == 0) {
			second.num.erase(second.num.begin());
		}
		else {
			break;
		}

	}
	

	if(second.sign != sign){
		if (second.sign == '-') {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (sign == '-') {
			if (num.size() > second.num.size()) {
				return true;
			}

			else if(num.size() < second.num.size()) {
				return false;
			}
			else {/**/
				for (size_t i = 0; i < num.size(); i++)
				{
					if (second.num[i] > num[i]) {
						return false;
					}
					else if (second.num[i] < num[i] ) {
						return true;
					}
				}
				return false;
			}
		}
		else {
			if (num.size() > second.num.size()) {
				return false;
			}
			else if (num.size() < second.num.size()) {
				return true;
			}
			else {
				/* here */
				for (size_t i = 0; i < num.size(); i++)
				{
					if (second.num[i] > num[i]) {
						return true;
					}
					else if (second.num[i] < num[i]) {
						return false;
					}
				}
				return false;
			}
		}
	}
}


char BigDecimalInt::get_sign() {
	return sign;
}

int BigDecimalInt::get_size() {
	return num.size();
}



bool BigDecimalInt::operator==(BigDecimalInt second) {

	if (num.size() == second.num.size() && sign == second.sign) {
		if (second.sign == '-') {
			for (size_t i = 0; i < num.size(); i++)
			{
				if (second.num[i] < num[i]) {
					return false;
				}
				else if (second.num[i] > num[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			for (size_t i = 0; i < num.size(); i++)
			{
				if (second.num[i] < num[i]) {
					return false;
				}
				else if (second.num[i] > num[i]) {
					return false;
				}
			}
			return true;
		}

	}
	else {
		return false;
	}
}

