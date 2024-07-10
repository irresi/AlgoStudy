#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
vector<vector<pii>> v;
vector<int> p,ed;
vector<vector<int>> euler;
//val, idx //현재보다 작은 것 pop
priority_queue<pii, vector<pii>, greater<pii> > pq; 
struct Fenwick{ //range update, point query
  vector<int> v;
  int sz;
  Fenwick(int n){
    v.assign(n+1,0);
    sz=n;
  }
  void update(int x, int val){
    for(;x;x-=x&(-x))
      v[x]+=val;
  }
  void update(int s, int e, int val){
    update(e,val);
    update(s-1,-val);
  }
  int query(int x){
    int ret=0;
    for(;x<=sz;x+=x&(-x)){
      ret+=v[x];
    }
    return ret;
  }
};
void dfs(int cur, int &num){
  euler[cur].push_back(++num);
  for(int &nxt : ed[cur]){
    dfs(nxt,num);
  }
  euler[cur].push_back(num);
}
void solve(){
  int i,j,t,val,x,cnt=1;
  cin>>n;
  euler.assign(n+1,{});
  v.assign(n+1,{});
  p.assign(n+1,0);
  ed.assign(n+1,0);
  euler.assign(n+1,0);
  Fenwick t(n+1);
  dfs(1,1);
  for(i=1;i<=n;i++){
    cin>>t;
    if(t==1){
      cin>>x;
      p[++cnt]=x;
      ed[x]=cnt;
      t.update(euler[x][0],euler[x][0],0);
    }
    else{
      cin>>val>>x;
      v[x].emplace_back(cnt,val);
      t.update(euler[x][0],euler[x][1],val);
    }
  }
  for(i=1;i<=n;i++){
    cout<<t.query(euler[i][0])<<' ';
  }
  cout<<"\n";
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}