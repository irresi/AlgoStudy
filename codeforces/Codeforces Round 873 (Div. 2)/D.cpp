#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
void solve(){
    cin>>n;
    int i,j,k,x,y,ans=(n+1)*n*n/2-n*(n+1)*(2*n+1)/6;
    vector<int> v(n);
    for(int &num : v) cin>>num;
    for(i=0;i<n;i++){
        for(k=i-1;k>=0;k--){
            if(v[k]<v[i]) break;
        }
        if(k<0) continue;
        for(x=k-1;x>=0;x--){
            if(v[x]>v[i]) break;
        }
        //x는 -1 가능
        for(y=i+1;y<n;y++){
            if(v[y]<v[i]) break;
        }
        //y도 n가능
        ans-=(k-x)*(y-i);
        // cout<<(k-x)*(y-i)<<'\n';
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