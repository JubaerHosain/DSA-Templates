typedef long long ll;

class Solution {
    ll mod = 1e9 + 7;
    ll dp[2][25][405];

    ll get_count(int tight, int pos, int sum, string &num, int min_sum, int max_sum) {
        if(pos == num.size()) {
            return sum >= min_sum && sum <= max_sum;
        }

        if(dp[tight][pos][sum] != -1)
            return dp[tight][pos][sum];

        int limit = 9;
        if(tight)
            limit = num[pos] - '0';

        ll res = 0;
        for(int i = 0; i <= limit; i++) {
            int nextTight = tight;
            if(tight && i < limit)
                nextTight = 0;
            
            res += get_count(nextTight, pos+1, sum+i, num, min_sum, max_sum);
            res %= mod;
            
        }

        dp[tight][pos][sum] = res;

        return res;
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        ll low = get_count(1, 0, 0, num1, min_sum, max_sum);

        memset(dp, -1, sizeof(dp));
        ll high = get_count(1, 0, 0, num2, min_sum, max_sum);

        int sum = 0;
        for(char c: num1) 
            sum += (c - '0');

        if(sum >= min_sum && sum <= max_sum)
            high += 1;

        ll ans = (high - low + mod) % mod;

        return (int) ans;
    }
};
