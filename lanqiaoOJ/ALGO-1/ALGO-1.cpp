/**  lanqiaoOJ ALGO-1  */

// search  K max  

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int count (int * numT, int length, int k){
	sort(numT, numT + length);
	return numT[length-k];
}

int main(){
	int n;
	cin >> n;
	int num[1000];
	int numT[1000];
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	int m, time = 0;
	cin >> m;
	int mm = m;
	int *answer = new int[m];
	while(m > 0){
		int l, r, k;
		cin >> l >> r >> k;
		memcpy(numT, num + l - 1, (r-l+1) * sizeof(int));
		answer[time] = count(numT, r-l+1, k);
		++time;
		--m;
	}
	for(int i = 0; i < mm; i++){
		cout << answer[i] << endl;
	}
	return 0;
}
