// try to understand more smartly

class Solution {
    int dp[101][101][101];
    
    int recur(int left, int right, int count, vector<int> &boxes) {
        if(left > right)
            return 0;
        else if(left == right)
            return count * count;
        else if(dp[left][right][count] != -1)
            return dp[left][right][count];
        
        int skip = count*count + recur(left+1, right, 1, boxes);
        int keep = 0;
        for(int l = left+1; l <= right; l++) {
            if(boxes[l] == boxes[left]) 
                keep = max(keep, recur(left+1, l-1, 1, boxes) + recur(l, right, count+1, boxes));
                
        }
        
        return dp[left][right][count] = max(skip, keep);
    }
    
public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        
        //l, r, streak, boxes
        return recur(0, boxes.size()-1, 1, boxes);
    }
};


