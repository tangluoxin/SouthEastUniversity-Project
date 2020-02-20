#include<iostream>
#include<string>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	string a1[] = { a };
	string a2[] = { b };
	for (int i = 0; i <= a.size() && i <= b.size(); i++) {
		if (a1[0][i] == a2[0][i])
			continue;
		else cout << a1[0][i] - a2[0][i] << endl;
		break;
		cout << 0 << endl;


	}
	system("pause");
	return 0;
}