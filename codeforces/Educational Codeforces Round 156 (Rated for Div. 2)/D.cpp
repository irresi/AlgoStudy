#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int mod = 998244353;
int n,m;
char str[300005];
inline int mult(int a, int b){
  return a*b%mod;
}
int rev(int num, int p = mod - 2){
  int cur=1,powed=num;
  while(p){
    if(p&1) cur=mult(cur,powed);
    powed=mult(powed,powed);
    p>>=1;
  }
  return cur;
}
void solve(){
  int i,j,idx,zeroflag=0,ans=1;
  cin>>n>>m;
  cin>>str;
  for(i=1;i<n-1;i++){
    if(str[i]=='?') ans=mult(ans,i);
  }
  if(str[0]=='?') zeroflag=1;
  cout<<(zeroflag?0:ans)<<'\n';
  char c;
  for(i=1;i<=m;i++){
    cin>>idx>>c;
    idx--;
    if(idx==0) {
      zeroflag=(c=='?');
    }
    else {
      if(str[idx]=='?'){
        ans=mult(ans,rev(idx));
      }
      if(c=='?') ans=mult(ans,idx);
    }
    str[idx]=c;
    cout<<(zeroflag?0:ans)<<'\n';
  }

}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}