
/*   ��Ŀ  */ 
//  ���ɶ���������Ϊ�ϴ����˹����������Ӧ�����������ڳ�Ϊ��ֱ�������Ρ�
//
//  ��ֱ֪�������ε�б����ĳ������������Ҫ������������Ҳ������������
//
//  ��������������Ĳ�ֱͬ�������εĸ�����

#include <iostream>
#include <cmath>

using namespace std;

int main( ){
	int n;     // n��ֱ�������εĳ���   0 < n < 10000000  
	cin >> n;
	int count = 0;  // ���ϵ�ֱ�������ε���Ŀ
	float side_2;
	for(int side_1=1; side_1 <= (int)(n/1.414); side_1++){
		side_2 = sqrt(n*n-side_1*side_1);
		if((int)side_2 == side_2)
			count++;
	}
	cout << count << endl;
	return 0;	
} 
