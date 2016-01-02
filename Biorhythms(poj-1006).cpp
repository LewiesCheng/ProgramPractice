// Biorhythms(poj-1006).cpp : �������̨Ӧ�ó������ڵ㡣
// ��������

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int Case = 1;
	int len = 20;
	int *n = (int *)malloc(len * sizeof(int)); //��ʼ����len���ȵ������Ų��������Ĵ�
	while (Case)
	{
		int p, e, i; //�ֱ��ʾ��������к������߷���ֵ�ʱ��
		int	d; //������ʱ�䣨0~365��
		cin >> p >> e >> i >> d;
		if (p == -1 && e == -1 && i == -1 && d == -1)break;//�˳���������
		if (len - 2 < Case) //���Ӳ������ݴ������ĳ���
		{
			len += len;
			n = (int *)realloc(n, len*sizeof(int));
		}
		for (int D=d+1; D <= 21252; D++)
		{
			if (D % 23 == p % 23 && D % 28 == e % 28 && D % 33 == i % 33)//�жϸ����Ƿ�ͬΪ���ָ߷�
				n[Case] = D - d;
		}
		Case++;
	}
	for (int j = 1; j < Case; j++) //������������ݵĴ�
	{
		cout << "Case " << j << ':' << " the triple peak occurs in " << n[j] << " days." << endl;
	}
    return 0;
}

