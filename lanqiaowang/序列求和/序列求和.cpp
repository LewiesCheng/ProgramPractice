#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long sum = (long long)(1+n) * n / 2;
	printf("%I64d",sum);
	return 0;
}
