#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
priority_queue<pii, vector<pii>, greater<pii> > sonpq[100003]; //minheap
vector<int> fa,imp,sz,a;
vector<vector<int>> edges;
void dfs(int cur, int prev){
  imp[cur] = a[cur]; sz[cur]=1;
  for(int &nxt : edges[cur])if(nxt!=prev){
    dfs(nxt,cur);
    fa[nxt] = cur;
    imp[cur] += imp[nxt];
    sz[cur] += sz[nxt];
    sonpq[cur].push({-sz[nxt],nxt});
  }
}
void solve(){
  int i,j,u,v,q,x;
  cin>>n>>m;
  a.resize(n+1); fa.resize(n+1); imp.resize(n+1); sz.resize(n+1);
  edges.resize(n+1);
  for(i=1;i<=n;i++) cin>>a[i];
  for(i=1;i<n;i++){
    cin>>u>>v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1,0);
  int fax,sonx;
  for(i=1;i<=m;i++){
    cin>>q>>x;
    if(q==1){
      cout<<imp[x]<<"\n";
    }
    else{
      if(sonpq[x].empty()) continue;
      fax=fa[x];
      auto [sonsz, sonx] = sonpq[x].top(); sonpq[x].pop();
      fa[sonx]=fax;
      fa[x]=sonx;

      imp[x]-=imp[sonx]; //2(x) : 5, 3(sonx) : 2 / 2 : 3, 3 : 5
      imp[sonx]+=imp[x];

      sz[x]-=sz[sonx]; //2(x) : 5, 3(sonx) : 2 / 2 : 3, 3 : 5
      sz[sonx]+=sz[x];

      //sonpq[sonx]에 x넣기
      sonpq[sonx].push({-sz[x],x});
      
      //부모에서 지우는 것 안 함.
    }
  }
}
signed main(){ 
  ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}