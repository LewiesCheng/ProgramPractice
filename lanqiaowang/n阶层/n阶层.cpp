#include <iostream>

using namespace std;

int main()
{
	int result[3000] = { 0 };
	result[0] = 1;
	int n;
	cin >> n;
	int carry = 0;
	for ( int i = 1; i <= n; i++ )
	{
		carry = 0;
		for ( int j = 0; j < 2999; j++ )
		{
			result[j] *= i;
			result[j] += carry;
			carry = result[j] / 10;
			result[j] %= 10;
		}
	}
	int i = 2999;
	for ( i = 2999; result[i] == 0; i-- );
	for ( int j = i; j >= 0; j-- )
	{
		cout << result[j];
	}
	return 0;
}
