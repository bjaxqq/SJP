#include <iostream>
#include <iomanip> // setting the decimal places to 2
#include <cmath> // sqrt()

using namespace std;

void input(double & real, double & fake);
void output(double real, double fake);
void add(double & a, double & b, double c, double d);
void sub(double & a, double & b, double c, double d); // prototyping for the mathematical functions and for input/output
void mult(double & a, double & b, double c, double d);
void div(double & a, double & b, double c, double d);
double lngth(double real, double fake);

int main()
{
	char choice;
	double A = 0; // keeps track of the current real value
	double B = 0; // keeps track of the current imaginary value
	double C = 0; // the real value to +, -, *, or /
	double D = 0; // the imaginary value to +, -, *, or /

	cout << endl;
	cout << " Welcome to the Complex Number Calculator! " << endl;
	cout << "-------------------------------------------" << endl;
	cout << " Here are your options: " << endl;
	cout << " + (addition)" << endl;
	cout << " - (subtraction)" << endl;
	cout << " * (multiplication)" << endl; // gives instructions how to use calculator
	cout << " / (division)" << endl;
	cout << " l (length)" << endl;
	cout << " i (new input)" << endl;
	cout << " q (quit)" << endl;

	while(choice != 'q')
	{
		cout << "-------------------------------------------" << endl;
		cout << " Enter what you want to do: "; // input for choice
		cin >> choice;

		switch(choice) // another way of using an if statement
		{
			case '+':
				input(C, D);
				add(A, B, C, D); // calls the addition function
				output(A, B); // outputs the results
				break;

			case '-':
				input(C, D);
				sub(A, B, C, D); // calls the subtraction function
				output(A, B); // outputs the results
				break;

			case '*':
				input(C, D);
				mult(A, B, C, D); // calls the multiplication function
				output(A, B); // outputs the results
				break;

			case '/':
				input(C, D);
				div(A, B, C, D); // calls the division function
				output(A, B); // outputs the results
				break;

			case 'l':
				cout << " The length is: " << fixed << setprecision(2) << lngth(A,B) << endl; // calls the length function
				output(A, B); // outputs the results
				break;

			case 'i':
				input(A, B); // setting new values for the real and imaginary numbers
				output(A, B); // outputs the results
				break;

			case 'q':
				cout << " Thanks for using our calculator!" << endl; // completion message to user
				cout << endl;
				break;

			default:
				cout << " Not a valid choice!" << endl; // another way of using an else statement (any other output)
				break;
		}
	}
	return 0;
}

void input(double & real, double & fake) // defines the input function
{
	cout << " Please enter a real number: ";
	cin >> real;
	cout << " Please enter an imaginary number: ";
	cin >> fake;
}
void output(double real, double fake)
{
	cout << fixed << setprecision(2) << " Current value: " << real << " + " << fake << "i" << endl; // defines the output function
}
void add(double & a, double & b, double c, double d) // defines the addition function
{
	a = (a + c);
	b = (b + d);
}
void sub(double & a, double & b, double c, double d) // defines the subtraction function
{
	a = (a - c);
	b = (b - d);
}
void mult(double & a, double & b, double c, double d) // defines the multiplication function
{
	double x;
	x = a;
	a = (a*c - b*d);
	b = (b*c + x*d);
}
void div(double & a, double & b, double c, double d) // defines the division function
{
	double x;
	x = a;
	a = (a*c + b*d) / (c*c + d*d);
	b = (b*c - x*d) / (c*c + d*d);
}
double lngth(double real, double fake) // defines the length function
{
	return sqrt((real * real) + (fake * fake));
}