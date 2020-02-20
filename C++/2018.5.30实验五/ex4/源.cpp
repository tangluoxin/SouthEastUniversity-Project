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
	cout << "输入三个int型数"<<endl;
	intarray.push();
	cout << "int类型数组内有："<<endl;
	intarray.print();
	cout << endl;
	Array<float>floatarray(2);
	cout << "输入2个float类型数"<<endl;
	floatarray.push();
	cout << "float类型数组内有："<<endl;
	floatarray.print();
	cout << endl;
	system("pause");
	return 0;
}