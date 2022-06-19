// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
private:
    long long count = 0;
    
    void merge(long long arr[], int left, int mid, int right) {
        vector<long long> tmp(right-left+1);
        int i = left, j = mid+1, k = 0;
        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j]) {
                tmp[k++] = arr[i++];
            } else {
                count += mid-i+1;
                tmp[k++] = arr[j++];
            }
        }
        
        while(i <= mid) 
            tmp[k++] = arr[i++];
        while(j <= right)
            tmp[k++] = arr[j++];
            
        for(int l = left; l <= right; l++)
            arr[l] = tmp[l-left];
    }
    
    void sort(long long arr[], int left, int right) {
        if(left >= right)
            return;
        int mid = (left+right)/2;
        sort(arr, left, mid);
        sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N) {
        int n = (int)N;
        sort(arr, 0, n-1);
        return count;
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