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


int main()
{

	

	
	
	
    
}
