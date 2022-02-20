#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m;
int chk[1003][1003],arr[1003][1003],cur[1003][1003];
int w[4][2]={0,1,1,0,0,-1,-1,0};
queue<pii> q;
vector<array<int,3>> ans;
int main()
{
	int i,j,r,c,nr,nc;
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	for(j=1;j<=m;j++){
    		cin>>arr[i][j];
    	}
    }
    for(i=0;i<=n;i++) arr[i][0]=arr[i][m+1]=1;
    for(i=0;i<=m;i++) arr[0][i]=arr[n+1][i]=1;
    q.push({1,1}); chk[1][1]=1;
    q.push({1,m}); chk[1][m]=1;
    q.push({n,1}); chk[n][1]=1;
    q.push({n,m}); chk[n][m]=1;
    while(!q.empty()){
    	auto [r,c] = q.front(); q.pop();
    	if(cur[r][c]!=arr[r][c]){
    		ans.push_back({r,c,arr[r][c]});
    		cur[r][c]=cur[r+1][c]=cur[r][c+1]=cur[r+1][c+1]=arr[r][c];
    	}
    	for(i=0;i<4;i++){
    		nr = r+w[i][0]; nc = c+w[i][1];
    		if(!chk[nr][nc]){
    			q.push({nr,nc});
    			chk[nr][nc]=1;
    		}
    	}
    }
    for(i=1;i<=n;i++){
    	for(j=1;j<=m;j++){
    		if(arr[i][j]!=cur[i][j]){
    			cout<<-1;
    			return 0;
    		}
    	}
    }
    cout<<ans.size();
    for(auto [a,b,c] : ans) cout<<a<<' '<<b<<' '<<c<<'\n';
    return 0;
}
