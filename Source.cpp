/**
* @file Source.cpp
*
* @brief This code tests Operator Overloading on Complex numbers.
*
* @author Saif Ullah Ijaz
*
* TODO: Saif 190123: possible division problem while cascading.
* Use brackets carefully. For details see KLUDGE on line 183 in "Complex.h"
*
*/

// SYSTEM INCLUDES
#include<iostream>
using namespace std;

// LOCAL INCLUDES
#include "Complex.h"

// function main begins program execution
void main()
{
	Complex c1(23, 8), c2 = (string)"5+4i", c3("-5 + 0 j");
	
	
	Complex t0 = (c1 + 8. - c2 * c3);
	Complex t1 = 8. * (c1 + c3) - c2;
	Complex t2 = c2 * 8. / (c1 + c3);
	Complex t3 = c2 - 8. * (c3) / c1;
	Complex t4 = (c3) + (c1) - 8. * (c2);
	Complex t5 = (c3) * c2 + (c1) - 8.;
	cout << t0 << endl;
	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;
	cout << t4 << endl;
	cout << t5 << endl;

	Complex c4;
	c4 = (Complex)"23 + 8j";
	if (c4 != c2)
		cout << "Not Equal" << endl;
	else
		cout << "Equal" << endl;
	c4 = *c2;
	cout << "Conjugate of " << c2 << " is: " << c4 << endl;

	c1 /= c2;
	cout << c1 << endl;
	(c2 /= 2.325) = c3;
	cout << c2 << endl;

	double ab = c4;
	cout << ab << endl;
	
	system("pause");
}
// end main
