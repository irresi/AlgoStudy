#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int mod = 998244353;
int n, m,d[300003][2],cnt[300003][2];
void solve() {
  int i, j, k, ans = 0;
  cin >> n;
  vector<int> v(n);
  for(int &num : v) cin>>num;
  for(i=0;i<=30;i++){
    int mask = (1<<i);
    d[0][0]=d[0][1]=0;
    d[0][((v[0]&mask)>0)]=1;
    cnt[0][0]=d[0][0]; cnt[0][1]=d[0][1];
    ans+=d[0][1]*mask;
    ans%=mod;
    for(j=1;j<n;j++){
      if(v[j]&mask){
        d[j][0]=(d[j-1][1]+cnt[j-1][1])%mod;
        d[j][1]=(d[j-1][0]+cnt[j-1][0]+1)%mod;
        cnt[j][0]=cnt[j-1][1];
        cnt[j][1]=cnt[j-1][0]+1;
      }
      else{
        d[j][0]=(d[j-1][0]+cnt[j-1][0]+1)%mod;
        d[j][1]=(d[j-1][1]+cnt[j-1][1])%mod;
        cnt[j][0]=cnt[j-1][0]+1;
        cnt[j][1]=cnt[j-1][1];
      }
      ans+=d[j][1]*mask;
      ans%=mod;
    }
  }
  cout << ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // int tc;
  // cin >> tc;
  // while (tc--)
  solve();

  return 0;
}