#include<iostream>
using namespace std;

static int sum = 0;//存放当前的距离和
static int minsum = 0;//存放最小距离和

int matrix[100][100] = { 0 };//存放各个特工到各个核电站的距离
int address[100] = { 0 };//存放各个特工去哪一个核电站，address[i]中存放的是第i个特工去哪个电站
int minaddress[100] = { 0 };//存放最小路径和时各个特工的安排

int check(int loop, int value)
{
	int index;
	int data;
	for (index = 0; index < loop; index++)
	{
		data = address[index];
		if (value == data)
			return 0;
		
	}
	return 1;
}
void compare(int s,int n) {
	if (minsum == 0) {
		minsum = sum;
		for (int i = 0; i < n; i++) {
			minaddress[i] = address[i];
		}
	}
	if (sum < minsum) {
		minsum = sum;
		for (int i = 0; i < n; i++) {
			minaddress[i] = address[i];
		}
	}
}

void count(int n)
{
	for (int i = 0; i < n; i++)
	{
		int inner= address[i];
		sum=sum+matrix[i][inner];
				
	}
	compare(sum,n);
}


void eight_queen(int index,int n)
{
	int loop;
	for (loop = 0; loop < n; loop++)
	{
		if (check(index, loop))
		{
			address[index] = loop;
			if (n-1 == index)
			{
				count(n);
				sum = 0;
				address[index] = 0;
				return;
			}
			eight_queen(index + 1,n);
			address[index] = 0;
		}
	}
}

int main() {
	int n = 0,m=0;
	cout << "请输入特工数量";
	cin >> n;
	cout << "请输入各个特工离核电站的距离";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m;
			matrix[i][j] = m;
		}
	}
	eight_queen(0,n);

	cout <<"最小距离和是："<<minsum<<endl;
	cout << "安排方案是："<<endl;
	for (int i = 0; i < n; i++) {
		cout <<"第"<<i+1<<"个特工去第"<< minaddress[i]+1<<"个核电站"<<endl;
	}
	system("pause");
	return 0;

}