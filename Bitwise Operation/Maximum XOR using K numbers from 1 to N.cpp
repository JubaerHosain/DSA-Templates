//each element can use multiple times

#include <bits/stdc++.h>
using namespace std;

int maxXorSum(int n, int k) {
	if (k == 1)
		return n;

	int res = 1;
	while (res <= n)
		res <<= 1;

	//return 2^exp - 1
    //exp = 32 - __builtin_clz(n);

	return res - 1;
}

// Driver program
int main() {
	int n = 12, k = 7;
	cout << maxXorSum(n, k) << endl;
	return 0;
}
