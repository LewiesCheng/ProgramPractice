// CountPools.cpp : �������̨Ӧ�ó������ڵ㡣
//
//ˮ����Ŀ
//����
//������ѧԺУ԰����һЩС�Ӻ�һЩ���������ڣ����ǰ�����ͨһ����ˮ�أ�������һ������ѧУ��ĳ���ĵ�ͼ�������ͼ�Ͻ���ʶ�˴˴��Ƿ���ˮ�أ����ڣ�����������ˣ����ü��������õ�ͼ�й��м���ˮ�ء�
//����
//��һ������һ������N����ʾ����N���������
//ÿһ�����ݶ���������õ�ͼ������m(0<m<100)������n(0<n<100)��Ȼ�������������m��ÿ������n��������ʾ�˴���ˮ����ûˮ��1��ʾ�˴���ˮ�أ�0��ʾ�˴��ǵ��棩
//	���
//	����õ�ͼ��ˮ�صĸ�����
//	Ҫע�⣬ÿ��ˮ�ص��Աߣ����������ĸ�λ�ã��������ˮ�صĻ��Ļ������ǿ��Կ�����ͬһ��ˮ�ء�
//	��������
//	2
//	3 4
//	1 0 0 0
//	0 0 1 1
//	1 1 1 0
//	5 5
//	1 1 1 1 0
//	0 0 1 0 1
//	0 0 0 0 0
//	1 1 1 0 0
//	0 0 1 1 1
//	�������
//	2
//	3

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//���ǰ�����Ҳ����ϱ��
void Checknear(bool **map, bool **sign, int m, int n, int i, int j) 
{
	if(i < 0 || i >= m)//���ݳ����ɲ鷶Χ
		return;
	else if(j < 0 || j >= n)
		return;
	else if (sign[i][j]) //����λ�ò����ټ��
		return;
	else if (!map[i][j]) //��������Ͳ����ټ����ȥ
	{
		sign[i][j] = 1;
		return;
	}
	else if (map[i][j]) //����ˮ�ؼ������
	{   
		sign[i][j] = 1;
		Checknear(map, sign, m, n, i - 1, j); //����ˮ�ص��Ϸ�
		Checknear(map, sign, m, n, i, j - 1); //����ˮ�ص���
		Checknear(map, sign, m, n, i, j + 1); //����ˮ�ص��ҷ�
		Checknear(map, sign, m, n, i + 1, j); //����ˮ�ص��·�
	}
	return;
}

//����������ĸ���
int Countpools(bool **map, bool **sign, int m, int n) 
{
	int counts = 0;//�õ�ͼ�ĳ�����
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (sign[i][j] )//������λ�������ټ��
				continue;
			if (!map[i][j]) //��������Ͳ��ؼ�飬ֻ���Ǹô���������
			{
				sign[i][j] = 1;
				continue;
			}
			else 
			{
				Checknear(map, sign, m, n, i, j);//����ˮ����Ӧ�ü��������ܸ���ȫ��λ�ã������
				++counts;
			}
		}
	}
	return counts;//���ظõ�ͼ�ĳ�����
}

int main()
{
	int N;
	cin >> N;//N��ʾ�������ݵ�����
	int * counts = new int[N];//ÿ��������ݵ�ͼ�ĳ�����
	memset(counts, 0, sizeof(counts));
	for (int i = 0; i < N; i++) 
	{
		int m, n;
		cin >> m >> n; //�õ�ͼ����m������n
		bool **map = new bool *[m]; //��Ÿõ�ͼ��1-ˮ�أ�0-���棩
		for (int j = 0; j < m; j++) 
		{
			map[j] = new bool[n];
		}
		bool **sign = new bool *[m]; //��Ϊ����ǣ�1-�Ѽ�飬0-δ��飩
		for (int j = 0; j < m; j++) 
		{
			sign[j] = new bool[n];
		}
		for (int j = 0; j < m; j++) //sign[][]��ʼֵ��Ϊ0
		{
			for (int k = 0; k < n; k++)
			{
				sign[j][k] = 0;
			}
		}

		for (int j = 0; j < m; j++) //����õ�ͼ
		{
			for (int k = 0; k < n; k++) 
			{
				cin >> map[j][k];
			}
		}
		counts[i] = Countpools(map, sign, m, n);  //����õ�ͼ�ĳ�����
		for (int j = 0; j < m; j++) //�ͷŶ�̬���������map��sign
		{
			delete[] map[j];
			delete[] sign[j];
		}
		delete[] map;
		delete[] sign;
	}
	for (int i = 0; i < N; i++) //������������
	{
		cout << counts[i] << endl;
	}
    return 0;
}

