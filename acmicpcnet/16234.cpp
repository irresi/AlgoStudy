#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,L,R,arr[53][53],ans;
vector<pii> w={{0,1},{1,0},{0,-1},{-1,0}};
int sum[2503],divnum[2503];
int main()
{
	int i,j;
    cin>>n>>L>>R;
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		cin>>arr[i][j];
    	}
    }
    for(i=1;i<=n;i++) arr[0][i]=arr[n+1][i]=arr[i][0]=arr[i][n+1]=inf;
    int flag=1,diff,nr,nc;
    for(ans=0;flag;ans++){
    	flag=0;
    	vector<vector<int>> chk(n+2,vector<int>(n+2,0));
    	queue<pii> q;
    	int cnt=0;
    	for(i=1;i<=n;i++){
    		for(j=1;j<=n;j++)if(!chk[i][j]){
    			chk[i][j]=++cnt;
    			q.push({i,j});
    			sum[cnt]=arr[i][j];
    			divnum[cnt]=1;
    			while(!q.empty()){
    				auto [r,c] = q.front(); q.pop();
    				for(auto [tr,tc] : w){
    					nr=r+tr; nc=c+tc;
    					diff=abs(arr[r][c]-arr[nr][nc]);
    					if(!chk[nr][nc] && L<=diff && diff<=R){
    						chk[nr][nc]=cnt;
    						sum[cnt]+=arr[nr][nc];
    						divnum[cnt]++;
    						flag=1;
    						q.push({nr,nc});
    					}
    				}
    			}
    		}
    	}
    	for(i=1;i<=cnt;i++) sum[i]/=divnum[i];
    	for(i=1;i<=n;i++){
    		for(j=1;j<=n;j++){
    			arr[i][j]=sum[chk[i][j]];
    		}
    	}
    }
    cout<<ans-1;
    return 0;
}
