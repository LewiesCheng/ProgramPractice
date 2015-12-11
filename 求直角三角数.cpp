
/*   题目  */ 
//  勾股定理，西方称为毕达哥拉斯定理，它所对应的三角形现在称为：直角三角形。
//
//  已知直角三角形的斜边是某个整数，并且要求另外两条边也必须是整数。
//
//  求满足这个条件的不同直角三角形的个数。

#include <iostream>
#include <cmath>

using namespace std;

int main( ){
	int n;     // n是直角三角形的长度   0 < n < 10000000  
	cin >> n;
	int count = 0;  // 符合的直角三角形的数目
	float side_2;
	for(int side_1=1; side_1 <= (int)(n/1.414); side_1++){
		side_2 = sqrt(n*n-side_1*side_1);
		if((int)side_2 == side_2)
			count++;
	}
	cout << count << endl;
	return 0;	
} 
