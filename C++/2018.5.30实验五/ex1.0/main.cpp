#include <iostream>
#include <stdexcept>
#include "TestException.h"
using namespace  std;

void h()throw(TestException){
	cout<<" in h():"<<endl;
}
void g()throw(TestException){
	cout<<"h() is called inside g()"<<endl;
	h();
}
void f()throw(TestException){
	cout<<"g() is called in f()"<<endl;
	g();
}
int main(){
	try{
		cout<<"f() is called in main"<<endl;
		f();
	}
	catch(TestException&error){
		cout<<"TestException error:"<<error.what()<<endl;
		cout<<"TestException handled in main"<<endl;

	}
	return 0;
}