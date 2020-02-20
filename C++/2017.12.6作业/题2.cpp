#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v1;
	double i = 0, j = 0, m = 0, n = 0;
	double sum = 0;
	do {
		cin >> i;
		v1.push_back(i);

	} while (i != 9999);
	m = v1.size();
	for (auto j:v1)
		n = n +j;
	if (n != 0)
	{
		sum = (n -9999)/ (m - 1);
		cout << "9999之前的数字的平均数是：" << sum;
	}
	else cout << "您不能直接输入9999";
	system("pause");
	return 0;
}