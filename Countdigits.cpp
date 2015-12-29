// Countdigits.cpp : 定义控制台应用程序的入口点。
//

//描述：给定两个数a，b，计算出a和b之间各个数字（0~9）出现的次数

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;


//计算0~num之间各数字出现的次数
void Countdigit(int num, int sign,int * count) {
	if (num <= 0)
		return;
	int rem = num % 10; 
	int ten = num / 10;
	//先加上各数字个位上各数字出现的次数
	for (int i = 0; i <= rem; i++) {
		count[i] += sign;
	}
	for (int i = 0; i < 10; i++) {
		count[i] += ten*sign;
	}
	//再加上最后（rem+1）个数的各个位上的数字出现次数
	while (num/10) {
		count[num / 10 % 10] += (rem + 1)*sign;
		num /= 10;
	}
	//最后减去首位为0的数字
	count[0] -= sign;
	sign *= 10;//计算各个数字前一位上各数字出现的次数
	Countdigit(ten - 1, sign, count);
	return;
}

//输出各个数字出现的个数
void Countput(int * count) {
	for (int i = 0; i < 10; i++) {
		cout << "Number " << i << " : " << count[i] << endl;
	}
	cout << endl;
}

int main()
{
	int a, b;
	cin >> a >> b;
	int count[10];//存放0~9每个数字出现的次数
	memset(count, 0, sizeof(count));//初始化count[0~9]=0
	Countdigit(b, 1, count);//计算出0~b之间各数字出现的字数，并存放进count[]数组中
	Countdigit(a-1, -1, count);//减去 0~（a-1）之间各数字出现的字数，并存放进count[]数组中
	Countput(count);//输出各个数字出现的个数
    return 0;
}

