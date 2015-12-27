//from lanqiao-4-7

//  写的较为垃圾，待改进，结果能运行 
//
//标题：错误票据
//    某涉密单位下发了某种票据，并要在年终全部收回。
//    每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。
//    因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。
//    你的任务是通过编程，找出断号的ID和重号的ID。
//    假设断号不可能发生在最大和最小号。
//
//要求程序首先输入一个整数N(N<100)表示后面数据行数。
//接着读入N行数据。
//每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000）
//每个整数代表一个ID号。
//
//要求程序输出1行，含两个整数m n，用空格分隔。
//其中，m表示断号ID，n表示重号ID

#include<iostream>

using namespace std;

int ID[100][100] = { 0 };

int main( ) {
	int N;
	cin >> N;
	
	int min_id = 1000000;
	for(int i = 0; i < N; i++) {
		for(int j = 0; ; j++) {
			cin >> ID[i][j];
			if(cin.get() == '\n'){
				break;
			}
			if( ID[i][j] < min_id ) {
				min_id = ID[i][j];
			}
		}
	}
	
	int break_id = 0, repeat_id = 0;
	bool temp_b = 0, temp_r = 0;
	
	for(int i = min_id + 1; ; i++) {
		temp_b = 0;
		if( !repeat_id ) {
			temp_r = 0;
		}
		for(int j = 0; j < N; j++) {
			for(int k = 0; ID[j][k] != 0; k++) {
				if( i == ID[j][k] ) {
					temp_b = 1;
					if( !repeat_id && !temp_r ) {
						temp_r = 1;
					}
					else if( temp_r ){
						repeat_id = i;
						break;
					}
					else break;
				}
			}
			if( temp_b && repeat_id ) break;
		}
		if( !temp_b ) {
			break_id = i;
		}
		if( break_id && repeat_id ) {
			break;
		}
	}
	
	cout << break_id << ' ' << repeat_id << endl;
	return 0;
}
