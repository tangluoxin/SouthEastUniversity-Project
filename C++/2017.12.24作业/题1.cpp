#include<iostream>
using namespace std;
void s(int a) {
	for (int i = 0; i < a; i++)
	{
		cout << "" << endl;
		for (int j = 0; j < a; j++)
		{
			cout << "#";
		}
	}
	cout << endl;
}
void d(int n) {
	for (int i = 0; i < n; i++)
	{

		for (int j = 1; j < (n - i + 1); j++)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			cout << "*";
		}cout << endl;

	}
	cout << endl;
}
void t(int n) {
	for (int i = 0; i < n; i++)
	{

		for (int j = 1; j < (n - i + 1); j++)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			cout << "*";
		}cout << endl;

	}
	for (int i = n - 2; i >= 0; i--)
	{

		for (int j = 0; j < (n - i); j++)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			cout << "*";
		}cout << endl;

	}
	cout << endl;
}
int main() {
	cout << "��ѡ��ͼ��  1������  2������  3����" << endl;
	cout << "����������" << endl;
	int b = 0, c = 0;
	cin >> b >> c;
	switch (b)
	{
	case 1:s(c); break;
	case 2:d(c); break;
	case 3:t(c); break;

	default:
		break;
	}
	for (int m = 0;; m++) {
		cout << "�Ƿ����?   1 ����   2ֹͣ" << endl;
		int a = 0;
		cin >> a;
		if (a = 1) {
			cout << "��ѡ��ͼ��  1������  2������  3����" << endl;
			cout << "����������" << endl;
				int b = 0, c = 0;
				cin >> b >> c;
				switch (b)
				{
				case 1:s(c); break;
				case 2:d(c); break;
				case 3:t(c); break;

				default:
					break;
				}
	
		}
		else break;
	}
	system("pause");
	return 0;
}
