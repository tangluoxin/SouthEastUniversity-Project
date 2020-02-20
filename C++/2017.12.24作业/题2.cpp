#include<iostream>
using namespace std;
bool perfect(int a) {
	int  s = 0, i = 0;
		for (i = 1; i <= a / 2; i++) {
			if (a%i == 0)
				s += i;
		}
		if (s == a)
			return 1;
		else return 0;
	}

int main() {
	int a = 0, s = 0, i = 0;
	for (a = 6; a <= 1000; a++,s=0) {
      if (perfect(a) == 1) {
			for (i = 1; i <= a / 2; i++)
				if (a%i == 0) {
					if (i == 1)
						cout << a << "=1";
					else cout << "+" << i;
				}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}