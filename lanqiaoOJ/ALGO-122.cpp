/** lanqiaoOJ ALGO-122 */

//未名湖边的烦恼
// 问题描述
// 　　每年冬天，北大未名湖上都是滑冰的好地方。北大体育组准备了许多冰鞋，可是人太多了，每天下午收工后，常常一双冰鞋都不剩。
// 　　每天早上，租鞋窗口都会排起长龙，假设有还鞋的m个，有需要租鞋的n个。现在的问题是，这些人有多少种排法，可以避免出现体育组没有冰鞋可租的尴尬场面。（两个同样需求的人（比如都是租鞋或都是还鞋）交换位置是同一种排法）
// 输入格式
// 　　两个整数，表示m和n
// 输出格式
// 　　一个整数，表示队伍的排法的方案数。
// 样例输入
// 3 2
// 样例输出
// 5
// 数据规模和约定
// 　　m,n∈［0,18］

#include <iostream>

using namespace std;

int fun(int M, int N, int m, int n){
	if(M < N){
		return 0;
	}
	if(M == m || N == n){
		return 1;
	}
	if(m == n){
		return fun(M, N, m + 1, n);
	}
	else{
		return fun(M, N, m + 1, n) + fun(M, N, m, n + 1);
	}
}

int main(){
	int m, n;
	cin >> m >> n;
	cout << fun(m, n, 0, 0) << endl; 
	return 0;
}
