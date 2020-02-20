#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Shape{
public:
	Shape(int l,int w);
	int getleng() { return leng; }
	int getwide(){ return wide; }
    virtual void getA();
	virtual void getV();
private:
	int leng;
	int wide;
};
#endif