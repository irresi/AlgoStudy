#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,k;
int arr[100003];
void solve(){
  cin>>n>>k;
  int i,j,div=0,ans=k,even=0;
  for(i=1;i<=n;i++){
    cin>>arr[i];
    if(arr[i]%k==0) div=1;
    ans=min(ans,k-arr[i]%k);
    even+=(arr[i]%2==0);
  }
  if(div){
    cout<<"0\n";
    return;
  }
  if(k==4){
    ans=min(ans,max(0LL,2-even));
  }
  cout<<ans<<"\n";
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}