#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
vector<int> e[803];
int cf[803][803];
bool getp(vector<int>&p,int S, int T){
	vector<int> prev(803,0);
	queue<int> q;
	q.push(S);
	prev[S]=S;
	while(!q.empty() && prev[T]==0){
		int cur = q.front(); q.pop();
		for(int nxt : e[cur])if(cf[cur][nxt] && prev[nxt]==0){
			prev[nxt]=cur;
			q.push(nxt);
		}
	}
	if(prev[T]==0) return false;
	int cur = T;
	while(cur!=S){
		p.push_back(cur);
		cur=prev[cur];
	}
	p.push_back(cur);
	reverse(all(p));
	return true;
}
int maxflow(int S, int T){
	vector<int> p;
	int ans=0,i;
	while(getp(p,S,T)){
		int flow = 1e9;
		for(i=1;i<p.size();i++) flow=min(flow,cf[p[i-1]][p[i]]);
		for(i=1;i<p.size();i++){
			cf[p[i-1]][p[i]]-=flow;
			cf[p[i]][p[i-1]]+=flow;
		}
		ans+=flow;
		p.clear();
	}
	return ans;
}
int main()
{
    int i,j,a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	cf[i][i+n]=1;
    	e[i].push_back(i+n);
    }
    for(i=1;i<=m;i++){
    	cin>>a>>b;

    	cf[a+n][b]=1;
    	cf[b+n][a]=1;
    	e[a+n].push_back(b);
    	e[b].push_back(a+n);
    	e[b+n].push_back(a);
    	e[a].push_back(b+n);
    }
    cout<<maxflow(1+n,2);
    return 0;
}
//1. 증강경로 찾기
//2. 증강경로 각각의 flow-=증강경로의 flow
/// 그래프를 그대로 모델링했는데 왜 틀렸을까 계속 고민했음.
/// 그런데 edmond karp를 하면서 그래프의 간선이 역으로 바뀔 수 있기 때문에 
/// 역간선도 인접 리스트에 넣어 주어야 한다.
