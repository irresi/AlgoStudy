#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,c;

void solve(){
  int i,j,ans=0,k;
  cin>>n>>c;
  vector<int> v(n),must;
  vector<pii> ava;
  unordered_set<int> lib;
  for(i=0;i<n;i++){
    cin>>v[i];
  }
  sort(all(v));
  for(i=0;i<n;i++){ //n
    lib.insert(v[i]);
    for(j=0;v[j]*v[j]<=v[i] and j<=i;j++){
      if(!lib.count(v[i]/v[j]))
        ans=-1;
    }
    for(k=j,--j;j>=0;--j){
      while(k<=i){
        if(v[i]/(v[j]+1)+1<=v[k] and v[k]<=v[i]/v[j]) ++k;
        else break;
      }
    }
    if(k<=i) ans=-1;
  }
  if(ans<0) cout<<"NO\n";
  else cout<<"YES\n";
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}