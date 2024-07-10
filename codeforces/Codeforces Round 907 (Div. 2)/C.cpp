#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;

void solve(){
  int i,j,sum=0,ans=0,t;
  cin>>n;
  vector<int> v(n);
  for(int &num : v){
    cin>>num;
    sum+=num;
  }
  sort(all(v),greater<>());
  for(int &num : v){
    if(sum>=2){
      t=min(sum/2,num);
      sum-=t*2;
      ans+=t+1;
    }
  }
  ans+=sum;
  cout<<ans<<'\n';
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}