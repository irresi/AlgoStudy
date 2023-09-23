#include<bits/stdc++.h>
using namespace std;
int n,m,k,x;
void solve(){
    int i,j;
    cin>>n>>k>>x;
    if(x!=1){
        cout<<"YES\n";
        cout<<n<<'\n';
        for(i=1;i<=n;i++) cout<<"1 ";
        cout<<'\n';
    }
    else{ //x가 1이 아님.
        if(k==1) cout<<"NO\n";
        else if(k==2){ //x가 2
            if(n%2==0){
                cout<<"YES\n";
                cout<<n/2<<"\n";
                for(i=1;i<=n/2;i++) cout<<"2 ";
                cout<<'\n';
            }
            else cout<<"NO\n";
        }
        else{
            if(n%2==0){
                cout<<"YES\n";
                cout<<n/2<<"\n";
                for(i=1;i<=n/2;i++) cout<<"2 ";
                cout<<'\n';
            }
            else{
                cout<<"YES\n";
                cout<<n/2<<"\n";
                cout<<"3 ";
                for(i=1;i<=n/2-1;i++) cout<<"2 ";
                cout<<'\n';

            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}