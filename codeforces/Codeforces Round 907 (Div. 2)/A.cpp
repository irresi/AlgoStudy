#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;

void solve(){
  int i,j,num,prev=-1e9,flag=1;
  set<int> lib;
  cin>>n;
  for(i=1;i<n;i<<=1) lib.insert(i);
  for(i=1;i<=n;i++){
    cin>>num;
    if(prev>num and !lib.count(i-1)){
      flag=0;
    }
    prev=num;
  }
  if(flag) cout<<"YES\n";
  else cout<<"NO\n";
  return;
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}