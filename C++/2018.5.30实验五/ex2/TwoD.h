#ifndef TWOD_H
#define TWOD_H
#include "Shape.h"

class TwoD:public Shape{
public:
	TwoD(int l, int w);
    virtual void getA();
};
#endif