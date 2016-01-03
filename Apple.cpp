// Apple.cpp : �������̨Ӧ�ó������ڵ㡣
// ��������NYOJ-289

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//��ⱳ�����ƻ����Ǯ���ֵ
int apple(int n, int v, int *value, int *weight)
{
	int *c = new int[v+1];//����Ϊv�Ľ�����ֵc[v]
	memset(c, 0, v+1);
	for (int i = 0; i < n; i++)
	{
		for (int j = v; j > 0; j--)
		{
			if (weight[i] <= j && (c[j - weight[i]] + value[i]) > c[j])
			{
				c[j] = c[j - weight[i]] + value[i];
			}
		}
	}
	return c[v];
}

int main()
{
	int Case = 1;
	int len = 5;
	int *S_Value = (int *)malloc(len*sizeof(int));
	while (Case)//Case��ʾ���������ĸ���
	{
		int n, v;//n-ƻ��������v-��������
		cin >> n >> v;
		int *value = new int[n];//��i��ƻ���ļ�Ǯvalue[i]
		int *weight = new int[n];//��i��ƻ��������value[i]
		if (n == 0 && v == 0)//��������
		{
			break;
		}
		if (Case > len)//���Ӵ�Ų�����������ĳ���
		{
			len += len;
			S_Value = (int *)realloc(S_Value, len*sizeof(int));
		}
		for (int i = 0; i < n; i++)
		{
			cin >> weight[i] >> value[i];
		}
		S_Value[Case - 1] = apple(n, v, value, weight);
		Case++;
		delete value;
		delete weight;
	}
	for (int i = 0; i < Case - 1; i++)//������
	{
		cout << S_Value[i] << endl;
	}
    return 0;
}

