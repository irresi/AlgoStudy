#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
void f(int sz, int cur){
  if(sz==cur){
    for(int i=0;i<sz;i++) cout<<'#';
    return;
  }
  if(cur==0){
    for(int i=0;i<sz;i++) cout<<'.';
    return;
  }
  if(cur*2<=sz) { //sz의 1/2보다 작다.
    f(sz/2,cur); f(sz/2,0); return;
  }
  else if(sz*3>=cur*4){ //sz의 3/4보다 작다.
    int b=sz/4; f(sz/2,cur-b); f(sz/2,b);
  }
  else{
    f(sz/2,sz/2); f(sz/2,cur-sz/2);
  }
}
void solve(){
  int i,j;
  cin>>n;
  int nn=1;
  while(nn<n) nn<<=1;
  f(nn,n);
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}