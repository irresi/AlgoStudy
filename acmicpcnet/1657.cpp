#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}
int n,m,score[5][5]={
	10,8,7,5,1,
	8,6,4,3,1,
	7,4,3,2,1,
	5,3,2,2,1,
	1,1,1,1,0
};
char inp[15][15];
int d[225][1<<14];
int main()
{
	int tc,i,j;
    sync()
    cin>>n>>m;
    for(i=0;i<n;i++){
    	cin>>inp[i];
    	for(j=0;j<m;j++){
    		if(inp[i][j]=='F') inp[i][j]--;
    		inp[i][j]-='A';
    	}
    }
    int r,c,nxtstate;
    for(i=1;i<(1<<n);i++) d[0][i]=-inf;
    for(i=1;i<=n*m;i++){
    	r=(i-1)%n; c=(i-1)/n;
    	for(j=0;j<(1<<(n-1));j++) d[i][j]=max(d[i-1][j<<1|1],d[i-1][j<<1]);
    	for(j=0;j<(1<<n);j+=2){
    		nxtstate=j>>1|(1<<(n-1));
    		if(c!=m-1) d[i][nxtstate]=max(d[i][nxtstate],d[i-1][j]+score[inp[r][c]][inp[r][c+1]]);
    		nxtstate=j>>1|1;
    		if(r!=n-1 && !(j&2)) d[i][nxtstate]=max(d[i][nxtstate],d[i-1][j]+score[inp[r][c]][inp[r+1][c]]);
    	}
    }
    cout<<d[n*m][0];
    return 0;
}
