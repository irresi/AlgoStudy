#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,arr[1003][1003],d[1003][1003],sum[1003][1003];

int main()
{
	int i,j,k;
    for(i=1;i<=n;i++){
    	for(j=1;j<=m;j++){
    		cin>>arr[i][j];
    		sum[i][j]=sum[i][j-1]+arr[i][j];
    	}
    }
    for(i=1;i<=n+1;i++){
    	for(j=1;j<=m;j++){
    		for(k=j+1;k<=m;k++){ //j~ㅏ
    			d[i][j]=max(d[i][j],d[i-1][k]+sum[i][k]-sum[i][j-1]);
    			d[i][k]=max(d[i][k],d[i-1][j]+sum[i][k]-sum[i][j-1]);
    		}
    	}
    }
    cout<<sum[n+1][1];
    return 0;
}
