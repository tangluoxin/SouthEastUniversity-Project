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
		cout << "用户输入的是回文序列";
	else cout << "用户输入的不是回文序列";
	system("pause");
	return 0;
}