#include<iostream>
using namespace std;
int power(int a, int n) {
	if (n == 0)
		return 1;
	else return a*power(a, n - 1);
}
int main() {
	cout << "������������" << endl;
	int a = 0, b = 0;
	cin >> a >> b;
	cout << a << "��" << b << "�η���" << power(a, b) << endl;
	system("pause");
	return 0;
}