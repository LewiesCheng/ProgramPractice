// Blubs.cpp : �������̨Ӧ�ó������ڵ㡣
// ��������

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
	for (int i = 1; i <= (int)sqrt(n); i++)//�ҳ����ŵĵƵı��
	{
		blub[i*i] = 1;
	}
	for (int i = 1; i <= n; i++) //������ŵĵƵı��
	{
		if (blub[i])
			cout << i << "  ";
	}
	cout << endl;
    return 0;
}