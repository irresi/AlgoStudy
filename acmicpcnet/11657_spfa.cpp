#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const ll inf=1e18+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
vector<pll> ed[503];
int vis[503],chk[503];
ll dist[503];
int main()
{
	int a,b,c,i,j;
    cin>>n>>m;
    for(i=1;i<=m;i++){
    	cin>>a>>b>>c;
    	ed[a].push_back({b,c});
    }
    for(i=1;i<=n;i++){
    	sort(all(ed[i]),[&](pll A,pll B){
    		return A.second<B.second;
    	});
    }
    fill(dist+2,dist+1+n,inf);
    queue<int> q;
    q.push(1);
    while(!q.empty()){
    	int cur = q.front(); q.pop();
    	for(auto [nxt,cost] : ed[cur]){
    		if(dist[nxt]>dist[cur]+cost){
    			dist[nxt] = dist[cur]+cost;
    			vis[nxt]++;
    			if(vis[nxt]>=n){ //음수사이클
    				cout<<"-1";
    				return 0;
    			}
    			q.push(nxt);
    		}
    	}
    }
    for(i=2;i<=n;i++){
    	if(dist[i]==inf) dist[i]=-1;
    	cout<<dist[i]<<'\n';
    }
    return 0;
}
