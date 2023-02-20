#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += (n&1);
        n = n >> 1;
    }
    return count;
}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int a, b;
         cin >> a >> b;

        int count = 0;
        for (int i = a; i <= b; i++)
        {
            // Check if the no is even and is less than b
            if ((i&1) == 0 && i < b)
            {
                count += 2 * countSetBits(i) + 1;
                i++;
                continue;
            }
            count += countSetBits(i);
        }
        cout << count << '\n';
    }
    return 0;
}


