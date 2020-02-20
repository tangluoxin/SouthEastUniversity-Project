#include <iostream>
#include "ThreeD.h"
using namespace std;

ThreeD::ThreeD(int l,int w,int h):Shape(l,w){
	high=h;
}
void ThreeD::getA(){
	int m=getleng()*getwide()*2+getleng()*high*2+high*getwide()*2;
	cout<<"The area of the ThreeDimensionalShape is "<<m<<endl;
}
void ThreeD::getV(){
	int n=getleng()*getwide()*high;
	cout<<"The volume of the ThreeDimensionalShape is "<<n<<endl;
}