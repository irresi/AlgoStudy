#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<int, int>;
const int INF=1e18;
int n,m;
void solve(){
    int i,j,ans=0;
    cin>>n;
    vector<pii> v(n);
    for(i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(all(v),[&](pii L, pii R){
        return L.second<R.second;
    });
    int lim = -1, fe = INF;
    for(auto &[s,e] : v){
        if(s<=lim) 
            continue;
        if(s>fe)
            fe=e;
        else if(fe!=INF){
            lim = e;
            fe = INF;
            ans+=2;
        }
        else fe=e;
    }
    cout<<n-ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}