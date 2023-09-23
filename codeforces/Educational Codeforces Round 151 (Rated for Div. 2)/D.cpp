#include<bits/stdc++.h>
using namespace std;
#define int ll
#define all(x) (x).begin(),(x).end()
using ll = long long;
using pii = pair<int, int>;
int n,m;
void solve(){
    int i,j;
    cin>>n;
    vector<int> v(n);
    int acc=0, curhigh=0, curlow=0, ans=0, mdd=0;
    for(int &num : v) {
        cin>>num;
        acc+=num;
        if(acc>curhigh){
            if(curhigh-curlow>mdd){
                mdd=curhigh-curlow;
                ans=curhigh;
            }
            curhigh=curlow=acc;
        }
        if(acc<curlow) curlow=acc;
    }
    if(curhigh-curlow>mdd){
        mdd=curhigh-curlow;
        ans=curhigh;
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