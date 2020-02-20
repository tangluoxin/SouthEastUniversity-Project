#include<iostream>
using namespace std;

static int sum = 0;//��ŵ�ǰ�ľ����
static int minsum = 0;//�����С�����

int matrix[100][100] = { 0 };//��Ÿ����ع��������˵�վ�ľ���
int address[100] = { 0 };//��Ÿ����ع�ȥ��һ���˵�վ��address[i]�д�ŵ��ǵ�i���ع�ȥ�ĸ���վ
int minaddress[100] = { 0 };//�����С·����ʱ�����ع��İ���

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
	cout << "�������ع�����";
	cin >> n;
	cout << "����������ع���˵�վ�ľ���";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m;
			matrix[i][j] = m;
		}
	}
	eight_queen(0,n);

	cout <<"��С������ǣ�"<<minsum<<endl;
	cout << "���ŷ����ǣ�"<<endl;
	for (int i = 0; i < n; i++) {
		cout <<"��"<<i+1<<"���ع�ȥ��"<< minaddress[i]+1<<"���˵�վ"<<endl;
	}
	system("pause");
	return 0;

}