#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
char str[53];
void solve(){
    int i,j,cnt2=0;
    cin>>str;
    vector<int> cnt(256,0);
    n = strlen(str);
    for(i=0;i<n;i++){
      cnt[str[i]]++;
    }
    for(i='a';i<='z';i++){
      if(cnt[i]>=2) cnt2++;
    }
    if(cnt2>=2) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}