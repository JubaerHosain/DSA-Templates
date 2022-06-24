class Solution {
private:
    // CSEL = Count Smaller Element on the Left
    // CGEL = Count Greater Element on the Left
    vector<int> csel, cgel;
    int mod = 1e9+7;
    
    void merge(vector<int> &a, vector<int> &inx1, vector<int> &inx2,  int left, int mid, int right) {
        vector<int> tmp(right-left+1);
        
        // sort in non-increasing order
        int i = left, j = mid+1, k = 0;
        while(i <= mid && j <= right) {
            if(a[inx1[i]] >= a[inx1[j]]) {
                tmp[k++] = inx1[i++];
            } else {
                csel[inx1[j]] += mid - i + 1;
                tmp[k++] = inx1[j++];
            }
        }

        while(i <= mid) 
            tmp[k++] = inx1[i++];
        while(j <= right)
            tmp[k++] = inx1[j++];

        for(int l = left; l <= right; l++)
            inx1[l] = tmp[l-left]; 
        
        // sort in non-decreasing order
        i = left, j = mid+1, k = 0;
        while(i <= mid && j <= right) {
            if(a[inx2[i]] <= a[inx2[j]]) {
                tmp[k++] = inx2[i++];
            } else {
                cgel[inx2[j]] += mid - i + 1;
                tmp[k++] = inx2[j++];
            }
        }

        while(i <= mid) 
            tmp[k++] = inx2[i++];
        while(j <= right)
            tmp[k++] = inx2[j++];

        for(int l = left; l <= right; l++)
            inx2[l] = tmp[l-left]; 
    }
    
    void sort(vector<int> &a, vector<int> &inx1, vector<int> &inx2,  int left, int right, int flag) {
        if(left >= right)
            return;
        int mid = (left + right) / 2;
        sort(a, inx1, inx2, left, mid, flag);
        sort(a, inx1, inx2, mid+1, right, flag);
        merge(a, inx1, inx2, left, mid, right);
    }
    
public:
    int createSortedArray(vector<int>& a) {
        int n = a.size();
        vector<int> inx1(n), inx2(n);
        csel.resize(n);
        cgel.resize(n);
        
        for(int i = 0; i < n; i++)
            inx1[i] = inx2[i] = i;
        
        sort(a, inx1, inx2, 0, n-1, 1);
        
        int ans = 0;
        for(int i = 0; i < n; i++) 
            ans = (ans + min(csel[i], cgel[i])) % mod;
    
        return ans;
    }
};





