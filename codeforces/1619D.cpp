#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int inf=1e9;
int n,m;
vector<vector<int>> p;
bool pos(int num){
  for(int i=1;i<=n;i++){
    int cnt=0;
    for(int j=1;j<=m;j++){
      if(p[i][j]>=num) cnt++;
    }
    if(cnt>=2) return 1;
  }
  return 0;
}
void solve(){
  int i,j,mxsum=0,ans=inf;
  cin>>n>>m; //shop, friend;
  vector<pii> flike[m+1]; //friend, {val, shop}
  vector<int> mxFriendIdx[m+1]; //각 shop마다 max인 friend idx
  p.assign(n+1,vector<int>(m+1));
  for(i=1;i<=n;i++){ //shop
    for(j=1;j<=m;j++){ //friend
      cin>>p[i][j];
    }
  }
  int mx,mn=inf;
  for(j=1;j<=m;j++){ //friend
    mx=0;
    for(i=1;i<=n;i++){ //shop
      mx=max(mx,p[i][j]);
    }
    mn=min(mx,mn);
  }
  int s=1,e=mn,mid;
  while(s<e){
    mid=(s+e+1)/2;
    if(pos(mid)) s=mid;
    else e=mid-1;
  }
  cout<<s<<'\n';
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}