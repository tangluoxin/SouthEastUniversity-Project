#include <iostream>
using std::ostream;
using namespace std;
class HugeInt
{
	friend ostream &operator<<(ostream &, const HugeInt &);
public:
	HugeInt();
	HugeInt(const char *);
	HugeInt operator+(const HugeInt &) const;
	HugeInt operator+(int) const;
	HugeInt operator+(const char *) const;
	bool operator==(const HugeInt &) const;
	bool operator!=(const HugeInt &) const;
	bool operator<(const HugeInt &) const;
	bool operator<=(const HugeInt &) const;
	bool operator>(const HugeInt &) const;
	bool operator>=(const HugeInt &) const;
	HugeInt operator-(const HugeInt &) const;
	HugeInt operator*(const HugeInt &) const;
	HugeInt operator/(const HugeInt &) const;
	int getLength() const;
private:
	int integer[30];
}; // end class HugeInt
ostream &operator<<(ostream &output, const HugeInt &c) {
	int a = 0;
	for (int i = 0;; i++) {
		if (c.integer[i] != 0) { a = i; break; }
		else { continue; }
	}
	for (int i = a; i <= 29; j++) { output << c.integer[j]; }
	return output;
}
HugeInt::HugeInt() {
	for (int i = 0; i <= 29; i++) { integer[i] = 0; }
}
HugeInt::HugeInt(const char *c) {
	for (int i = 0; i <= 29; i++) { integer[i] = 0; }
	int a = 0;
	a = strlen(c);
	for (int i = 30 - a, j = 0; i <= 29 && j < a; i++ ) {
		integer[i] = c[j] - 48;
		j++;
	}
}
HugeInt HugeInt::operator+(const HugeInt &c)const {
	HugeInt t;
	for (int i = 0; i <= 29; i++) {
		t.integer[i] = c.integer[i];
	}
	for (int i = 29; i >= 0; i--) {
		if (integer[i] + c.integer[i] >= 10) {
			t.integer[i - 1] = t.integer[i - 1] + 1;
			t.integer[i] = integer[i] + t.integer[i] - 10;
		}
		else {
			t.integer[i] = integer[i] + t.integer[i];
		}
	}
	return t;
}
HugeInt HugeInt::operator+(int c)const {
	HugeInt t1, t2;
	for (int n = 0; n <= 29; n++) { t2.integer[n] = integer[n]; }
	int array[30] = { 0 };
	int i = 0, j = 0;
	do {
		array[i++] = c % 10;
		c = c / 10;
		j++;
	} while (c);
	for (int a = 29, b = j - 1; a >= 0, b >= 0; a--, b--) {
		t1.integer[a] = array[b];
	}
	t2 = t1 + t2;
	return t2;
}
HugeInt HugeInt::operator+(const char *c)const {
	HugeInt t(c), a;
	for (int i = 0; i <= 29; i++) {
		a.integer[i] = t.integer[i];
	}
	for (int i = 29; i >= 0; i--) {
		if (integer[i] + a.integer[i] >= 10) {
			a.integer[i - 1]++;
			a.integer[i] = integer[i] + a.integer[i] - 10;
		}
		else {
			a.integer[i] = integer[i] + a.integer[i];
		}
	}
	return a;
}
bool HugeInt::operator==(const HugeInt &c)const {
	for (int i = 0; i <= 29; i++) {
		if (integer[i] != c.integer[i]) { return false; }
		else { continue; }
	}
	return true;
}
bool HugeInt::operator!=(const HugeInt &c)const {
	for (int i = 0; i <= 29; i++) {
		if (integer[i] != c.integer[i]) { return true; }
		else { continue; }
	}
	return false;
}
bool HugeInt::operator<(const HugeInt &c)const {
	for (int i = 0; i <= 29; i++) {
		if (integer[i] < c.integer[i]) { return true; }
		else if (integer[i] > c.integer[i]) { return false; }
	}
}
bool HugeInt::operator<=(const HugeInt &c)const {
	for (int i = 0; i <= 29; i++) {
		if (integer[i] > c.integer[i]) { return false; }
		else { return true; }
	}
}
bool HugeInt::operator>(const HugeInt &c)const {
	for (int i = 0; i <= 29; i++) {
		if (integer[i] > c.integer[i]) { return true; }
		else if (integer[i] < c.integer[i]) { return false; }
	}
}
bool HugeInt::operator>=(const HugeInt &c)const {
	for (int i = 0; i <= 29; i++) {
		if (integer[i] < c.integer[i]) { return false; }
		else { return true; }
	}
}
HugeInt HugeInt :: operator-(const HugeInt &c)  const {
	HugeInt t;
	if (*this >= c) {
		int n = 0;
		for (int i = 29; i >= 0; i--) {
			t.integer[i] = integer[i] - c.integer[i] - n;
			if (t.integer[i] < 0) {
				t.integer[i] += 10;
				n = 1;
			}
			else n= 0;
		}
		return t;
	}
	else {
		t = c - *this;
		t.integer[30 - t.getLength()] -= 2 * t.integer[30 - t.getLength()];
		return t;
	}
}
HugeInt HugeInt::operator*(const HugeInt &c)const {
	int L1 = getLength(), L2 = c.getLength();
	if (L1 + L2 > 30) {
		cout << "out of the range" << endl;
		return *this;
	}
	HugeInt t;
	int n = 0;
	for (int i = 0; i < L1; i++) {
		for (int j = 0; j <= L2; j++) {
			t.integer[29 - i - j] += integer[29 - i] * c.integer[29 - j] + n;
			n = 0;
			if (t.integer[29 - i - j] > 9) {
				n += t.integer[29 - i - j] / 10;
				t.integer[29 - i - j] %= 10;
			}
		}
	}
	return t;
}
HugeInt HugeInt::operator/(const HugeInt &c)const {
	int L1 = getLength(), L2 = c.getLength();
	int x = L1 - L2;
	HugeInt t2 = *this;
	HugeInt t;
	if (*this < c) { return t; }
	for (int i = x; i >= 0; i--) {
		HugeInt t1 = c;
		for (int j = 30 - L2; j < 30; j++) { t1.integer[j - i] = t1.integer[j]; }
		for (int k = 1; k <= i; k++) { t1.integer[30 - k] = 0; }
		for (; t2 >= t1; t.integer[29 - i]++) {t2 = t2 - t1;}
	}
	return t;
}
int HugeInt::getLength()const {
	int a = 0;
	for (int i = 0; i < 30; i++) {
		if (integer[i] > 0) { a = 30 - i; break; }
		else { continue; }
	}
	return a;
}
int main() {
	char a1[8] = { "7654321" };
	char a2[8] = { "7891234" };
	char a3[9] = { "12341234" };
	char a4[5] = { "7888" };
	HugeInt n1(a1), n2(a2), n3(a3), n4(a4);
	cout << "n1 is " << n1 << endl;
	cout << "n2 is " << n2 << endl;
	cout << "n3 is " << n3 << endl;
	cout << "n4 is " << n4 << endl;
	if (n1 == n2) { cout << "n1 is equal to n2" << endl; }
	else { cout << "n1 is not equal to n2" << endl; }
	if (n1 < n2) { cout << "n1 is less than n2" << endl; }
	if (n1 <= n2) { cout << "n1 is less than or equal to n2" << endl; }
	HugeInt a;
	a = n1 + n2;
	cout << n1 << " + " << n2 << " = " << a << endl;
	int b = 9;
	a = n1 + b;
	cout << n1 << " + " << b << " = " << a << endl;
	char c[6] = { "10000" };
	a = n2 + c;
	cout << n2 << " + 10000 = " << a << endl;
	a = n3*n4;
	cout << n3 << " * " << n4 << " = " << a << endl;
	a = n3 - n4;
	cout << n3 << " - " << n4 << " = " << a << endl;
	a = n3 / n4;
	cout << n3 << " / " << n4 << " = " << a << endl;
	system("pause");
	return 0;

}