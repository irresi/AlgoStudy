#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m,s;
vector<vector<int>> ed;
vector<int> prevarr;
vector<int> chk;
vector<int> t2;
int dfs(int cur, int prev, int ini){
  if(chk[cur]!=ini and chk[cur]!=0){
    t2={prev,prevarr[cur]};
    return cur;
  }
  prevarr[cur]=prev;
  chk[cur]=ini;
  int ret=0;
  for(int &nxt : ed[cur]) if(chk[nxt]!=ini){
    ret=dfs(nxt,cur,ini);
    if(ret) return ret;
  }
  return ret;
}
void solve(){
  int i,j,u,v,ret=0;
  cin>>n>>m>>s;
  ed.resize(n+1);
  prevarr.assign(n+1,0);
  chk.assign(n+1,0);
  for(i=0;i<m;i++){
    cin>>u>>v;
    if(v==s) continue;
    ed[u].push_back(v);
  }
  prevarr[s]=s;
  chk[s]=s;
  for(int &s2 : ed[s]){
    ret=dfs(s2,s,s2);
    if(ret) break;
  }
  if(ret){
    cout<<"Possible\n";
    for(int &num : t2){
      vector<int> pr = {ret,num};
      while(prevarr[pr.back()]!=pr.back())
        pr.push_back(prevarr[pr.back()]);
      reverse(all(pr));
      cout<<pr.size()<<'\n';
      for(int &num : pr) cout<<num<<' ';
      cout<<'\n';
    }
  }
  else cout<<"Impossible\n";
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}