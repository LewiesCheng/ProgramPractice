// Blubs.cpp : 定义控制台应用程序的入口点。
// 灯泡问题

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool *blub = new bool[n+1];
	memset(blub, 0, n+1);
	for (int i = 1; i <= (int)sqrt(n); i++)//找出亮着的灯的编号
	{
		blub[i*i] = 1;
	}
	for (int i = 1; i <= n; i++) //输出亮着的灯的编号
	{
		if (blub[i])
			cout << i << "  ";
	}
	cout << endl;
    return 0;
}