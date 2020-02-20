#include <iostream>
#include <stdexcept>
using namespace std;

class TestException:public runtime_error{
public:
	TestException():runtime_error("TestException error"){};
};