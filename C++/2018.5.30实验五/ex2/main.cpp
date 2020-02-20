#include <iostream>
#include <vector>
#include "Shape.h"
#include "TwoD.h"
#include "ThreeD.h"
using namespace std;

int main(){
    vector<Shape*>shape(4);
	shape[0]=&TwoD(2,3);
	shape[1]=&ThreeD(2,3,4);
	shape[2]=&TwoD(1,2);
	shape[3]=&ThreeD(1,2,3);
	for(int i=0;i<4;i++){
		shape[i]->getA();
		ThreeD *ptr=dynamic_cast<ThreeD *>(shape[i]);
		if(ptr!=0){shape[i]->getV();}
	}
	system("pause");
	return 0;
}