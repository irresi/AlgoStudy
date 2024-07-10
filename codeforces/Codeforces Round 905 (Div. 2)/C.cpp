#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;

void solve(){
  int i,j,ans=0;
  cin>>n;
  map<int, int> lib;
  vector<int> v(n+1),lst(n+2);
  for(i=1;i<=n;i++) cin>>v[i];
  for(i=n;i>=1;i--){
    lst[i]=lst[i+1];
    if(lib[v[i]]==0) lst[i]++;
    lib[v[i]]++;
  }
  lib.clear();
  for(i=1;i<=n;i++){
    if(lib[v[i]]==0) ans+=lst[i];
    ++lib[v[i]]; 
  }
  cout<<ans<<'\n';
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}