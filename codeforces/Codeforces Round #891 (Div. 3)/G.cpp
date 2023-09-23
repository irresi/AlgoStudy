#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
using iii = tuple<ll,ll,ll>;
const int mod = 998244353;
vector<int> g,cnt;
vector<iii> edges;
int n,S, pow22[64]={2};
int fnd(int num){
    return num==g[num]?num: g[num] = fnd(g[num]);
}
int powmod(int a, int x){
    int cur=a,ans=1;
    while(x){
        if(x%2) ans=ans*cur%mod;
        cur=cur*cur%mod;
        x/=2;
    }
    return ans;
}
void uni(int u, int v){
    u = fnd(u), v = fnd(v);
    g[u]=v;
    cnt[v]+=cnt[u];
    cnt[u]=0;
}
void solve(){
    int i,j,ans=1,addcnt;
    cin>>n>>S;
    g.resize(n); cnt.assign(n,1); edges.resize(n-1);
    iota(all(g),0);
    for(i=0;i<n-1;i++){
        auto &[w, u, v] = edges[i];
        cin>>u>>v>>w;
        u--; v--;
    }
    sort(all(edges));

    for(auto &[w, u, v]: edges){
        if(fnd(u)==fnd(v)) continue;
        addcnt = cnt[fnd(u)]*cnt[fnd(v)]-1;
        uni(u,v);
        ans*=powmod(S-w+1, addcnt);
        ans%=mod;
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