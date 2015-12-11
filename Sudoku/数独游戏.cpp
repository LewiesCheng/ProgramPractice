/** Sudoku **/
//缺点：已经默认是数独，没有讨论给的数据非数独情况
//待改进 

#include <iostream>

using namespace std;

//输出宫格
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

//检查是否符合要求
int check(int i, int j, char num[][9], char figure){
	
	int k = 0;
	
	//检查行
	for(k = 0; k < 9; k++){
		if(figure == num[i][k])
			return 0;
	}
	
	//检查列
	for(k = 0; k < 9; k++){
		if(figure == num[k][j])
			return 0;
	}
	
	//检查九宫里
	for(int r=i/3*3; r < i/3*3+3; r++){
		for(int c=j/3*3; c < j/3*3+3; c++){
			if(figure == num[r][c])
				return 0;
		}
	}
	return 1;
}

//填充表格 
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
