
//  ��Ŀ
//����7�����֣�����1������2������3��...����7���������ų�һ�С�
//Ҫ������1����1���������֣�����2����2���������֣��Դ����ƣ�����7֮����7���������֡� 
//ע�⣺ֻ��д���14λ��������������д�κζ�������ݣ�����˵��ע�͵ȡ�

#include<iostream>

using namespace std;

void putNum (int * num){
	for(int i = 0; i < 14; i++){
		cout << num[i];
	}
	cout << endl;
}

void rank (int * num, int * temp, int i){
	if(i == 14){
		putNum(num);
		return;
	}
	if(num[i])
		rank(num, temp, i+1);
	else{
		for(int j = 1; j <= 7; j++){
			if(temp[j])
				continue;
			if(i+j+1 < 14 && !num[i+j+1]){
				num[i] = j;
				num[i+j+1] = j;
				temp[j] = 1;
				rank(num, temp, i+1);
				num[i] = 0;
				num[i+j+1] = 0;
				temp[j] = 0;
			}	
		}
		return;
	}
	return;
}

int main(){
	int num[14] = {0};
	int temp[8] = {0};
	rank(num, temp, 0);
	return 0;
}
