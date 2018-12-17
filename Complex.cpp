#include "Complex.h"
#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

Complex::Complex(double x, double y) :real(x), img(y){

}

Complex::Complex(const Complex &obj) : real(obj.getReal()), img(obj.getImaginary()) { }

Complex::Complex(const string & aString) {
	int posPlus = aString.find("+");
	int posMinus = aString.find("-");
	int posSymbol = max(posPlus, posMinus);
	int posI = aString.find("i");
	int posJ = aString.find("j");
	int posImSymbol = max(posI, posJ);
	if (posSymbol == -1 || posImSymbol == -1) {
		if (this->is_number(aString) && posImSymbol == -1)
			this->setComplex(stod(aString));
		else if (this->is_number(aString) && posImSymbol != -1)
			this->setComplex(0,stod(aString));
		else {
			cout << "Provided string cannot be converted to complex number. Setting string to zero." << endl;
			this->setComplex();
		}
		
		return;
	}
	double realDouble = 1.0;
	double imaginaryDouble = 1.0;
	int posStart = -1;
	// for negative symbols
	if (posPlus == -1) {
		imaginaryDouble = -1.0;
		if (count(aString.begin(), aString.end(), '-') == 2) {
			realDouble = -1.0;
			posSymbol = aString.find_last_of("-");
			posStart = aString.find_first_of("-");
		}	
	}
	else {
		if (posMinus != -1) {
			realDouble = -1.0;
			posStart = aString.find_first_of("-");
		}
	}
	string realString = aString.substr(posStart+1, posSymbol);
	string gap = aString.substr(posSymbol + 1, posImSymbol - posSymbol + 1);
	string imaginaryString;
	if(this->is_number(gap))	// a + bi case
		imaginaryString = aString.substr(posSymbol+1);
	else			// a + ib case
		imaginaryString = aString.substr(posImSymbol + 1);
	if (this->is_number(realString))
		realDouble *= stod(realString);
	else
		realDouble = 0.0;
	imaginaryDouble *= stod(imaginaryString);

	this->setComplex(realDouble, imaginaryDouble);
}

void Complex::setReal(double aReal) {
	this->real = aReal;
}
void Complex::setImaginary(double aImg) {
	this->img = aImg;
}
void Complex::setComplex(double x, double y){
	this->setReal(x);
	this->setImaginary(y);
}
void Complex::setComplex(const Complex &obj) {
	this->setComplex(obj.getReal(), obj.getImaginary());
}

double Complex::getReal()const {
	return this->real;
}
double Complex::getImaginary()const {
	return this->img;
}
Complex Complex::getComplex()const {
	return *this;
}

Complex Complex::operator + (const Complex & rhs) {
	Complex t(this->getComplex());
	return (t += rhs);
}

Complex Complex::operator + (const double & rhs) {
	Complex t(this->getComplex());
	return (t += rhs);
}

Complex Complex::operator +=(const Complex & rhs) {
	real += rhs.getReal();
	img += rhs.getImaginary();
	return this->getComplex();
}
Complex Complex::operator +=(const double & rhs) {
	real += rhs;
	return this->getComplex();
}
Complex Complex::operator -(const Complex & rhs) {
	Complex t(this->getComplex());
	return (t -= rhs);
}
Complex Complex::operator -(const double & rhs) {
	Complex t(this->getComplex());
	return (t -= rhs);
}

Complex Complex::operator -=(const Complex & rhs) {
	real -= rhs.getReal();
	img -= rhs.getImaginary();
	return this->getComplex();
}
Complex Complex::operator -=(const double & rhs) {
	real -= rhs;
	return this->getComplex();
}

Complex Complex::operator *(const Complex & rhs) {
	Complex t(this->getComplex());
	return (t *= rhs);
}
Complex Complex::operator *(const double & rhs) {
	Complex t(this->getComplex());
	return (t *= rhs);
}

Complex Complex::operator *=(const Complex & rhs) {
	Complex t;
	t.setReal(this->getReal()*rhs.getReal() - this->getImaginary()*rhs.getImaginary());
	t.setImaginary(this->getReal()*rhs.getImaginary()+this->getImaginary()*rhs.getReal());
	this->setComplex(t);
	return this->getComplex();
}
Complex Complex::operator *=(const double & rhs) {
	real *= rhs;
	img *= rhs;
	return this->getComplex();
}

Complex Complex::operator /(const Complex & rhs) {
	Complex t(this->getComplex());
	return (t /= rhs);
}
Complex Complex::operator /(const double & rhs) {
	Complex t(this->getComplex());
	return (t /= rhs);
}

Complex Complex::operator /=(const Complex & rhs) {
	Complex nmrtr, dnmntr, cnjgt = *rhs.getComplex();
	double dDenom;
	nmrtr = this->getComplex() * cnjgt;
	dnmntr = cnjgt * rhs;
	dDenom = (double)dnmntr;
	*this = nmrtr / dDenom;
	return this->getComplex();
}
Complex Complex::operator /=(const double & rhs) {
	real /= rhs;
	img /= rhs;
	return this->getComplex();
}


bool Complex::is_number(const string& s)
{
	try
	{
		std::stod(s);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool Complex::operator == (const Complex & c)
{
	if ((this->getReal() == c.getReal()) && (this->getImaginary() == c.getImaginary())){
		return true;
	}
	else
		return false;
}
bool Complex::operator != (const Complex & c)
{
	if (this->getImaginary() == c.getImaginary()){
		return false;
	}
	else
		return true;
}


Complex Complex::operator -(){
	Complex temp(-this->getReal(), -this->getImaginary());
	return temp;
}

Complex Complex::operator * () {
	Complex t(this->getReal(), -this->getImaginary());
	return t;
}

Complex & Complex::operator++(){
	this->real++;
	return *this;
}

Complex Complex::operator ++(int){
	Complex t = this->getComplex();
	this->real++;
	return t;
}
Complex & Complex::operator --() {
	this->real--;
	return *this;
}

Complex Complex::operator --(int) {
	Complex t = this->getComplex();
	this->real--;
	return t;
}

Complex::operator double(){
	return this->getReal();
}
Complex operator +(const double & lhs, const Complex & rhs) {
	Complex t;
	t.setReal(lhs + rhs.getReal());
	t.setImaginary(rhs.getImaginary());
	return t;
}

Complex operator -(const double & lhs, const Complex & rhs) {
	Complex t;
	t.setReal(lhs - rhs.getReal());
	t.setImaginary(-rhs.getImaginary());
	return t;
}

Complex operator *(const double & lhs, const Complex & rhs) {
	Complex t = rhs;
	return t *= lhs;
}

Complex operator /(const double & lhs, const Complex & rhs) {
	Complex nmrtr, dnmntr, cnjgt =*rhs.getComplex();
	double dDenom;
	nmrtr = cnjgt * lhs;
	dnmntr = cnjgt * rhs;
	dDenom = (double)dnmntr;
	return nmrtr / dDenom;
}

ostream & operator <<(ostream & os, const Complex & c)
{
	os << "(" << c.real << ") + (" << c.img << ")i";
	return os;
}

istream & operator >>(istream & is, Complex & c)
{
	cout << "Enter real part: ";
	is >> c.real;
	cout << "Enter imaganiary part: ";
	is >> c.img;

	return is;
}


