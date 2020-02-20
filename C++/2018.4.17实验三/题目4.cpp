#include <iostream>
using namespace std;
class Polynomial
{
public:
	Polynomial() { numberOfTerms = 0; exponents[100] = (100, 0); coefficients[100] = (100, 0); }
	Polynomial operator+(const Polynomial&) const; // addition
	Polynomial operator-(const Polynomial&) const; // subtraction
	Polynomial operator*(const Polynomial&); // multiplication
	Polynomial operator=(const Polynomial&); // assignment
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	void enterTerms();
	void printPolynomial() const;

private:
	int numberOfTerms;
	int exponents[100]; // exponent array指数
	int coefficients[100]; // coefficients array系数

};
void Polynomial::enterTerms() {
	std::cout << "请输入多项式项数" << endl;
	cin >> numberOfTerms;
	for (int i = 0; i < numberOfTerms; i++) {
		std::cout << "输入系数" << endl;
		cin >> coefficients[i];

		
	    std::cout << "输入指数" << endl;
		cin >> exponents[i];

		
	}
	

}
void Polynomial::printPolynomial() const {
	if (exponents[0] == 0) { cout << coefficients[0]; }
	else if (exponents[0] == 1) { cout << coefficients[0] << "x"; }
	else { cout << coefficients[0] << "x^" << exponents[0]; }
	for (int i = 1; i < numberOfTerms; i++) {
		if (coefficients[i] < 0) {
			if (exponents[i] == 0) { cout << coefficients[i]; }
			else if (exponents[i] == 1) { cout << coefficients[i] << "x"; }
			else { cout << coefficients[i] << "x^" << exponents[i]; }
		}
		else if (coefficients[i] > 0) {
			if (exponents[i] == 0) { cout << "+" << coefficients[i]; }
			else if (exponents[i] == 1) { cout << "+" << coefficients[i] << "x"; }
			else { cout << "+" << coefficients[i] << "x^" << exponents[i]; }
		}
	}
	cout << endl;

}
Polynomial Polynomial::operator+(const Polynomial&c) const {
	Polynomial a;
	int max = 0;
	if (numberOfTerms>c.numberOfTerms)max = numberOfTerms;
	else max = c.numberOfTerms;
	int i = 0, j = 0;
	for (; i<max; i++) {
		for (; j<max; j++) {
			if (exponents[i] == c.exponents[j])break;
		}
	}
	if (i>j) {
		for (int k = 0; k<i; k++) { a.coefficients[k] = coefficients[k]; a.exponents[k] = exponents[k]; }
		for (int k = i; k<max; k++) { a.coefficients[k] = coefficients[k] + c.coefficients[k]; }
		for (int k = i; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = (exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k];
		}
	}
	if (i<j) {
		for (int k = 0; k<j; k++) { a.coefficients[k] = c.coefficients[k]; a.exponents[k] = c.exponents[k]; }
		for (int k = j; k<max; k++) { a.coefficients[k] = coefficients[k] + c.coefficients[k]; }
		for (int k = j; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = (exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k];
		}
	}
	if (i == j) {
		for (int k = 0; k<max; k++) { a.coefficients[k] = coefficients[k] + c.coefficients[k]; }
		for (int k = 0; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = (exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k];
		}
	}
	return a;
}
Polynomial Polynomial::operator-(const Polynomial&c) const {
	Polynomial a;
	int max = 0;
	if (numberOfTerms>c.numberOfTerms)max = numberOfTerms;
	else max = c.numberOfTerms;
	int i = 0, j = 0;
	for (; i<max; i++) {
		for (; j<max; j++) {
			if (exponents[i] == c.exponents[j])break;
		}
	}
	if (i>j) {
		for (int k = 0; k<i; k++) { a.coefficients[k] = coefficients[k]; a.exponents[k] = exponents[k]; }
		for (int k = i; k<max; k++) { a.coefficients[k] = coefficients[k] - c.coefficients[k]; }
		for (int k = i; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = (exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k];
		}
	}
	if (i<j) {
		for (int k = 0; k<j; k++) { a.coefficients[k] = c.coefficients[k]; a.exponents[k] = c.exponents[k]; }
		for (int k = j; k<max; k++) { a.coefficients[k] = coefficients[k] - c.coefficients[k]; }
		for (int k = j; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = (exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k];
		}
	}
	if (i == j) {
		for (int k = 0; k<max; k++) { a.coefficients[k] = coefficients[k] - c.coefficients[k]; }
		for (int k = 0; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = (exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k];
		}
	}
	return  a;
}
Polynomial Polynomial::operator*(const Polynomial&c) {
	Polynomial a;
	int r[100][100];//储存相乘之后的系数
	int s[100][100];//储存相乘之后的指数
	for (int i = 0; i<100; i++) {
		for (int j = 0; j<100; j++) {
			r[i][j] = 0;
			s[i][j] = 0;
		}
	}
	int m = numberOfTerms, n = c.numberOfTerms;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			r[i][j] = coefficients[i] * c.coefficients[j];
			s[i][j] = exponents[i] + c.exponents[j];
		}
	}
	int min = 0;
	while (min<m*n - 1) {
		for (int i = min + 1; i<m*n; i++) {
			if (s[i / n][i%n]>s[min / n][min%n]) {
				int t = s[min / n][min%n];
				s[min / n][min%n] = s[i / n][i%n];
				s[i / n][i%n] = t;
				t = t = r[min / n][min%n];
				r[min / n][min%n] = r[i / n][i%n];
				r[i / n][i%n] = t;
			}
		}
		min++;
	}
	for (int i = 0; i<m*n - 1; i++) {
		if (s[i / n][i%n] == s[(i + 1) / n][(i + 1) % n])
			r[i / n][i%n] = r[(i + 1) / n][(i + 1) % n] + r[i / n][i%n];
		r[(i + 1) / n][(i + 1) % n] = 0;
		s[(i + 1) / n][(i + 1) % n] = 0;

	}
	int count = 0;
	for (int i = 0; i<100; i++) {
		for (int j = 0; j<100; j++) {
			if (r[i][j] != 0) {
				a.coefficients[count] = r[i][j];
				a.exponents[count] = s[i][j];
				count++;
			}
		}
	}

	return a;
}
Polynomial Polynomial::operator=(const Polynomial&c) {
	Polynomial a;
	a.numberOfTerms = c.numberOfTerms;
	for (int i = 0; i<c.numberOfTerms; i++) {
		a.coefficients[i] = c.coefficients[i];
		a.exponents[i] = c.exponents[i];
	}
	return a;
}
Polynomial &Polynomial::operator+=(const Polynomial&c) {
	Polynomial a;
	int max = 0;
	if (numberOfTerms>c.numberOfTerms)max = numberOfTerms;
	else max = c.numberOfTerms;
	int i = 0, j = 0;
	for (; i<max; i++) {
		for (; j<max; j++) {
			if (exponents[i] == c.exponents[j])break;
		}
	}
	if (i>j) {
		for (int k = 0; k<i; k++) { a.coefficients[k] = coefficients[k]; a.exponents[k] = exponents[k]; }
		for (int k = i; k<max; k++) { a.coefficients[k] = coefficients[k] + c.coefficients[k]; }
		for (int k = i; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = ((exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k]);
		}
	}
	if (i<j) {
		for (int k = 0; k<j; k++) { a.coefficients[k] = c.coefficients[k]; a.exponents[k] = c.exponents[k]; }
		for (int k = j; k<max; k++) { a.coefficients[k] = coefficients[k] + c.coefficients[k]; }
		for (int k = j; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = ((exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k]);
		}
	}
	if (i == j) {
		for (int k = 0; k<max; k++) { a.coefficients[k] = coefficients[k] + c.coefficients[k]; }
		for (int k = 0; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = ((exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k]);
		}
	}
	for (int k = 0; k < 100; k++) {
		coefficients[k] = a.coefficients[k];
		exponents[k] = a.exponents[k];
	}
	return *this;
}
Polynomial &Polynomial:: operator-=(const Polynomial&c) {
	Polynomial a;
	int max = 0;
	if (numberOfTerms>c.numberOfTerms)max = numberOfTerms;
	else max = c.numberOfTerms;
	int i = 0, j = 0;
	for (; i<max; i++) {
		for (; j<max; j++) {
			if (exponents[i] == c.exponents[j])break;
		}
	}
	if (i>j) {
		for (int k = 0; k<i; k++) { a.coefficients[k] = coefficients[k]; a.exponents[k] = exponents[k]; }
		for (int k = i; k<max; k++) { a.coefficients[k] = coefficients[k] - c.coefficients[k]; }
		for (int k = i; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = ((exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k]);
		}
	}
	if (i<j) {
		for (int k = 0; k<j; k++) { a.coefficients[k] = c.coefficients[k]; a.exponents[k] = c.exponents[k]; }
		for (int k = j; k<max; k++) { a.coefficients[k] = coefficients[k] - c.coefficients[k]; }
		for (int k = j; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = ((exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k]);
		}
	}
	if (i == j) {
		for (int k = 0; k<max; k++) { a.coefficients[k] = coefficients[k] - c.coefficients[k]; }
		for (int k = 0; k<max; k++) {
			if (exponents[k] == 0 && c.exponents[k] == 0)a.exponents[k] = 0;
			else a.exponents[k] = ((exponents[k]>c.exponents[k]) ? exponents[k] : c.exponents[k]);
		}
	}
	for (int k = 0; k < 100; k++) {
		coefficients[k] = a.coefficients[k];
		exponents[k] = a.exponents[k];
	}
	return *this;
}
Polynomial &Polynomial:: operator*=(const Polynomial&c) {
	Polynomial a;
	int r[100][100];//储存相乘之后的系数
	int s[100][100];//储存相乘之后的指数
	for (int i = 0; i<100; i++) {
		for (int j = 0; j<100; j++) {
			r[i][j] = 0;
			s[i][j] = 0;
		}
	}
	int m = numberOfTerms, n = c.numberOfTerms;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			r[i][j] = coefficients[i] * c.coefficients[j];
			s[i][j] = exponents[i] + c.exponents[j];
		}
	}
	int min = 0;
	while (min<m*n - 1) {
		for (int i = min + 1; i<m*n; i++) {
			if (s[i / n][i%n]>s[min / n][min%n]) {
				int t = s[min / n][min%n];
				s[min / n][min%n] = s[i / n][i%n];
				s[i / n][i%n] = t;
				t = t = r[min / n][min%n];
				r[min / n][min%n] = r[i / n][i%n];
				r[i / n][i%n] = t;
			}
		}
		min++;
	}
	for (int i = 0; i<m*n - 1; i++) {
		if (s[i / n][i%n] == s[(i + 1) / n][(i + 1) % n])
			r[i / n][i%n] = r[(i + 1) / n][(i + 1) % n] + r[i / n][i%n];
		r[(i + 1) / n][(i + 1) % n] = 0;
		s[(i + 1) / n][(i + 1) % n] = 0;

	}
	int count = 0;
	for (int i = 0; i<100; i++) {
		for (int j = 0; j<100; j++) {
			if (r[i][j] != 0) {
				a.coefficients[count] = r[i][j];
				a.exponents[count] = s[i][j];
				count++;
			}
		}
	}
	for (int k = 0; k < 100; k++) {
		coefficients[k] = a.coefficients[k];
		exponents[k] = a.exponents[k];
	}
	return *this;
}
int main()
{
	Polynomial a, b, c, t;
	a.enterTerms();
	b.enterTerms();
	//t = a;   // save the value of a
	cout << "First polynomial is:\n";
	a.printPolynomial();
	cout << "Second polynomial is:\n";
	b.printPolynomial();
	cout << "\nAdding the polynomials yields:\n";
	c = a + b;
	c.printPolynomial();
	cout << "\n+= the polynomials yields:\n";
	a += b;
	a.printPolynomial();
	cout << "\nSubtracting the polynomials yields:\n";
	a = t;  // reset a to original value
	c = a - b;
	c.printPolynomial();
	cout << "\n-= the polynomials yields:\n";
	a -= b;
	a.printPolynomial();
	cout << "\nMultiplying the polynomials yields:\n";
	a = t;  // reset a to original value
	c = a * b;
	c.printPolynomial();
	cout << "\n*= the polynomials yields:\n";
	a *= b;
	a.printPolynomial();
	cout << endl;
	system("pause");
	return 0;
}
