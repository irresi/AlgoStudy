#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
int p[100003][20],d[100003];
ll rc[100003];
vector<pii> e[100003];
void tmake(int cur, int prev, int lv, ll curcost){
	d[cur]=lv;
	rc[cur]=curcost;
	p[cur][0]=prev;
	for(auto [nxt,nxtcost] : e[cur])if(nxt!=prev){
		tmake(nxt,cur,lv+1,curcost+nxtcost);
	}
}
int LCA(int u, int w){
	if(d[u]>d[w]) swap(u,w);
	for(int i=19;i>=0;i--) if(d[w]-(1<<i)>=d[u]) w=p[w][i];
	if(u==w) return u;
	for(int i=19;i>=0;i--) if(p[u][i]!=p[w][i]) u=p[u][i],w=p[w][i];
	return p[u][0];
}
int main()
{
 	int i,j,a,b,c,u,v,w,k;
 	scanf("%d",&n);
 	for(i=1;i<n;i++){
 		scanf("%d %d %d",&a,&b,&c);
 		e[a].push_back({b,c});
 		e[b].push_back({a,c});
 	}
 	tmake(1,0,0,0);
 	for(i=1;i<=19;i++){
 		for(j=1;j<=n;j++){
 			p[j][i]=p[p[j][i-1]][i-1];
 		}
 	}
 	scanf("%d",&m);
 	for(i=1;i<=m;i++){
 		scanf("%d",&a);
 		if(a==1){
 			scanf("%d %d",&u,&v);
 			w=LCA(u,v);
 			printf("%lld\n",rc[u]-rc[w]+rc[v]-rc[w]);
 		}
 		else{
 			scanf("%d %d %d",&u,&v,&k);
 			w=LCA(u,v);
 			k--;
 			if(d[u]-d[w]>k){
 				for(j=0;j<=19;j++) if(k&(1<<j)) u=p[u][j];
 				printf("%d\n",u);
 			}
 			else{
 				k=d[u]-d[w]+d[v]-d[w]-k;
 				for(j=0;j<=19;j++) if(k&(1<<j)) v=p[v][j];
 				printf("%d\n",v);
 			}
 		}
 	}
    return 0;
}
