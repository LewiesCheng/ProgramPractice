/** Sudoku **/
//ȱ�㣺ֻ����һ��
//���Ľ� 

#include <iostream>

using namespace std;

//�������
void put(char num[][9]){
	cout << endl;
	for(int i=0; i < 9; i++){
		for(int j=0; j < 9; j++){
			cout << num[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//����Ƿ����Ҫ��
int check(int i, int j, char num[][9], char figure){
	
	int k = 0;
	
	//�����
	for(k = 0; k < 9; k++){
		if(figure == num[i][k])
			return 0;
	}
	
	//�����
	for(k = 0; k < 9; k++){
		if(figure == num[k][j])
			return 0;
	}
	
	//���Ź���
	for(int r=i/3*3; r < i/3*3+3; r++){
		for(int c=j/3*3; c < j/3*3+3; c++){
			if(figure == num[r][c])
				return 0;
		}
	}
	return 1;
}

//����� 
int fill_form(int i, int j,char num[][9]){
	if(i==9 && j==0){
		put(num);
		return 1;
	}
	char figure = '1';
	if(num[i][j] == '0'){
		for(int k=0; k < 9; k++){
			if(check(i, j, num, (figure+k))){
				num[i][j] =  (figure+k);
				if(fill_form(i+j/8, (j+1)%9, num)) return 1;
			}
			num[i][j] = '0';
		}
		
	}
	else{
		if(fill_form(i+j/8, (j+1)%9, num)) return 1;
	}
	return 0;
}

int main( ){
	char num[9][9];
	for(int i=0; i < 9; i++){
		for(int j=0; j < 9; j++){
			cin >> num[i][j];
		}
		getchar();
	}
	fill_form(0, 0, num);
	return 0; 
} 
