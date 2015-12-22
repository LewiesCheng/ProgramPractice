//���x��x���ݽ��Ϊ10���μ���ͼ1.png���������ܼ����x�Ľ���ֵ��
//��Ȼ�����ֵ�ǽ���2��3֮���һ�����֡�
//���x��ֵ���㵽С����6λ���������룩������д���С��ֵ��
//ע�⣺ֻ��дһ��С������Ҫд�κζ���ķ��Ż�˵����

// if pow(x,x)=10, solve to seek x(six after decimal point and rounding off)

#include<stdio.h>
#include<math.h>

double count (double a, double b){
	if((int)(a*1000000) == (int)(b*1000000))
		return a;
	double temp = (a+b) / 2;
	if(pow(temp,temp) > 10)
		count(a, temp);
	else
		count(temp, b);
}

int main(){
	double a = 2, b = 3;
	double result;
	result = count(a, b);
	printf("%.6f",result);
	return 0;
} 
