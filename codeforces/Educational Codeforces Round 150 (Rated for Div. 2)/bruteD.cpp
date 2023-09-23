#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<int, int>;
const int INF=1e18;
int n,m;
bool inter(pii &A, pii &B){
    return A.first<=B.second and A.second<=B.first;
}
void solve(){
    int i,j,k,ans=0;
    cin>>n;
    vector<pii> v(n);
    vector<int> chk(n);
    for(i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(i=0;i<(1<<n);i++){
        for(j=0;j<n;j++)if(i&(1<<j)){
            for(k=j+1;k<n;k++)if(i&(1<<k)){
                if(inter(v[j],v[k])) chk[j]++,chk[k]++;
            }
        }
        int cnt=0;
        for(j=0;j<n;j++)if(i&(1<<j)){
            if(chk[j]>=2) break;
            cnt+=chk[j];
        }
        ans=min(ans,n-2*cnt);
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}