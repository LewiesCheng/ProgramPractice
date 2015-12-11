#include<iostream>
#include<cstdio>
#define PI 3.14159265358979323

using namespace std;

int main(){
	int r;
	cin>>r;
	double area = PI*r*r;
	printf("%.7lf",area);
	return 0;
}
