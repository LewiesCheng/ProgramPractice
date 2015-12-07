/* from lanqiaownag-»ù´¡Á·Ï°  */
/* Ñî»ÔÈý½ÇÐÎ  */ 

#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n;
	cin >> n;                       //1 <= n <= 34 
	int array[35] = { 1,0 };	
	cout << array[0] << endl;
	for(int i=1; i < n; i++){
		array[i] = 1;
		for(int j=i-1; j > 0; j--){
			array[j] = array[j] + array[j-1];
		}
		for(int j=0; j <= i; j++){
			if(j != i)
				cout << array[j] << ' ';
			else
				cout << array[j] << endl;
		}
	}
	return 0;
} 
