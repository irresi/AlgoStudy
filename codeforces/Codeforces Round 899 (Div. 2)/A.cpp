#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
void solve(){
    int i,j,k,cur=1,ans=0;
    cin>>n;
    vector<int> sz(n);
    vector<vector<int>> v,rev(51);
    v.resize(n);
    set<int> chk;
    for(i=0;i<n;i++){
        cin>>sz[i];
        v[i].resize(sz[i]);
        for(j=0;j<sz[i];j++){
            cin>>v[i][j];
            rev[v[i][j]].push_back(i);
            chk.insert(v[i][j]);
        }
    }
    int mx = chk.size();
    chk.clear();
    for(i=1;i<=50;i++){
        if(rev[i].size()){
            vector<int> nrev;
            set<int> chk;
            int flag=0;
            for(j=0;j<n;j++){
                flag=0;
                for(int &num : rev[i]){
                    if(num==j) {   
                        flag=1; 
                        break;
                    }
                }
                if(!flag) nrev.push_back(j);
            }
            for(int &idx : nrev){
                for(int &num : v[idx]) chk.insert(num);
            }
            if(chk.size()==mx) continue;
            ans = max(ans,(ll)chk.size());
        }
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