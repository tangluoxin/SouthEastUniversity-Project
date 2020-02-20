#include <iostream>
using namespace std;
int qiuyueshu(int a, int b) {
	int r = a%b;
	while (r != 0) {
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}
class Rational {
public:
	Rational(double m = 0.0, double n = 0.0) {
		fz = m;
		fm = n;
	}
	Rational add(const Rational&n2);
	Rational jian(const Rational&n2);
	Rational cheng(const Rational&n2);
	Rational chu(const Rational&n2);
	void input();
	void output();
	void huaxiaoshu();
private:
	int fz; int fm;
};
Rational Rational::add(const Rational&n2) {
	Rational n3;
	n3.fz = fz*n2.fm + n2.fz*fm;
	n3.fm = fm*n2.fm;
	return n3;
}
Rational Rational::jian(const Rational&n2) {
	Rational n3;
	n3.fz = fz*n2.fm - n2.fz*fm;
	n3.fm = fm*n2.fm;
	return n3;
}
Rational Rational::cheng(const Rational&n2) {
	Rational n3;
	n3.fz = fz*n2.fz;
	n3.fm = fm*n2.fm;
	return n3;
}
Rational Rational::chu(const Rational&n2) {
	Rational n3;
	n3.fz =fz*n2.fm;
	n3.fm =fm*n2.fz;
	return n3;
}

void Rational::input() {
	cout << "输入分子分母"; cin >> fz >> fm;
}
void Rational::output() {
	int a = fz, b = fm;
	int c = qiuyueshu(a, b);
	a = a / c; b = b / c;
	cout << a << "/" << b << endl;

}
void Rational::huaxiaoshu() {
	int a = fz, b = fm;
	int c = qiuyueshu(a, b);
	a = a / c; b = b / c;
	double m = a, n = b;
		double d = m / n;
	cout << a << "/" << b << "=" << d;
}
int main() {
	Rational n1, n2, n3;
	n1.input(); n2.input();
	n3 = n1.add(n2);
	n1.output(); cout << "+"; n2.output(); cout << "="; n3.output(); cout << endl;
	n3.huaxiaoshu();cout<< endl;

	n3 = n1.jian(n2);
	n1.output(); cout << "-"; n2.output(); cout << "="; n3.output(); cout << endl;
	n3.huaxiaoshu(); cout << endl;

	n3 = n1.cheng(n2);
	n1.output(); cout << "*"; n2.output(); cout << "="; n3.output(); cout << endl;
	n3.huaxiaoshu(); cout << endl;

	n3 = n1.chu(n2) ;
	n1.output(); cout << "/"; n2.output(); cout << "="; n3.output(); cout << endl;
	n3.huaxiaoshu(); cout << endl;
	system("pause");
	return 0;
}