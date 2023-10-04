#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
#define NO {cout<<"NO\n"; return;}
#define YES {cout<<"YES\n"; return;}
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
void solve(){
  
  int i,j,color=1;
  cin>>n>>m;
  v.assign(n+1,0);
  chk.assign(n+1,0);
  for(i=1;i<=n;i++){
    cin>>v[i];
  }
  if(m==1){
    for(i=1;i<=n;i++) if(i!=v[i]) NO;
  }
  else{
    for(i=1;i<=n;i++)if(!chk[i]){
      if(!dfs(i,color,color)) NO;
    }
  }
  YES;
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}