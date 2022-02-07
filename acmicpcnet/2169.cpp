#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m;
int d[1003][1003],dl[1003][1003],dr[1003][1003],A[1003][1003];
int main(){
    int i,j,k,sum;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>A[i][j];
        }
    }
    for(i=1;i<=m;i++) d[1][i]=d[1][i-1]+A[1][i];

    for(i=2;i<=n;i++){
        dl[i][1]=d[i-1][1]+A[i][1];
        for(j=2;j<=m;j++){
            dl[i][j]=max(d[i-1][j],dl[i][j-1])+A[i][j];
        }
        dr[i][m]=d[i-1][m]+A[i][m];
        for(j=m-1;j>=1;j--){
            dr[i][j]=max(d[i-1][j],dr[i][j+1])+A[i][j];
        }
        for(j=1;j<=m;j++) d[i][j]=max(dl[i][j],dr[i][j]);
    }
    cout<<d[n][m];
    return 0;
}
//n^3이면 10억인데 거기에 상수 10~20정도 붙으면 100억~200억이니까 시간초과