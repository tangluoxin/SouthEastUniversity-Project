#include<iostream>
using namespace std;
template< typename T >
class Array 
{
public:
	explicit Array(int ct);
	~Array() { delete[]ptr; }
	void push();
	void print();
private:
	int count;
	T *ptr;
};

template< typename T >
Array<T>::Array(int ct):count(ct),ptr(new T[count]){}

template< typename T >
void Array<T>::push() {
	int x = 0;
	for (int i = 0; i < count; i++) {
		cin >> x;
	    ptr[i] = x;
	}
}
template< typename T >
void Array<T>::print() {
	for (int i = 0; i < count; i++) {
		cout << ptr[i] << "   ";
	}
}

int main() {
	Array<int>intarray(3);
	cout << "��������int����"<<endl;
	intarray.push();
	cout << "int�����������У�"<<endl;
	intarray.print();
	cout << endl;
	Array<float>floatarray(2);
	cout << "����2��float������"<<endl;
	floatarray.push();
	cout << "float�����������У�"<<endl;
	floatarray.print();
	cout << endl;
	system("pause");
	return 0;
}