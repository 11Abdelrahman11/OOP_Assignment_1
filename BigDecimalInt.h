#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class BigDecimalInt
{
private:
	vector<int> num;
	char sign = '+';
	bool has_sign = false;
public:
	BigDecimalInt(string number); 
	BigDecimalInt(int number);
	bool check_number(string s);
	BigDecimalInt operator+(BigDecimalInt second);
	friend BigDecimalInt operator-(BigDecimalInt first,BigDecimalInt second);
	void print();
	bool operator<(BigDecimalInt second);
	bool operator==(BigDecimalInt other);
	friend bool operator>(BigDecimalInt first, BigDecimalInt second);
	friend ostream& operator<<(ostream& os, BigDecimalInt first);
	char get_sign();
	int get_size();



	

};

