#include<iostream>
#include<string>
using namespace std;
int main() {
	string word1[] = { "ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE" };
	string word2[] = { "TEN","ELEVEN","TWELVE","THIRTEEN","FORTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINTEEN" };
	string word3[] = { "TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY" };
	string word;
	double i = 0, j = 0;
	int a = 0, b = 0, c = 0;
	cout << "Enter the check amount(0.00to99.99):" << endl;
	cin >> i;
	a = i / 10;//十位数字
	b = i;//整数部分
	c = b - a * 10;//个位数字
	j = i - b;//小数部分
	if (a == 0) {
		word = word1[c - 1];
	}
	else if (a == 1) {
		word = word2[c];
	}
	else if (a > 1) {
		word = word3[a - 2] + "-" + word1[c - 1];
	}
	cout << word << "and" << j * 100 << "/100" << endl;
	system("pause");
	return 0;
}