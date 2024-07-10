#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
#define X first
#define Y second
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
pii A[3],cur,nxt;
vector<tuple<int, int, int, int>> pr;
void solve(){
  int i,j,x,y,a,b;
  for(i=0;i<3;i++){
    cin>>x>>y;
    A[i]={x,y};
  }
  sort(A,A+3);
  if(A[1].second<=A[0].second and A[0].second<=A[2].second or A[2].second<=A[0].second and A[0].second<=A[1].second) {
    m=0; a=1,b=2;
  }
  else if(A[0].second<=A[1].second and A[1].second<=A[2].second or A[2].second<=A[1].second and A[1].second<=A[0].second) {
    m=1; a=0,b=2;
  }
  else m=2, a=0, b=1;
  if(A[0].first!=A[2].first) pr.emplace_back(A[0].first,A[m].second,A[2].first,A[m].second);
  for(i=0;i<3;i++){
    if(i!=m){
      if(A[i].second!=A[m].second) pr.emplace_back(A[i].first,A[i].second,A[i].first,A[m].second);
    }
  }
  cout<<pr.size()<<"\n";
  for(auto &[a,b,c,d] : pr)cout<<a<<' '<<b<<' '<<c<<' '<<d<<"\n";
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}