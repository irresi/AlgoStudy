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
int go(int x, int state){
    if(x>=n*m) return 0;
    if(d[x][state]>=0) return d[x][state];
    int &ans=d[x][state]=0,r=x%n,c=x/n;
    ans=max(ans,go(x+1,state>>1));
    if(!(state&1) && (c!=m-1)) ans=max(ans,go(x+1,(state>>1)|(1<<(n-1)))+score[inp[r][c]][inp[r][c+1]]);
    if(!(state&3) && (r!=n-1)) ans=max(ans,go(x+2,state>>2)+score[inp[r][c]][inp[r+1][c]]);
    return ans;
}
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
    fill(d[0],d[0]+sizeof(d)/sizeof(int),-1);
    cout<<go(0,0);
    return 0;
}
