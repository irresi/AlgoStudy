#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m,q;
char str[1003][1003];

void solve(){
  int i,j,r,c,ans=0;
  cin>>n>>m>>q;
  set<int> lib;
  for(i=0;i<n;i++){
    cin>>str[i];
    for(j=0;j<m;j++){
      if(str[i][j]=='*') lib.insert(j*n+i);
    }
  }
  set<int>::iterator si = lib.begin();
  ans=lib.size();
  while(si!=lib.end() and *si<lib.size()){
    --ans;
    ++si;
  }
  for(i=0;i<q;i++){
    cin>>r>>c;
    if(lib.count(r*n+c)) lib.erase
  }
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}