//如果x的x次幂结果为10（参见【图1.png】），你能计算出x的近似值吗？
//显然，这个值是介于2和3之间的一个数字。
//请把x的值计算到小数后6位（四舍五入），并填写这个小数值。
//注意：只填写一个小数，不要写任何多余的符号或说明。

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
