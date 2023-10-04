#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n;

void solve(){
  int i,j;
  cin>>n;
  vector<int> a(n);
  vector<pii> v(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    v.emplace_back(a[i],i);
  }
  sort(all(v),greater());
  cout<<v[0]<<'\n';

}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}