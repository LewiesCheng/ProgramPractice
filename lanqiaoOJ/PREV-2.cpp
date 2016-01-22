/** lanqiaoOJ PREV-2 */

#include <iostream>
#include <cstring>

using namespace std;

void assign (char **map, int row) {
	for(int i = 0; i < row; i++) {
		if(i >= (row / 2 - 2) && i <= (row / 2 + 2))
			map[row / 2][i] = '$';
		else if(i % 2 == 0)
			map[row / 2][i] = '$';
		else
			map[row / 2][i] = '.';
	}
	
	map[0][0] = map[0][1] = map[0][row-1] = map[0][row-2] = '.';
	for(int i = 2; i < row - 2; i++){
		map[0][i] = '$';
	}
	
	for(int i = 0; i < row; i++) {
		map[1][i] = '.';
	}
	map[1][2] = map[1][row-3] = '$';
	
	for(int i = 2; i < row / 2; i++) {
		if(i % 2 == 0){
			for(int j = i - 2; j <= row - i + 1; j++){
				map[i][j] = '$';
			}
			map[i][i+1] = map[i][row-i-2] = '.';
			for(int j = 0; j < i - 2; j++) {
				if(j % 2 == 0)
					map[i][j] = map[i][row-j-1] = '$';
				else
					map[i][j] = map[i][row-j-1] = '.';
			}
		}
		else {
			for(int j = i - 2; j <= row - i + 1; j++){
				map[i][j] = '.';
			}
			map[i][i+1] = map[i][row-i-2] = '$';
			for(int j = 0; j < i - 2; j++) {
				if(j % 2 == 0)
					map[i][j] = map[i][row-j-1] = '$';
				else
					map[i][j] = map[i][row-j-1] = '.';
			}
		}
	}
	
	for(int i = row / 2 + 1; i < row; i++) {
		memcpy(map[i], map[row-i-1], row);
	}
}

int main() {
	int n;
	cin >> n;
	int row, column;
	row = column = 4 * n + 5;
	char **map = new char *[row];
	for(int i = 0; i < row; i++) {
		map[i] = new char[column];
	}
	assign(map, row);
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}
