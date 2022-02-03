#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m,k;
struct edge{
	int target, capacity, flow;
	edge* rev;
	edge(int a, int b, int c=0):target(a),capacity(b),flow(c){}
	int cf(){return capacity-flow;}
	void push(int num){
		flow+=num;
		rev->capacity+=num;
	}
};
vector<edge*> ed[2005];
void addedge(int u, int v, int c){
	edge *uv = new edge(v,c), *vu = new edge(u,0);
	uv->rev=vu; vu->rev=uv;
	ed[u].push_back(uv); ed[v].push_back(vu);
}
bool getp(vector<edge*>&p, int S, int T){
	vector<edge*> prev(n+m+3,nullptr);
	queue<int> q;
	q.push(S); prev[S]=new edge(S,0);
	while(!q.empty() && prev[T]==nullptr){
		int tp = q.front(); q.pop();
		for(auto& nxt : ed[tp])if(prev[nxt->target]==nullptr && nxt->cf()){
			q.push(nxt->target);
			prev[nxt->target]=nxt;
		}
	}
	if(prev[T]==nullptr) return false;
	int cur = T;
	while(cur!=S){
		p.push_back(prev[cur]);
		cur=prev[cur]->rev->target;
	}
	reverse(all(p));
	return true;
}
int maxflow(int S, int T){
	int ret=0;
	vector<edge* > p;
	while(getp(p,S,T)){
		int minflow = inf;
		for(auto&t : p) minflow=min(minflow,t->cf());
		for(auto&t : p) t->push(minflow);
		ret+=minflow;
        p.clear();
	}
	return ret;
}
int main()
{
	int i,j,s,num;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++){
    	cin>>s;
    	while(s--){
    		cin>>num;
    		addedge(i,n+num,1);
    	}
    }
    addedge(0,n+m+1,k);
    for(i=1;i<=n;i++){
    	addedge(0,i,1);
    	addedge(n+m+1,i,k);
    }
    for(i=n+1;i<=n+m;i++){
    	addedge(i,n+m+2,1);
    }
    cout<<maxflow(0,n+m+2);
    return 0;
}
