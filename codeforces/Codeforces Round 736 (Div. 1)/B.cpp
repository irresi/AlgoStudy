#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int MN=200003;
int n;
int g[20][MN];
void solve(){
  int i,j,e,ans=0,cur,curg;
  cin>>n;
  vector<int> v(n);
  for(int &num : v) cin>>num;
  if(n==1){
    cout<<"1\n"; return;
  }
  for(i=1;i<n;i++){
    g[0][i]=abs(v[i-1]-v[i]); //1~n-1
  }
  for(i=1;i<20;i++){
    e=n-(1<<i);
    for(j=1;j<=e;j++){
      g[i][j]=__gcd(g[i-1][j],g[i-1][j+(1<<(i-1))]);
    }
    for(;j<n;j++) g[i][j]=0; //for unreseted values
  }

  for(i=1;i<n;i++){
    cur=i; curg=0;
    for(j=19;j>=0 and cur<n;j--){
      if(g[j][cur]>1){
        if(!curg){
          curg=g[j][cur];
        }
        else if(__gcd(curg,g[j][cur])>1){
          curg=__gcd(curg,g[j][cur]);
        }
        else continue;
        cur+=(1<<j);
      }
    }
    ans=max(ans,cur-i+1);
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