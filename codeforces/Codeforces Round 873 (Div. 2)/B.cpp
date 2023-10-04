#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int mod = 1e9+7;
int n,m;
struct BIT{ //range query, point modify
  vector<int> t;
  BIT(int n){
    t.assign(n+1,0);
    for(int i=1;i<=n;i++) 
      modify(i,1);
  }
  void modify(int x,int val){
    for(;x<=n;x+=x&(-x)) 
      t[x]+=val;
  }
  int query(int x){
    int ret=0;
    for(;x>0;x-=x&(-x)) ret+=t[x];
    return ret;
  }
  int query(int s, int e){
    return query(e)-query(s-1);
  }
};
void solve(){
  int i,j,num,ret,ans=0;
  cin>>n;
  vector<pii> v(n);
  BIT T(n);
  for(i=0;i<n;i++){
    cin>>num;
    v.emplace_back(num,i);
  }
  sort(all(v), greater<pii>());
  for(auto &[num, idx] : v){
    ret = T.query(idx+1,n);
    ans+=ret*(ret+1)/2;
    T.modify(idx,-1);
  }
  cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}