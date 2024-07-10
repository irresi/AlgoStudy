#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;

void solve(){
  int i,j,x,mn=31,mask;
  cin>>n>>m;
  vector<int> v(n);
  for(int &num : v) cin>>num;
  for(i=1;i<=m;i++){
    cin>>x;
    if(x<mn){
      mn=x;
      mask=(1<<x)-1;
      for(int &num : v){
        if(num&mask) continue;
        num+=1<<(x-1);
      }
    }
  }
  for(int &num : v) cout<<num<<' ';
  cout<<"\n";
  return;
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}