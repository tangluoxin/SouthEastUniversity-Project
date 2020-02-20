#include<iomanip>
#include<iostream>
using namespace std;
int rolldice() {
	int d1 = 1 + rand() % 6;
	int d2 = 1 + rand() % 6;
	int sum = d1 + d2;
	return sum;
}
int main() {
	 cout << "Sum  Total  Actual" << endl;
	double result[11] = { 0 };
	srand(time(0));
	for (int i = 1; i <= 36000; i++) {
		int sum = rolldice();
		result[sum - 2]++;
	}

	for (int j = 0; j < 11; j++) {
		double actual = result[j] / 360;
		cout << setw(3) << (j + 2) << setw(8) << result[j] << setw(8) << actual << "%" << endl;
	}
	system("pause");
	return 0;
}