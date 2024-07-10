#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int inf=1e18;
int n,m;
void solve(){
  int i,j,l,ans=inf;
  cin>>n;
  vector<int> a(n),b(n),s(n);
  int toplus=0;
  for(i=0;i<n;i++) {
    cin>>a[i];
    s[i]+=a[i];
    toplus+=a[i]*a[i]*(n-1);
  }
  for(i=0;i<n;i++) {
    cin>>b[i];
    s[i]+=b[i];
    if(i) s[i]+=s[i-1];
    toplus+=b[i]*b[i]*(n-1);
  }
  vector<unordered_map<int, int>> d(n);
  d[0][a[0]]=0; d[0][b[0]]=0;
  int diff=10000;
  for(i=1;i<n;i++){
    for(auto &[idx,val] : d[i-1]){
      l=(s[i]-diff+1)/2;
      if(l<=idx+a[i] and idx+a[i]<=l+diff){
        if(!d[i][idx+a[i]]) d[i][idx+a[i]]=inf;
        d[i][idx+a[i]] = min(d[i][idx+a[i]],val + 2*a[i]*idx + 2*b[i]*(s[i-1]-idx));
      }
      swap(a[i],b[i]);
      if(l<=idx+a[i] and idx+a[i]<=l+diff){
        if(!d[i][idx+a[i]]) d[i][idx+a[i]]=inf;
        d[i][idx+a[i]] = min(d[i][idx+a[i]],val + 2*a[i]*idx + 2*b[i]*(s[i-1]-idx));
      }
    }
  }
  for(auto [idx, val] : d[n-1]) ans=min(ans,val);
  cout<<ans+toplus<<'\n';
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}