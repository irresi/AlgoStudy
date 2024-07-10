#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
vector<vector<int>> ed,red;
vector<int> d,a,chk,vis;
const int inf=2e18;
int n,m,k;
void dfs(int cur, int mx){
  chk[cur]=1;
  for(int &nxt : ed[cur])if(!chk[nxt] and a[nxt]<=mx){
    dfs(nxt,mx);
  }
  vis.push_back(cur);
}
bool pos(int num){
  int ans=0;
  chk.assign(n+1,0);
  d.assign(n+1,0);
  //topological sort를 한 다음에 전 순서에 체크된 것 방문 : 무한 -> 항상 가능
  for(int i=1;i<=n;i++)if(!chk[i] and d[i]<=num){
    dfs(i,num);
  }
  reverse(all(vis));
  for(int &num : vis){
    for(int &prev : red[num]){
      d[num]=max(d[prev]+1,d[num]);
    }
    for(int &nxt : ed[num]){
      if(d[nxt]) return true;
    }
    ans=max(ans,d[num]);
  }
  return ans>=k;
}
void solve(){
  int i,j,u,v;
  cin>>n>>m>>k;
  --k;
  a.assign(n+1,0);
  ed.assign(n+1,vector<int>());
  red.assign(n+1,vector<int>());
  for(i=1;i<=n;i++) cin>>a[i];
  for(i=1;i<=m;i++){
    cin>>u>>v;
    ed[u].push_back(v);
    red[v].push_back(u);
  }
  int s=1,e=10,m;
  while(s<e){
    m=(s+e)/2;
    if(pos(m)) e=m;
    else s=m+1;
  }
  if(s>1e9) cout<<"-1";
  else cout<<s;
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}