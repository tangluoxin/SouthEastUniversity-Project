#include <iostream>
using namespace std;

int main()
{
	int count = 0; //���ַ��������������θ��� 
    int m=0; // б��ƽ��
    int n=0; //ֱ�Ǳ�ƽ����
    cout << "Side 1\tSide 2\tSide3" << endl;
	for (int side1 = 1; side1 <= 500; side1++)
	{
		for (int side2 = side1; side2 <= 500; side2++)
		{
			for (int side3 = side2; side3 <= 500; side3++)
			{
				m =side3 * side3;
                n = side1 * side1 + side2 * side2;

				if( m == n)
				{
					cout << side1 << '\t' << side2 << '\t'
						<< side3 << '\n';
					count++; 
				}
			}
		}
	}

	cout << "�ܹ��� " << count << " ��������" << endl;
	system("pause");
	return 0;
}
