// Countdigits.cpp : �������̨Ӧ�ó������ڵ㡣
//

//����������������a��b�������a��b֮��������֣�0~9�����ֵĴ���

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;


//����0~num֮������ֳ��ֵĴ���
void Countdigit(int num, int sign,int * count) {
	if (num <= 0)
		return;
	int rem = num % 10; 
	int ten = num / 10;
	//�ȼ��ϸ����ָ�λ�ϸ����ֳ��ֵĴ���
	for (int i = 0; i <= rem; i++) {
		count[i] += sign;
	}
	for (int i = 0; i < 10; i++) {
		count[i] += ten*sign;
	}
	//�ټ������rem+1�������ĸ���λ�ϵ����ֳ��ִ���
	while (num/10) {
		count[num / 10 % 10] += (rem + 1)*sign;
		num /= 10;
	}
	//����ȥ��λΪ0������
	count[0] -= sign;
	sign *= 10;//�����������ǰһλ�ϸ����ֳ��ֵĴ���
	Countdigit(ten - 1, sign, count);
	return;
}

//����������ֳ��ֵĸ���
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
	int count[10];//���0~9ÿ�����ֳ��ֵĴ���
	memset(count, 0, sizeof(count));//��ʼ��count[0~9]=0
	Countdigit(b, 1, count);//�����0~b֮������ֳ��ֵ�����������Ž�count[]������
	Countdigit(a-1, -1, count);//��ȥ 0~��a-1��֮������ֳ��ֵ�����������Ž�count[]������
	Countput(count);//����������ֳ��ֵĸ���
    return 0;
}

