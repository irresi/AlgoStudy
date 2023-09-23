#include<bits/stdc++.h>
using namespace std;
#define int ll
#define all(x) (x).begin(),(x).end()
using ll = long long;
using pii = pair<int, int>;
int n,m;
string s, l, r, fcur;
void solve(){
    set<int> lib;
    int i,j; 
    cin>>s;
    n = s.size();
    cin>>m; 
    cin>>l>>r;
    int idx=0;
    for(char ch : s){
        if(idx==m) break;
        if(l[idx]<=ch and ch<=r[idx]) lib.insert(ch);
        
        if(lib.size()==r[idx]-l[idx]+1){
            lib.clear(); ++idx;
        }
    }
    if(idx==m) cout<<"NO\n";
    else cout<<"YES\n";
    return;
}
signed main(){
    // ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;

    while(tc--){
        solve();
    }
    return 0;
}