#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m,ans;
int a[250003],mnpref[250003],mxpref[250003],mnsuf[250003],mxsuf[250003];
void goleft(int x){ //t=0 : use pref, t=1 : use suf
  if(x==1) return;
  int idx = mnpref[x]; ans++;
  if(idx==1) return;
  ans++;
  goleft(mxpref[idx]);
}
void goright(int x){ //t=0 : use pref, t=1 : use suf
  if(x==n) return;
  int idx = mnsuf[x]; ans++;
  if(idx==n) return;
  ans++;
  goright(mxsuf[idx]);
}
void solve(){
  ans=0;
  int i,j;
  cin>>n;
  for(i=1;i<=n;i++) {
    cin>>a[i];
  }
  if(n==1){
    cout<<"0\n";
    return;
  }
  mnpref[1]=mxpref[1]=1;
  for(i=2;i<=n;i++){
    if(a[mnpref[i-1]]>a[i]) mnpref[i]=i;
    else mnpref[i]=mnpref[i-1];
    if(a[mxpref[i-1]]<a[i]) mxpref[i]=i;
    else mxpref[i]=mxpref[i-1];
  }
  mnsuf[n]=mxsuf[n]=n;
  // if(mnpref[n]+mxpref[n]==n+1){
  //   cout<<"1\n";
  //   return;
  // }
  for(i=n-1;i>=1;i--){
    if(a[mnsuf[i+1]]>a[i]) mnsuf[i]=i;
    else mnsuf[i]=mnsuf[i+1];
    if(a[mxsuf[i+1]]<a[i]) mxsuf[i]=i;
    else mxsuf[i]=mxsuf[i+1];
  }
  goleft(mxpref[n]);goright(mxpref[n]);
  cout<<ans<<'\n';
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}