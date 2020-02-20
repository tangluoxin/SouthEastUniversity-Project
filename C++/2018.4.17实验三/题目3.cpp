#include <iostream>
using namespace std;
class RationalNumber {
public:
	RationalNumber(int a = 1, int b = 1) {
		int x = a, y = b;
		if (b == 0) { cout << "输入不合法，分母为零" << endl; }
		if (b< 0) { cout << "输入不合法，分母为负" << endl; }
		if (b > 0) { 
			int r = x%y;
			while (r != 0) {
				x = y;
				y = r;
				r = x%y;
			}
			fz = a/y; fm = b/y; }
			
	}
	void print() {
		int x = fz, y = fm;
		int a = fz, b = fm;
		int r = x%y;
		while (r != 0) {
			x = y;
			y = r;
			r = x%y;
		}
		fz = a / y; fm = b / y;
		if(fm!=1)
		cout << fz << "/" << fm;
		else cout << fz;
	}
	RationalNumber operator+(RationalNumber&n2);
	RationalNumber operator-(RationalNumber&n2);
	RationalNumber operator*(RationalNumber&n2);
	RationalNumber operator/(RationalNumber&n2);
	friend bool operator>(RationalNumber&m, RationalNumber&n);
	friend bool operator<(RationalNumber&m, RationalNumber&n);
	friend bool operator>=(RationalNumber&m, RationalNumber&n);
	friend bool operator<=(RationalNumber&m, RationalNumber&n);
	friend bool operator==(RationalNumber&m, RationalNumber&n);
	friend bool operator!=(RationalNumber&m, RationalNumber&n);
private:
	int fz; int fm;
};
RationalNumber RationalNumber::operator+(RationalNumber&n2) {
	RationalNumber n3;
	n3.fz = fz*n2.fm + n2.fz*fm;
	n3.fm = fm*n2.fm;
	return n3;
}
RationalNumber RationalNumber::operator-(RationalNumber&n2) {
	RationalNumber n3;
	n3.fz = fz*n2.fm - n2.fz*fm;
	n3.fm = fm*n2.fm;
	return n3;
}
RationalNumber RationalNumber::operator*(RationalNumber&n2) {
	RationalNumber n3;
	n3.fz = fz*n2.fz;
	n3.fm = fm*n2.fm;
	return n3;
}
RationalNumber RationalNumber::operator/(RationalNumber&n2) {
	RationalNumber n3;
	n3.fz = fz*n2.fm;
	n3.fm = fm*n2.fz;
	return n3;
}
bool operator>(RationalNumber&m, RationalNumber&n) {
	double a = m.fz; double b = m.fm;
	double c = n.fz; double d = n.fm;
	double e = a / b; double f = c / d;
	if (a > b) { return true; }
	else { return false; }
}
bool operator<(RationalNumber&m, RationalNumber&n) {
	double a = m.fz; double b = m.fm;
	double c = n.fz; double d = n.fm;
	double e = a / b; double f = c / d;
	if (a <b) { return true; }
	else { return false; }
}
bool operator>=(RationalNumber&m, RationalNumber&n) {
	double a = m.fz; double b = m.fm;
	double c = n.fz; double d = n.fm;
	double e = a / b; double f = c / d;
	if (a >= b) { return true; }
	else { return false; }
}
bool operator<=(RationalNumber&m, RationalNumber&n) {
	double a = m.fz; double b = m.fm;
	double c = n.fz; double d = n.fm;
	double e = a / b; double f = c / d;
	if (a <= b) { return true; }
	else { return false; }
}
bool operator==(RationalNumber&m, RationalNumber&n) {
	double a = m.fz; double b = m.fm;
	double c = n.fz; double d = n.fm;
	double e = a / b; double f = c / d;
	if (a == b) { return true; }
	else { return false; }
}
bool operator!=(RationalNumber&m, RationalNumber&n) {
	double a = m.fz; double b = m.fm;
	double c = n.fz; double d = n.fm;
	double e = a / b; double f = c / d;
	if (a != b) { return true; }
	else { return false; }
}
int main() {
	RationalNumber m(7, 3);
	RationalNumber n(1, 3);
	RationalNumber x(1, 1);
	x = m + n;
	m.print(); cout << "+1/3="; x.print(); cout << endl;
	x = m - n;
	m.print(); cout << "-1/3="; x.print(); cout << endl;
	x = m * n;
	m.print(); cout << "*1/3="; x.print(); cout << endl;
	x = m / n;
	m.print(); cout << "/ 1/3="; x.print(); cout << endl;
	m.print(); cout << "is:" << endl;
	if (m > n) { cout << ">  1/3 according to the overloaded > operator" << endl; }
	else { cout << "<=  1/3 according to the overloaded > operator" << endl; }
	if (m < n) { cout << "<  1/3 according to the overloaded < operator" << endl; }
	else { cout << ">=  1/3 according to the overloaded < operator" << endl; }
	if (m >= n) { cout << ">=  1/3 according to the overloaded >= operator" << endl; }
	else { cout << "<  1/3 according to the overloaded >= operator" << endl; }
	if (m <= n) { cout << "<=  1/3 according to the overloaded <= operator" << endl; }
	else { cout << ">  1/3 according to the overloaded <= operator" << endl; }
	if (m == n) { cout << "==  1/3 according to the overloaded == operator" << endl; }
	else { cout << "!=  1/3 according to the overloaded == operator" << endl; }
	if (m != n) { cout << "!=  1/3 according to the overloaded != operator" << endl; }
	else { cout << "==  1/3 according to the overloaded != operator" << endl; }
	system("pause");
	return 0;
}