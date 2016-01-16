#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n = 0, result[22] = {0};//存放最后测试用例的结果n 
	int year;
	cin >> year;
	while(year)//输入year == 0 退出 
	{
		int k = 1;
		for(int j = 1; j <= (2 + (year - 1960) / 10); j++)
		{
			k *= 2;
		}
		
		double i = 1;
		double sum = 0;
		for(i = 1; ;i++)
		{
			sum += log2 (i);
			if(sum > k) break;
		}
		result[n] = i - 1;
		n++;
		cin >> year;
	}
	for(int i = 0; i < n; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
} 
