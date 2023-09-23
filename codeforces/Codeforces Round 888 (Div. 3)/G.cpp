#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
using i4 = tuple<int, int, int, int>;
int n,m,q;
vector<int> gr;
int fnd(int num){
    return num==gr[num]?gr[num]:gr[num]=fnd(gr[num]);
}
void uni(int a, int b){
    a = fnd(a); b = fnd(b);
    gr[a]=b;
}
void solve(){
    gr.clear();
    int i,j,a,b,c;

    cin>>n>>m;
    vector<int> h(n),ans;
    vector<i4> edges;
    gr.resize(n);
    iota(all(gr),0);
    for(int &num : h) cin>>num;
    for(i=0;i<m;i++){
        cin>>a>>b;
        --a; --b;
        edges.emplace_back(max(h[a],h[b]),-1,a,b);
    }
    cin>>q;
    ans.assign(q,0);
    for(i=0;i<q;i++){
        cin>>a>>b>>c;
        --a; --b;
        edges.emplace_back(h[a]+c,i,a,b);
    }
    sort(all(edges));
    for(auto &[c, num, a, b] : edges){
        if(num<0) uni(a,b);
        else{
            ans[num]=(fnd(a)==fnd(b));
        }
    }
    for(int &pr : ans) cout<<(pr?"YES\n":"NO\n");
    cout<<"\n";
}
signed main(){
    // ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}