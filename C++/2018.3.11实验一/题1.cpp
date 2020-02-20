#include <iostream>
using namespace std;
class Complex{
public:
	Complex(double real = 0.0, double image = 0.0)
	{
		inreal = real; inimage = image;
	}
	Complex add(const Complex&n2);
	Complex subtract(const Complex&n2);
	void display();
private:
	double inreal;
	double inimage;
};
Complex Complex::add(const Complex&n2) {
	Complex n;
	n.inreal = inreal + n2.inreal;
	n.inimage = inimage + n2.inimage;
	return n;
}
Complex Complex::subtract(const Complex&n2) {
	Complex n;
	n.inreal = inreal - n2.inreal;
	n.inimage = inimage - n2.inimage;
	return n;
}
void Complex::display() {
	cout << "(" << inreal << "," << inimage << ")" << endl;
}
int main() {
	Complex n1(1.0, 2.0), n2(3.0, 4.0), n3(0.0, 0.0);
	n3 = n1.add(n2);
	cout << "n1+n2=";
	n3.display();
	n3 = n1.subtract(n2);
	cout << "n1-n2=";
	n3.display();
	system("pause");
	return 0;

}

