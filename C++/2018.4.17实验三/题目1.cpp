#include<iostream>
using namespace std;
class Complex {
	friend Complex operator+(Complex &m, Complex &n);
	friend Complex operator-(Complex &m, Complex &n);
	friend Complex operator*(Complex &m, Complex &n);
	friend istream &operator>>(istream &input, Complex &m);
	friend ostream &operator<<(ostream &output, const Complex &m);
	friend bool operator==(Complex &m, Complex &n);
	friend bool operator!=(Complex &m, Complex &n);
public:
	Complex(double r = 0.0, double i = 0.0) { real = r, imag = i; }
private:
	double real;
	double imag;
};
Complex operator+(Complex &m, Complex &n) {
	Complex a;
	a.real = m.real + n.real;
	a.imag = m.imag + n.imag;
	return a;
}
Complex operator-(Complex &m, Complex &n) {
	Complex a;
	a.real = m.real - n.real;
	a.imag = m.imag - n.imag;
	return a;
}
Complex operator*(Complex &m, Complex &n) {
	Complex a;
	a.real = m.real*n.real-m.imag*n.imag;
	a.imag = m.real*n.real+m.imag *n.imag;
	return a;
}
istream &operator>>(istream &input, Complex &m) {
	input >> m.real >> m.imag;
	return input;
}
ostream &operator<<(ostream &output, const Complex&m) {
	if (m.imag < 0) {
		 output << m.real << m.imag <<"i";
	}
	else {
		output << m.real << "+" << m.imag <<"i";
	}
	return output;
}
bool operator==(Complex &m, Complex &n) {
	if (m.real == n.real&&m.imag == n.imag) {
		return true;
	}
	else { return false; }
}
bool operator!=(Complex &m, Complex &n) {
	if (m.real != n.real||m.imag != n.imag) {
		return true;
	}
	else { return false; }
}
int main()
{
	Complex x, y(4.3, 8.2), z(3.3, 1.1), k;

	cout << "Enter a complex number in the form: (a, b)\n? ";
	cin >> k; // demonstrating overloaded >>
	cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
		<< k << '\n'; // demonstrating overloaded <<
	x = y + z; // demonstrating overloaded + and =
	cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
	x = y - z; // demonstrating overloaded - and =
	cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
	x = y * z; // demonstrating overloaded * and =
	cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

	if (x != k) // demonstrating overloaded !=
		cout << x << " != " << k << '\n';

	cout << '\n';
	x = k;

	if (x == k) // demonstrating overloaded ==
		cout << x << " == " << k << '\n';
	system("pause");
	return 0;
}
