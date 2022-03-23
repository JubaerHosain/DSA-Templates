#include<bits/stdc++.h>
using namespace std;
#define ninf -1e5

int a[100][100];
int price[100][100];
 
int cut_chocolate(int m, int n) {
    int x=ninf;
    int y=ninf;

    if(a[m][n] > ninf)
        return a[m][n];
 
    for(int i=1; i<=m; i++)
        x=max(x, price[i][n]+cut_chocolate(m-i, n));

    for(int i=1; i<=n; i++)
        y=max(y, price[m][i]+cut_chocolate(m, n-i));
    
    a[m][n] = max(x, y);
    return a[m][n];
}
 
int main(void){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin>>m>>n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>price[i][j];
        }
    }
   
    for(int i=0; i<=m; i++){
        a[i][0]=0;
    }
        
    for(int i=0; i<=n; i++){
        a[0][i]=0;
    }
        
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            a[i][j]= ninf;
        }
    }

    cout<<"Maximum revenue is: "<<cut_chocolate(m, n);

    return 0;
}