#include<bits/stdc++.h>
using namespace std;

// CGEL = Count Greater Element on the Left
vector<int> a, inx, cgel;

void merge(vector<int> &a, vector<int> &inx,  int left, int mid, int right) {
    vector<int> tmp(right-left+1);
    int i = left, j = mid+1, k = 0;

    // sort in non-decreasing order
    while(i <= mid && j <= right) {
        if(a[inx[i]] <= a[inx[j]]) {
            tmp[k++] = inx[i++];
        } else {
            cgel[inx[j]] += mid - i + 1;
            tmp[k++] = inx[j++];
        }
    }

    while(i <= mid) 
        tmp[k++] = inx[i++];
    while(j <= right)
        tmp[k++] = inx[j++];

    for(int l = left; l <= right; l++)
        inx[l] = tmp[l-left]; 
}

void sort(vector<int> &a, vector<int> &inx,  int left, int right) {
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    sort(a, inx, left, mid);
    sort(a, inx, mid+1, right);
    merge(a, inx, left, mid, right);
}

int main(void) {
    freopen("input.txt", "r", stdin);


    int n;
    cin >> n;

    a.resize(n);
    inx.resize(n);
    cgel.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        inx[i] = i;
    }

    sort(a, inx, 0, n-1);

    for(int i = 0; i < n; i++) 
        cout << a[inx[i]] << " ";

    cout << endl;
    for(int i = 0; i < n; i++) 
        cout << cgel[i] << " ";
}