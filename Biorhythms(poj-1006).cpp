// Biorhythms(poj-1006).cpp : 定义控制台应用程序的入口点。
// 生理周期

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int Case = 1;
	int len = 20;
	int *n = (int *)malloc(len * sizeof(int)); //初始分配len长度的数组存放测试用例的答案
	while (Case)
	{
		int p, e, i; //分别表示体力，情感和智力高峰出现的时间
		int	d; //给定的时间（0~365）
		cin >> p >> e >> i >> d;
		if (p == -1 && e == -1 && i == -1 && d == -1)break;//退出输入条件
		if (len - 2 < Case) //增加测试数据存放数组的长度
		{
			len += len;
			n = (int *)realloc(n, len*sizeof(int));
		}
		for (int D=d+1; D <= 21252; D++)
		{
			if (D % 23 == p % 23 && D % 28 == e % 28 && D % 33 == i % 33)//判断该天是否同为三种高峰
				n[Case] = D - d;
		}
		Case++;
	}
	for (int j = 1; j < Case; j++) //输出各测试数据的答案
	{
		cout << "Case " << j << ':' << " the triple peak occurs in " << n[j] << " days." << endl;
	}
    return 0;
}

