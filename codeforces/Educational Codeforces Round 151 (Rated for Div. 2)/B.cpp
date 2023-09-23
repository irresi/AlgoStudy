#include<bits/stdc++.h>
using namespace std;
#define int ll
using ll = long long;
using pii = pair<int, int>;
int n,m;
void solve(){
    int ans=1;
    int i,j,xa,ya,xb,yb,xc,yc;
    cin>>xa>>ya;
    cin>>xb>>yb;
    cin>>xc>>yc;
    xb-=xa; xc-=xa;
    yb-=ya; yc-=ya;
    if(xb*xc>0) ans+=min(abs(xb),abs(xc));
    if(yb*yc>0) ans+=min(abs(yb),abs(yc));
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