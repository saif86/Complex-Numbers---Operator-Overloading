/**  Complex class to handle Complex numbers in a C++ code.
*
* #include "Complex.h" <BR>
* -llib
*
*/
#ifndef COMPLEX_H
#define COMPLEX_H

// SYSTEM INCLUDES
#include<iostream>
using std::string;


// Complex class definition
class Complex {
public:
	// LIFECYCLE
	/** Default + Overloaded constructor.
	*/
	Complex(double = 0.0, double = 0.0);

	/** Type conversion constructor (string ==> Complex).
	*/
	Complex(const string&);

	// Use compiler-generated copy constructor, assignment, and destructor.
	// Complex(const Complex&);
	// Complex& operator=(const Complex&);
	// ~Complex();


// OPERATORS
	/** Stream Insertion operator.
	*
	* @param rOs Standard Output Stream.
	* @param rFrom The value to be inserted to the output stream.
	*
	* @return A reference to the standard output stream.
	*/
	friend std::ostream& operator <<(std::ostream& rOs, const Complex& rFrom);

	/** Stream Extraction operator.
	*
	* @param rIs Standard Intput Stream.
	* @param rTo The value to be extracted from the input stream.
	*
	* @return A reference to the standard input stream.
	*/
	friend std::istream& operator >>(std::istream& rIs, Complex& rTo);

	// ADDITION
	/** Addition operator.
	*
	* @param rhs A reference to rhs addend.
	*
	* @return Sum of two Complex Numbers.
	*/
	Complex operator +(const Complex& rhs);

	/** Overloaded Addition operator.
	*
	* @param rhs Real(double) addend.
	*
	* @return Sum of Complex and real.
	*/
	Complex operator +(const double rhs);

	/** Friend function to overloaded Addition operator.
	*
	* @param lhs Real(double) augend.
	* @param rhs A reference to rhs addend.
	*
	* @return Sum of Real and Complex.
	*/
	friend Complex operator +(const double lhs, const Complex& rhs);
	
	/** Addition assignment operator.
	*
	* @param rhs A reference to rhs addend.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator +=(const Complex& rhs);
	

	/** Overloaded Addition assignment operator.
	*
	* @param rhs Real(double) addend.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator +=(const double rhs);
	

	// SUBTRACTION
	/** Subtraction operator.
	*
	* @param rhs A reference to rhs subtrahend.
	*
	* @return Difference of two Complex Numbers.
	*/
	Complex operator -(const Complex& rhs);

	/** Overloaded Subtraction operator.
	*
	* @param rhs Real(double) subtrahend.
	*
	* @return Difference of real from Complex number.
	*/
	Complex operator -(const double rhs);

	/** Friend function to overloaded Subtraction operator.
	*
	* @param lhs Real(double) minuend.
	* @param rhs A reference to rhs subtrahend.
	*
	* @return Difference of Real and Complex.
	*/
	friend Complex operator -(const double lhs, const Complex& rhs);

	/** Subtraction assignment operator.
	*
	* @param rhs A reference to rhs subtrahend.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator -=(const Complex& rhs);

	/** Overloaded Subtraction assignment operator.
	*
	* @param rhs Real(double) subtrahend.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator -=(const double rhs);


	// MULTIPLICATION
	/** Multiplication operator.
	*
	* @param rhs A reference to rhs multiplier/factor.
	*
	* @return Product of two Complex Numbers.
	*/
	Complex operator *(const Complex& rhs);

	/** Overloaded Multiplication operator.
	*
	* @param rhs Real(double) multiplier/factor.
	*
	* @return Product Complex and Real(double).
	*/
	Complex operator *(const double rhs);

	/** Friend function to overloaded Multiplication operator.
	*
	* @param lhs Real(double) multiplicand/factor.
	* @param rhs A reference to rhs multiplier/factor.
	*
	* @return Product Real(double) and Complex.
	*/
	friend Complex operator *(const double lhs, const Complex& rhs);

	/** Multiplication assignment operator.
	*
	* @param rhs A reference to rhs multiplier/factor.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator *=(const Complex& rhs);

	/** Overloaded Multiplication assignment operator.
	*
	* @param rhs Real(double) multiplier/factor.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator *=(const double rhs);


	// DIVISION
	// :KLUDGE: Saif 190123: possible division problem
	// We need to revise division operator as it creates 
	// wrong output especially while cascading
	// e.g. a/b/c/d != (a*d)/(b*c) ==> needs to be solved.
	// for just 2 complex operands, it works fine. a/b :)
	
	/** Division operator.
	*
	* @param rhs A reference to rhs divisor.
	*
	* @return Division of two Complex Numbers.
	*/
	Complex operator /(const Complex& rhs);

	/** Overloaded Division operator.
	*
	* @param rhs Real(double) divisor.
	*
	* @return Division of Complex by Real(double).
	*/
	Complex operator /(const double rhs);

	/** Friend function to overloaded Division operator.
	*
	* @param lhs Real(double) dividend.
	* @param rhs A reference to rhs divisor.
	*
	* @return Division of Real(double) by Complex.
	*/
	friend Complex operator /(const double lhs, const Complex& rhs);

	/** Division assignment operator.
	*
	* @param rhs A reference to rhs divisor.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator /=(const Complex& rhs);

	/** Overloaded Division assignment operator.
	*
	* @param rhs Real(double) divisor.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator /=(const double rhs);


	// EQUALITY
	/** Equality operator.
	*
	* @param rhs A reference to rhs Complex.
	*
	* @return True if equal, false otherwise.
	*/
	bool operator ==(const Complex& rhs);

	/** Non-Equality operator.
	*
	* @param rhs A reference to rhs Complex.
	*
	* @return True if not equal, false otherwise.
	*/
	bool operator !=(const Complex& rhs);


	// UNARY OPERATORS
	/** Negation operator.
	*
	* @param void.
	*
	* @return Negative of Complex Number.
	*/
	Complex operator -();

	/** Conjugate operator.
	*
	* @param void.
	*
	* @return Conjugate of Complex Number.
	*/
	Complex operator *();

	// INCREMENT OPERATOR
	/** pre-increment operator.
	*
	* @param void.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator ++();

	/** post-increment operator.
	*
	* @param dummy integer to overload increment operator.
	*
	* @return Incremented Complex Number.
	*/
	Complex operator ++(int);

	// DECREMENT OPERATOR
	/** pre-decrement operator.
	*
	* @param void.
	*
	* @return reference to (updated) current object.
	*/
	Complex& operator --();

	/** post-decrement operator.
	*
	* @param dummy integer to overload decrement operator.
	*
	* @return Decremented Complex Number.
	*/
	Complex operator --(int);

	/** Function operator to overload double
	* This converts Complex number to real
	*
	* @param void.
	*
	* @return converted Real(double) equivalent.
	*/
	operator double();


// ACCESS
	// setters
	void SetReal(double = 0.0);
	void SetImaginary(double = 0.0);
	void SetComplex(double = 0.0, double = 0.0);
	/**
	# @overload void SetComplex(const Complex&);
	*/
	void SetComplex(const Complex&);

	// getters
	double GetReal()const;
	double GetImaginary()const;
	const Complex& GetComplex()const;
	
private:
// INQUIRY
	/** utility function to check for leap year.
	*
	* @param testNumber The string to be tested for numbers.
	*
	* @return true if testNumber is numeric, false otherwise.
	*/
	bool Is_Number(const string& testNumber);


// DATA MEMBERS
	double mReal;
	double mImaginary;
};
// end class Complex
#endif  
// _COMPLEX_H_
