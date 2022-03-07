#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}
int n,m,S,T,anscost,ansflow;
int costs[203][203],cf[203][203];
int main()
{
	int tc,i,j,num;
    sync()
    cin>>n>>m;
    S=0,T=n+m+1;
    for(i=1;i<=n;i++) cin>>cf[S][i];
    for(i=n+1;i<=n+m;i++) cin>>cf[i][T];
    for(i=n+1;i<=n+m;i++){
    	for(j=1;j<=n;j++){
    		cin>>costs[j][i];
    		costs[i][j]=-costs[j][i];
    		cf[j][i]=inf;
    	}
    }
    while(1){
    	vector<int> C(n+m+2,inf),prev(n+m+2,-1);
    	vector<bool> inQ(n+m+2,false);
    	queue<int> q;
    	q.push(S); C[S]=0;
    	while(!q.empty()){
    		int cur = q.front(); q.pop(); inQ[cur]=false;
    		for(int nxt=1;nxt<=n+m+1;nxt++)if(cf[cur][nxt] && C[cur]+costs[cur][nxt]<C[nxt]){
    			C[nxt]=C[cur]+costs[cur][nxt];
    			prev[nxt]=cur;
    			if(!inQ[nxt]){
    				inQ[nxt]=true;
    				q.push(nxt);
    			}
    		}
    	}
    	if(prev[T]==-1) break;
    	int flow=inf;
    	for(i=T;i!=S;i=prev[i]) flow=min(flow,cf[prev[i]][i]);
    	for(i=T;i!=S;i=prev[i]){
    		cf[prev[i]][i]-=flow;
    		cf[i][prev[i]]+=flow;
    		anscost+=costs[prev[i]][i]*flow;
    	}
    	//ansflow+=flow;
    }
    cout<<anscost;
    return 0;
}
