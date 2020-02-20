#include <iostream>
#include "TwoD.h"
using namespace std;
TwoD::TwoD(int l,int w):Shape(l,w){}
void TwoD::getA(){
	int m=getleng()*getwide();
	cout<<"The TwoDimensionalShape's area is "<<m<<endl;
}