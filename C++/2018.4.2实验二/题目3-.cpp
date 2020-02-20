#include<iostream>
#include<iomanip>
using namespace std;
class IntegerSet
{
public:
	// default constructor
	IntegerSet()
	{
		emptySet(); // set all elements of set to 0
	} // end IntegerSet constructor

	IntegerSet(int[], int); // constructor that takes an initial set
	IntegerSet unionOfSets(const IntegerSet &c);//并集
	IntegerSet intersectionOfSets(const IntegerSet&c);//交集
	void emptySet(); // set all elements of set to 0
	void inputSet(int x); // read values from user
	void insertElement(int n);//添加成员
	void deleteElement(int m);//删除成员
	void printSet() const;//只打印存在的
	bool isEqualTo(const IntegerSet&c) const;//判断集合是否相等
private:
	int set[101]; // range of 0 - 100

				  // determines a valid entry to the set
	int validEntry(int x) const
	{
		return (x >= 0 && x <= 100);
	} // end function validEntry
}; // end class IntegerSet
IntegerSet::IntegerSet(int a[], int b) {
	int c = 0;
	for (int j = 0; j <= 100; j++) { set[j] = 0; }
	if (b < 5) {
		for (int index = b - 1; index < 5; index++) { a[index] = -1; }
		for (int i = 0; i < 5; i++) {
			c = a[i];
			if (c >= 0 && c <= 100) { set[c] = 1; }
		}
	}
	else {
		for (int i = 0; i < b; i++) {
			c = a[i];
			if (c >= 0 && c <= 100) { set[c] = 1; }
		}
	}
}
void IntegerSet::emptySet() {
	for (int i = 0; i<101; i++) {
		set[i] = 0;
	}
}
void IntegerSet::inputSet(int x) {
	
		if (set[x] == -1 || set[x] == 0)
			set[x] = 1;
	
}
IntegerSet IntegerSet::unionOfSets(const IntegerSet &c) {
	IntegerSet a;
	for (int i = 0; i < 101; i++) {
		if (set[i] == 1 || c.set[i] == 1) { a.set[i] = 1; }
		else { a.set[i] = 0; }
	}
	return a;
}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet&c) {
	IntegerSet a;
	for (int i = 0; i<101; i++) {
		if (set[i] == 1 && c.set[i] == 1) { a.set[i] = 1; }
		else { a.set[i] = 0; }
		
	}
	return a;
}
void IntegerSet::insertElement(int n) {
	if (n >= 0 && n <= 100)set[n] = 1;
	else cout << "输入不合法";
}
void IntegerSet::deleteElement(int m) {
	if (m >= 0 && m <= 100)set[m] = 0;
	else cout << "输入不合法";
}
void IntegerSet::printSet() const {
	cout << "(";
	for (int i = 0; i<101; i++) {
		if (set[i] == 1)cout << i << "   ";
	}
	cout << ")" << endl;
}
bool IntegerSet::isEqualTo(const IntegerSet&c) const {
	for (int i = 0; i<101; i++) {
		if (set[i] != c.set[i])return false;
	}
	return true;
}
int main() {
	IntegerSet A;
	IntegerSet B;
	IntegerSet C;
	IntegerSet D;
	int x = 0;
	cout << "Enter set A:" << endl;
	while (1) {
		cout << "Enter a element(-1 to end):";
		cin >> x;
		if (x != -1) { A.inputSet(x); }
		else { cout << "Enter complete"; break; }
	}
	cout << "Enter set B:" << endl;
	while (1) {
		cout << "Enter a element(-1 to end):";
		cin >> x;
		if (x != -1) { B.inputSet(x); }
		else { cout << "Enter complete" << endl; break; }
	}
	cout << "Union of A and B is:" << endl;
	C = A.unionOfSets(B);
	C.printSet();
	cout << "intersection of A and B is:" << endl;
	D = A.intersectionOfSets(B);
	D.printSet();
	int k = 0;
	cout << "Add the number to A:";
	cin >> k;
	A.inputSet(k);
	cout << "Now A is:" << endl;
	A.printSet();
	if (A.isEqualTo(B) == true) { cout << "A is equal to B" << endl; }
	else { cout << "A is not equal to B" << endl; }
	system("pause");
	return 0;


}