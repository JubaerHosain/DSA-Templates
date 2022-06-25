
/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the 
inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

1 ≤ N ≤ 5*1e5
1 ≤ arr[i] ≤ 1e18
**/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> BIT;
    
    vector<long long> compressArray(long long arr[], long long N) {
        map<long long, int> mp;
        for(int i = 0; i < N; i++) {
            mp[arr[i]] = 0;
        }
    
        int cnt = 1; 
        for(auto &it: mp) 
            it.second = cnt++;
    
        // compressed array
        vector<long long> b(N); 
        for(int i = 0; i < N; i++) {
            b[i] = mp[arr[i]];
        }
        
        return b;
    }
    
    void update(int i, int x, int n) {
        while(i <= n) {
            BIT[i] += x;
            i += (i&-i);
        }
    }
    
    int prefix_sum(int i) {
        int sum = 0;
        while(i > 0) {
            sum += BIT[i];
            i -= (i&-i);
        }
        return sum;
    }
    
    int get_inversion(int x, int n) {
        return prefix_sum(n) - prefix_sum(x);
    }
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N) {
        vector<long long> a = compressArray(arr, N);
        
        int n = *max_element(a.begin(), a.end());
        BIT.resize(n+1);
        
        long long cnt = 0;
        for(int i = 0; i < N; i++) {
            cnt += get_inversion(a[i], n);
            // use a[i] as index
            update(a[i], 1, n);
        }
        
        return cnt;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends