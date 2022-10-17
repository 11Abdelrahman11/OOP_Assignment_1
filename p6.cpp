// p6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

void fractal_Pattern(int n, int i) {
	if (n == 0) {
		return;
	}
	else {
		fractal_Pattern(n / 2, i);
		for (size_t j = 0; j < i; j++)
		{
			cout << ' ';
		}
		for (size_t k = 0; k < n ; k++)
		{
			cout << '*';
		}
		cout << endl;
		fractal_Pattern(n/2, i + n / 2);
	}
}

int main()
{
	int num1, num2;
	cout << "Enter Two Numbers: ";
	cin >> num1 >> num2;
	fractal_Pattern(num1, num2);
}

