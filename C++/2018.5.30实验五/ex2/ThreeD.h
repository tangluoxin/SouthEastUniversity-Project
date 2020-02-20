#ifndef THREED_H
#define THREED_H
#include "Shape.h"

class ThreeD:public Shape{
public:
	ThreeD(int l,int w,int h=0);
    virtual void getA();
	virtual void getV();
private:
	int high;
};
#endif