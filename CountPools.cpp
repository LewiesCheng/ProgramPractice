// CountPools.cpp : 定义控制台应用程序的入口点。
//
//水池数目
//描述
//南阳理工学院校园里有一些小河和一些湖泊，现在，我们把它们通一看成水池，假设有一张我们学校的某处的地图，这个地图上仅标识了此处是否是水池，现在，你的任务来了，请用计算机算出该地图中共有几个水池。
//输入
//第一行输入一个整数N，表示共有N组测试数据
//每一组数据都是先输入该地图的行数m(0<m<100)与列数n(0<n<100)，然后，输入接下来的m行每行输入n个数，表示此处有水还是没水（1表示此处是水池，0表示此处是地面）
//	输出
//	输出该地图中水池的个数。
//	要注意，每个水池的旁边（上下左右四个位置）如果还是水池的话的话，它们可以看做是同一个水池。
//	样例输入
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
//	样例输出
//	2
//	3

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//检查前后左右并做上标记
void Checknear(bool **map, bool **sign, int m, int n, int i, int j) 
{
	if(i < 0 || i >= m)//数据超出可查范围
		return;
	else if(j < 0 || j >= n)
		return;
	else if (sign[i][j]) //检查过位置不必再检查
		return;
	else if (!map[i][j]) //遇到地面就不必再检查下去
	{
		sign[i][j] = 1;
		return;
	}
	else if (map[i][j]) //遇到水池继续检查
	{   
		sign[i][j] = 1;
		Checknear(map, sign, m, n, i - 1, j); //检查该水池的上方
		Checknear(map, sign, m, n, i, j - 1); //检查该水池的左方
		Checknear(map, sign, m, n, i, j + 1); //检查该水池的右方
		Checknear(map, sign, m, n, i + 1, j); //检查该水池的下方
	}
	return;
}

//计算出池塘的个数
int Countpools(bool **map, bool **sign, int m, int n) 
{
	int counts = 0;//该地图的池塘数
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (sign[i][j] )//检查过的位置无需再检查
				continue;
			if (!map[i][j]) //遇到地面就不必检查，只需标记该处检查过即可
			{
				sign[i][j] = 1;
				continue;
			}
			else 
			{
				Checknear(map, sign, m, n, i, j);//遇到水池则应该检查出它所能覆盖全部位置，并标记
				++counts;
			}
		}
	}
	return counts;//返回该地图的池塘数
}

int main()
{
	int N;
	cin >> N;//N表示测试数据的组数
	int * counts = new int[N];//每组测试数据地图的池塘数
	memset(counts, 0, sizeof(counts));
	for (int i = 0; i < N; i++) 
	{
		int m, n;
		cin >> m >> n; //该地图行数m，列数n
		bool **map = new bool *[m]; //存放该地图（1-水池，0-地面）
		for (int j = 0; j < m; j++) 
		{
			map[j] = new bool[n];
		}
		bool **sign = new bool *[m]; //作为检查标记（1-已检查，0-未检查）
		for (int j = 0; j < m; j++) 
		{
			sign[j] = new bool[n];
		}
		for (int j = 0; j < m; j++) //sign[][]初始值都为0
		{
			for (int k = 0; k < n; k++)
			{
				sign[j][k] = 0;
			}
		}

		for (int j = 0; j < m; j++) //输入该地图
		{
			for (int k = 0; k < n; k++) 
			{
				cin >> map[j][k];
			}
		}
		counts[i] = Countpools(map, sign, m, n);  //计算该地图的池塘数
		for (int j = 0; j < m; j++) //释放动态分配的数组map和sign
		{
			delete[] map[j];
			delete[] sign[j];
		}
		delete[] map;
		delete[] sign;
	}
	for (int i = 0; i < N; i++) //输出结果池塘数
	{
		cout << counts[i] << endl;
	}
    return 0;
}

