#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define endl '\n'
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int st[n][m][10];
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                st[i][j][0]=a[i][j];
            }
        }
        for(int k=1;k<=log2(min(n,m));k++){
            for(int i=0;i+(1<<k)<=n;i++){
                for(int j=0;j+(1<<k)<=m;j++){
                    st[i][j][k]=min(min(st[i][j][k-1],st[i+(1<<(k-1))][j][k-1]),min(st[i][j+(1<<(k-1))][k-1],st[i+(1<<(k-1))][j+(1<<(k-1))][k-1]));
                }
            }
        }
        int l=1;
        int r=min(n,m);
        while(l<r){
            int x=(l+r+1)/2;
            int z=0;
            int p=log2(x);
            for(int i=0;i+x<=n;i++){
                for(int j=0;j+x<=m;j++){
                    if(min(min(st[i][j][p],st[i+x-(1<<p)][j+x-(1<<p)][p]),min(st[i][j+x-(1<<p)][p],st[i+x-(1<<p)][j][p]))>=x){
                        z=1;
                    }
                }
            }
            if(z){
                l=x;
            }
            else{
                r=x-1;
            }
        }
        cout<<l<<endl;
    }
}
