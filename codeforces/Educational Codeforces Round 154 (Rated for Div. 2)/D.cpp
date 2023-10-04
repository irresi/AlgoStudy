#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n;
int get_state(int a, int b){
  return (b-a)?(b-a)/abs(b-a):0;
}
void solve(){
  cin>>n;
  int i,j,state,tot=n-1,inc=0;
  vector<int> v(n);
  for(int &num : v) cin>>num;
  for(i=1;i<n;i++){
    if(v[i-1]<v[i]) inc++;
  }
  int ans=tot-inc;
  tot++;
  for(i=0;i<n;i++){
    if(i!=0){ //relation for front element
      if(get_state(v[i-1],v[i])==1) inc--;
      if(get_state(v[i-1],-v[i])==1) inc++;
    }
    if(i!=n-1){//relation for back element
      if(get_state(v[i],v[i+1])==1) inc--;
      if(get_state(-v[i],v[i+1])==1) inc++;
    }
    v[i]=-v[i];
    ans=min(ans,tot-inc);
  }
  cout<<ans<<'\n';
  return;
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}