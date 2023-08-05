class Solution {
    int mod = 1e9 + 7;
    int dp[2][2][10][100];

    int count_stepping(bool constraint, bool contZero, int prevDigit, int pos, string str) {
        if(pos == str.size()) {
            if(contZero)
                return 0;
            return 1;
        }

        if(dp[constraint][contZero][prevDigit][pos] != -1)
            return dp[constraint][contZero][prevDigit][pos];

        int limit = 9;
        if(constraint)
            limit = str[pos] - '0';

        int res = 0;
        for(int currDigit = 0; currDigit <= limit; currDigit++) {
            bool nextConstraint = constraint;
            if(constraint && currDigit < limit)
                nextConstraint = 0;

            bool nextContZero = contZero;
            if(contZero && currDigit > 0)
                nextContZero = 0;


            if(contZero) {
                res += count_stepping(nextConstraint, nextContZero, currDigit, pos+1, str);
                res %= mod;
            }
            else {
                if(abs(currDigit-prevDigit) == 1) {
                    res += count_stepping(nextConstraint, nextContZero, currDigit, pos+1, str);
                    res %= mod;
                }
            }
        }

        dp[constraint][contZero][prevDigit][pos] = res;

        return res;
    }

    int is_stepping(string s) {
        for(int i = 1; i < s.size(); i++) {
            if(abs(s[i]-s[i-1]) != 1)
                return 0;
        }

        return 1;
    }

public:
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        int lw = count_stepping(true, true, 0, 0, low);

        memset(dp, -1, sizeof(dp));
        int hg = count_stepping(true, true, 0, 0, high);
        hg += is_stepping(low);
        return (hg-lw+mod)%mod;
    }
};
