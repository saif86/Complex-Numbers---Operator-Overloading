#ifndef Complex_H_
#define Complex_H_

#include <iostream>
using namespace std;

class Complex
{
	double real;
	double img;
	bool is_number(const string &);
public:
	Complex(double = 0.0, double = 0.0);			// Default + Overloaded constructor
	Complex(const Complex &);						// copy constructor
	Complex(const string &);						// type conversion constructor (string ==> Complex)
	
	// setters
	void setReal(double = 0.0);
	void setImaginary(double = 0.0);
	void setComplex(double = 0.0, double =  0.0);
	void setComplex(const Complex &);

	// getters
	double getReal()const;
	double getImaginary()const;
	Complex getComplex()const;

	// operators overloading
	// addition
	Complex operator +(const Complex &);
	Complex operator +(const double &);
	friend Complex operator +(const double &, const Complex & );
	Complex operator +=(const Complex &);
	Complex operator +=(const double &);
	
	// subtraction
	Complex operator -(const Complex &);
	Complex operator -(const double &);
	friend Complex operator -(const double &, const Complex &);
	Complex operator -=(const Complex &);
	Complex operator -=(const double &);
	
	
	// multiplication
	Complex operator *(const Complex &);
	Complex operator *(const double &);
	friend Complex operator *(const double &, const Complex &);
	Complex operator *=(const Complex &);
	Complex operator *=(const double &);
	
	
	// division
	Complex operator /(const Complex &);
	Complex operator /(const double &);
	friend Complex operator /(const double &, const Complex &);
	Complex operator /=(const Complex &);
	Complex operator /=(const double &);
	
	// equality operator
	bool operator == (const Complex &);
	// inverse equality operator
	bool operator != (const Complex &);

	// Unary operators
	// negation operator
	Complex  operator - ();
	// conjugate operator
	Complex  operator * ();
	// pre-increment
	Complex & operator ++ ();
	// post-increment
	Complex operator ++ (int);
	// pre-decrement
	Complex & operator -- ();
	// post-decrement
	Complex operator -- (int);

	// Type conversion operator
	operator double();  // converts Complex to double


	friend ostream & operator <<(ostream &, const Complex &);		// output stream
	friend istream & operator >>(istream &, Complex &);				// input stream
};
#endif