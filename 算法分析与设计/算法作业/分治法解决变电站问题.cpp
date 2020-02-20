#include <iostream>  
#include <ctime>
#include <cmath>
#include <algorithm>
#include<math.h> 
#include <iomanip>

using namespace std;

//�����ά��Point
typedef struct Point
{
	float x, y,z;     //��ά��ĺ�������,����ݱ�ʶ
}Point;


static Point a, b;


//ƽ�������������֮��ľ��빫ʽ����
float Distance(Point a, Point b)
{
	if (a.z == b.z)return 1000000;//��������������ͬ��ͬΪ�ع�����ͬΪ��վ�������û������
	else return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

//���սṹ���е�x��Ա������������
bool CmpX(Point a, Point b)
{
	return a.x<b.x;
}

//��������Լ�¼�����������¼��a��b��
float ClosestPair(Point points[], int length, Point &a, Point &b)
{
	float distance;        //����points������������ 
	float d1, d2;           //�ָ�������Ӽ��и�����С��Ծ��� 
	Point a1, b1, a2, b2;     //�ָ�������Ӽ�����С���
	int i = 0, j = 0, k = 0;

	if (length<2)return 1000000;    //���Ӽ�����С��2������Ϊ�����룬��ʾ���ɴ�
	if (length == 2)
	{
		a = points[0];
		b = points[1];
		distance = Distance(points[0], points[1]);
	}
	else
	{   //����������
		Point *pts1 = new Point[length];     
		Point *pts2 = new Point[length];

		//CmpXΪ�Զ�����������
		sort(points, points + length, CmpX);   

		//��λ��,�������м��±�ֵ
		float mid = points[(length - 1) / 2].x;  

		//��������������������
		for (int i = 0; i < length / 2; i++) {
			pts1[i] = points[i];
		}
		for (int j = 0, i = length / 2; i < length; i++) {
			pts2[j] = points[i];
			j++;
		}
		//����������Ұ벿���Ӽ���������
		d1 = ClosestPair(pts1, length / 2, a1, b1);             
		d2 = ClosestPair(pts2, length - length / 2, a2, b2);  

		if (d1<d2) { distance = d1; a = a1; b = b1; }
		else { distance = d2; a = a2; b = b2; }

	
		//����ָ��߲���d��2d�����ڵ�������
		Point *pts3 = new Point[length];
		for ( i = 0, k = 0; i<length; i++)
			if (abs(points[i].x - mid) <= distance)pts3[k++] = points[i];

		for ( i = 0; i < k; i++) {
			for ( j = i + 1; j <= i + 7 && j < k; j++)    //ֻ�����������ӵĵ�7������бȽ�
			{
				if (Distance(pts3[i], pts3[j]) < distance)
				{//�����ָ��ߵ��������С����֪��С���룬���¼�þ���
					distance = Distance(pts3[i], pts3[j]);
					a = pts3[i];
					b = pts3[j];
				}
			}
		}
	}
	return distance;
}

int main()
{
	int N;      
	
	float diatance;

	cout << "����˵�վ����";
	cin >> N;
	N = 2 * N;

	if (N < 1) {
		cout << "�������1����" << endl;
	}
	else
	{   
		Point *points = new Point[N];
		//�����վλ��
		for (int i = 0; i < (N/2); i++) {
			cin >> points[i].x >> points[i].y;
			points[i].z = 0;//������ֵ�վ���
		}
		//�����ع�λ��
		for (int i = (N / 2); i < N; i++) {
			cin >> points[i].x >> points[i].y;
			points[i].z = 1;//��������ع����
		}

		diatance = ClosestPair(points, N, a, b);

		//cout << endl << "����ع��ͺ˵�վΪ��" << "(" << a.x << "," << a.y << ")��" << "(" << b.x << "," << b.y << ")" << endl
		cout<< "�������Ϊ��" << setprecision(4) << diatance << endl;
	}
	system("pause");
	return 0;
}
