
//  题目
//今有7对数字：两个1，两个2，两个3，...两个7，把它们排成一行。
//要求，两个1间有1个其它数字，两个2间有2个其它数字，以此类推，两个7之间有7个其它数字。 
//注意：只填写这个14位的整数，不能填写任何多余的内容，比如说明注释等。

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
