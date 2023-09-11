//간선 서로소 경로의 최대 개수 찾기 = 간선의 비용이 1인 최대 유량 찾기
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} 
int n,m,S,T;
int adj[405][405];
vector<int> ed[405];
bool getp(vector<int> &p, int S, int T){
	vector<int> prev(n+1,-1);
	queue<int> q; q.push(S);
	prev[S]=0;
	while(!q.empty() && prev[T]<0){
		int cur = q.front(); q.pop();
		for(int nxt : ed[cur])if(adj[cur][nxt] && prev[nxt]<0){
			prev[nxt]=cur;
			q.push(nxt);
		}
	}
	if(prev[T]<0) return false;
	int cur = T;
	while(cur){
		p.push_back(cur);
		cur=prev[cur];
	}
	reverse(all(p));
	return true;
}
int maxflow(int S, int T){
	vector<int> p;
	int ans=0,i;
	while(getp(p,S,T)){
		int flow=inf;
		for(i=1;i<p.size();i++) flow=min(flow,adj[p[i-1]][p[i]]);
		for(i=1;i<p.size();i++) adj[p[i-1]][p[i]]-=flow,adj[p[i]][p[i-1]]+=flow;
		ans+=flow;
		p.clear();
	}
	return ans;
}
int main()
{
	int tc,i,j,a,b;
    sync()
    cin>>n>>m;
    for(i=1;i<=m;i++){
    	cin>>a>>b;
    	adj[a][b]++;
    	ed[a].push_back(b);
    	ed[b].push_back(a); //인접행렬과 인접리스트를 혼용해서 네트워크 플로우를 짤 때는 역간선도 인접리스트에 추가해 주어야 한다.
    }
    cout<<maxflow(1,2);
    return 0;
}
