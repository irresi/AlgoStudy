#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,q;
void solve(){
    int i,num,idx,ans,mi,j,k,ans4[5],resid[5];
    cin>>n>>q;
    vector<int> v(n),v4[5];
    for(int &num : v) cin>>num;
    sort(all(v));
    for(i=1;i<=4;i++){
        v4[i] = v;
        sort(all(v4[i]));
        for(j=i;j>=1;j--){
            mi = 0;
            for(k=1;k<min(n,4ll);k++) 
                if(v4[i][k]<v4[i][mi]) mi = k;
            v4[i][mi]+=j;
        }
        sort(v4[i].begin(),v4[i].begin()+min(n,4ll));
    }
    for(i=3;i<=4;i++){
        resid[i]=0;
        for(j=0;j<n;j++) {
            resid[i]+=v4[i][j]-v4[i][0];
        }
    }
    int tominus,allplus,toplus;
    for(i=0;i<q;i++){
        cin>>k;
        if(k<=4){
            cout<<ans4[k]<<'\n';
            continue;
        }
        tominus = -(k-3)/2;
        allplus = tominus*2;
        toplus = k-allplus; // 3(1,2,3) or 4(1,2,3,4)
        tominus +=resid[toplus];
        cout<<allplus+v4[toplus][0]+tominus/n<<' ';
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // int tc; cin>>tc;
    // while(tc--){
    solve();
    // }
    return 0;
}