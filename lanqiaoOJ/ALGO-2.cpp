/**  lanqiaoOJ ALGO-2 */
// the  maximum  of  minimum common multiple

//问题描述
//已知一个正整数N，问从1~N中任选出三个数，他们的最小公倍数最大可以为多少。
//
//输入格式
//输入一个正整数N。
//
//输出格式
//输出一个整数，表示你找到的最小公倍数。
//样例输入
//9
//样例输出
//504
//数据规模与约定
//1 <= N <= 106。


#include <cstdio> 

int main(){
	double N;
	scanf("%lf",&N);
	int n = N;
	if(n % 2){
		printf("%.0f",N * (N-1) * (N-2));
	}
	else{
		if(n % 3){
			printf("%.0f",N * (N-1) * (N-3));
		}
		else{
			printf("%.0f",(N-1) * (N-2) * (N-3));
		}
			
	}
	return 0;
}
