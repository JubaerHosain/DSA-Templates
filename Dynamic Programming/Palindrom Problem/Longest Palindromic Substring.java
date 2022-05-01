class Solution {
    public String longestPalindrome(String s) {
        if(s.length() == 0){
            return s;
        }
        
        int start = 0, maxLen = 1, n = s.length();
        boolean dp[][] = new boolean[n][n];
        
        //palindrom for length 1
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        
        //check palindrom for length 2
        for(int i = 0; i < n-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        //check palindrom for length >= 3
        for(int k = 3; k <= n; k++){
            for(int i = 0; i < n-k+1; i++){
                int j = i+k-1;
                
                if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1]){
                    dp[i][j] = true;
                    
                    if(k > maxLen){
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }
        
        return s.substring(start,start+maxLen);
    }
}
