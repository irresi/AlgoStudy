#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int _MX=13; ///////////////////////////////////////////////////////////////////////
int n,m,a[_MX],imp[_MX],son[_MX],sz[_MX],fa[_MX];
vector<vector<int>> edges;
void dfs(int cur, int prev){
  int &mxidx=son[cur];
  sz[cur]=1;
  imp[cur]=a[cur];
  for(int &nxt : edges[cur])if(prev!=nxt){
    dfs(nxt,cur);
    if(sz[nxt]>sz[mxidx]) mxidx=nxt;
    sz[cur]+=sz[nxt];
    imp[cur]+=imp[nxt];
    fa[nxt]=cur;
  }
  return;
}
void solve(){
  int i,j,u,v,q,x;
  cin>>n>>m;
  edges.assign(n+1,vector<int>());
  for(i=1;i<=n;i++) cin>>a[i];
  for(i=1;i<n;i++){
    cin>>u>>v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  //son ascending index;
  for(i=1;i<=n;i++) 
    sort(all(edges[i]));
  dfs(1,0);
  for(i=1;i<=m;i++){
    cin>>q>>x;
    if(q==1){
      cout<<imp[x];
    }
    else{ //son이 크기가 같은데 인덱스가 달라서 바뀔 수 있다.
      int sonx=son[x],fax=fa[x];
      if(sonx==0) continue;
      sz[sonx]=sz[x];
      sz[x]=1;

      imp[sonx]=imp[x];
      imp[x]=a[x];

      son[fax]=sonx;
      son[x]=0;
      if(son[sonx]==0) son[sonx]=x;

      fa[sonx]=fax;
      fa[x]=sonx;
    }
  }
  return;
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}