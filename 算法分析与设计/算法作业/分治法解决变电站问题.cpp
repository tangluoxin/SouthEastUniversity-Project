#include <iostream>  
#include <ctime>
#include <cmath>
#include <algorithm>
#include<math.h> 
#include <iomanip>

using namespace std;

//定义二维点Point
typedef struct Point
{
	float x, y,z;     //二维点的横纵坐标,和身份标识
}Point;


static Point a, b;


//平面上任意两点对之间的距离公式计算
float Distance(Point a, Point b)
{
	if (a.z == b.z)return 1000000;//如果两个点身份相同，同为特工或者同为电站，则距离没有意义
	else return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

//依照结构体中的x成员变量升序排序
bool CmpX(Point a, Point b)
{
	return a.x<b.x;
}

//求出最近点对记录，并将两点记录再a、b中
float ClosestPair(Point points[], int length, Point &a, Point &b)
{
	float distance;        //集合points中最近两点距离 
	float d1, d2;           //分割后两个子集中各自最小点对距离 
	Point a1, b1, a2, b2;     //分割后两个子集中最小点对
	int i = 0, j = 0, k = 0;

	if (length<2)return 1000000;    //若子集长度小于2，定义为最大距离，表示不可达
	if (length == 2)
	{
		a = points[0];
		b = points[1];
		distance = Distance(points[0], points[1]);
	}
	else
	{   //两个子数组
		Point *pts1 = new Point[length];     
		Point *pts2 = new Point[length];

		//CmpX为自定义的排序规则
		sort(points, points + length, CmpX);   

		//中位数,排序后的中间下标值
		float mid = points[(length - 1) / 2].x;  

		//将坐标填入两个子数组
		for (int i = 0; i < length / 2; i++) {
			pts1[i] = points[i];
		}
		for (int j = 0, i = length / 2; i < length; i++) {
			pts2[j] = points[i];
			j++;
		}
		//分治求解左、右半部分子集的最近点对
		d1 = ClosestPair(pts1, length / 2, a1, b1);             
		d2 = ClosestPair(pts2, length - length / 2, a2, b2);  

		if (d1<d2) { distance = d1; a = a1; b = b1; }
		else { distance = d2; a = a2; b = b2; }

	
		//求解跨分割线并在d×2d区间内的最近点对
		Point *pts3 = new Point[length];
		for ( i = 0, k = 0; i<length; i++)
			if (abs(points[i].x - mid) <= distance)pts3[k++] = points[i];

		for ( i = 0; i < k; i++) {
			for ( j = i + 1; j <= i + 7 && j < k; j++)    //只需与有序的领接的的7个点进行比较
			{
				if (Distance(pts3[i], pts3[j]) < distance)
				{//如果跨分割线的两点距离小于已知最小距离，则记录该距离
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

	cout << "输入核电站个数";
	cin >> N;
	N = 2 * N;

	if (N < 1) {
		cout << "输入大于1的数" << endl;
	}
	else
	{   
		Point *points = new Point[N];
		//存入电站位置
		for (int i = 0; i < (N/2); i++) {
			cin >> points[i].x >> points[i].y;
			points[i].z = 0;//标记区分电站身份
		}
		//存入特工位置
		for (int i = (N / 2); i < N; i++) {
			cin >> points[i].x >> points[i].y;
			points[i].z = 1;//标记区分特工身份
		}

		diatance = ClosestPair(points, N, a, b);

		//cout << endl << "最近特工和核电站为：" << "(" << a.x << "," << a.y << ")和" << "(" << b.x << "," << b.y << ")" << endl
		cout<< "最近距离为：" << setprecision(4) << diatance << endl;
	}
	system("pause");
	return 0;
}
