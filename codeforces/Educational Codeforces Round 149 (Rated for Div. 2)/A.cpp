#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
void solve(){
    int i,j;
    cin>>n>>m;
    if(n%m!=0){
        cout<<"1\n";
        cout<<n<<"\n";
        return;
    }
    for(i=1;i<=100;i++){
        for(j=1;j<=100;j++){
            if(i+j==n and i%m!=0 and j%m!=0){
                cout<<"2\n";
                cout<<i<<' '<<j<<"\n";
                return;
            }
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}