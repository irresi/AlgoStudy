#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
void solve(){
  int i,j,ans=0,s,e;
  queue<int> q;
  cin>>n>>m;
  vector<int> a(n+1);
  int cur=m,fr;
  for(i=1;i<=n;i++){
    cin>>a[i];
    while(!q.empty() and cur+a[i]<0){
      fr=q.front(); q.pop();
      cur-=a[fr];
    }
    if(cur+a[i]>=0){
      q.push(i);
      cur+=a[i];
    }
    if(ans<q.size()){
      ans=q.size();
      s=q.front(); e=i;
    }
  }
  if(ans!=0) cout<<s<<' '<<e<<'\n';
  else cout<<"-1\n";
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}