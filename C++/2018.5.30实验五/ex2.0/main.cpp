#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdio.h>
using namespace std;
void output(int c,char ch){
    
	cout<<setw(7)<<dec<<c<<setw(9)<<oct<<c<<setw(15)<<hex<<c<<setw(13)<<ch<<showbase<<'\n';
}
int main(){
	ifstream inAsciifile("ascii.txt",ios::in);
	int a=0;
	char charactor;
	cout<<setw(7)<<"Decimal"<<setw(9)<<"Octal"<<setw(15)<<"Hexadecimal"<<setw(13)<<"Character"<<showbase<<'\n';
	for(int i=33;i<=126;i++){
        a=i;
		charactor=i;
		inAsciifile>>dec>>a>>oct>>a>>hex>>a>>charactor;
		output(a,charactor);
	}
	return 0;
}