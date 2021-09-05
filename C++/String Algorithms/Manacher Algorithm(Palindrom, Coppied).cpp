#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

vector<int> manacher(const string &s)
{
	int n = 2 * s.length();
	vector<int> rad(n);

	for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0))
	{
		for( ; i >= j && i + j + 1 < n 
			&& s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j);

		rad[i] = j;

		for (k = 1; i >= k && rad[i] >= k 
			&& rad[i - k] != rad[i] - k; ++k)
			rad[i + k] = min(rad[i - k], rad[i] - k);
	}

	return rad;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	auto rad = manacher(s);
	cout << *max_element(rad.begin(), rad.end()) << endl;
	
	return 0;
}
