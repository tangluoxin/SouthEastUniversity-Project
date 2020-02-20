#include<iostream>
using namespace std;
int datas[100] = { 0 };
int i = 0;
void Add(int data) {
	datas[i] = data;
	++i;
}
void Delete() {
	--i;
	datas[i] = 0;
}
void Sort() {
	for (int j = 0; j < i; ++j) {
		for (int m = 0; m < i; ++m) {
			if (datas[j] < datas[m]) { int a = 0; a = datas[m]; datas[m] = datas[j]; datas[j] = a; }
		}
	}
}
int main() {
	cout << "Menu: A(dd) D(elete) S(ort) Q(uit), Select one:" << endl;
	for (int i = 0;; ++i) {
		char choice;
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'A' || choice == 'D' || choice == 'S' || choice == 'Q') {
			if (choice == 'A') {
				int data = 0;
				cin >> data;
				Add(data);
				cout << "数据已经增加" << endl;
			}
			else if (choice == 'D') {
				Delete(); cout << "数据已经删除" << endl;
			}
			else if (choice == 'S') {
				Sort(); cout << "数据已经排序" << endl;
			}
			else if (choice == 'Q') {
				break;
			}
		}
		
	}
	for (int j = 0; j < i; ++j) { cout << datas[j] << " "; }
	system("pause");
	return 0;
}