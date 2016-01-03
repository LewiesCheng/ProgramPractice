// Apple.cpp : 定义控制台应用程序的入口点。
// 背包问题NYOJ-289

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//求解背包存放苹果价钱最大值
int apple(int n, int v, int *value, int *weight)
{
	int *c = new int[v+1];//容量为v的结果最大值c[v]
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
	while (Case)//Case表示测试用例的个数
	{
		int n, v;//n-苹果个数，v-背包容量
		cin >> n >> v;
		int *value = new int[n];//第i个苹果的价钱value[i]
		int *weight = new int[n];//第i个苹果的重量value[i]
		if (n == 0 && v == 0)//结束测试
		{
			break;
		}
		if (Case > len)//增加存放测试用例数组的长度
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
	for (int i = 0; i < Case - 1; i++)//输出结果
	{
		cout << S_Value[i] << endl;
	}
    return 0;
}

