#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m,x,y,a[200003],ylv;
vector<vector<int>> ed;
vector<int> chk;
int dfs(int cur, int prev, int lv){

  int ret=0;
  if(cur==y) ylv=lv;
  for(int &nxt : ed[cur])if(prev!=nxt){
    ret+=dfs(nxt,cur,lv+1);
  }
  if(cur==y || chk[cur]==1 || ret>0) ret+=2;
  return ret;
}
void solve(){
  int i,j,u,v;
  cin>>n>>m;
  ed.assign(n+1,vector<int>());
  chk.assign(n+1,0);
  cin>>x>>y;
  for(i=1;i<=m;i++) {
    cin>>a[i];
    chk[a[i]]=1;
  }
  for(i=1;i<n;i++){
    cin>>u>>v;
    ed[u].push_back(v);
    ed[v].push_back(u);
  }
  cout<<dfs(x,x,0)-2-ylv<<'\n';
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}