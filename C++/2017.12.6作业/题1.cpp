#include<iostream>
#include<string>
using namespace std;
int main() {
	string word;
	cin >> word;
	for (auto &c : word)
		c + toupper(c);
	string a[] = { word };
	int i = 0, j = word.size() - 1, n = 0;
	for (; i <= j; i++, j--) {
		if (a[0][i] != a[0][j]) {
			n++;
		}
		else continue;
	}
	if (n == 0)
		cout << "�û�������ǻ�������";
	else cout << "�û�����Ĳ��ǻ�������";
	system("pause");
	return 0;
}