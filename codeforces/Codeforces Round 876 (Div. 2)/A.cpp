#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int inf=1e9;
int n,m;
void solve(){
    int i,j,k,idx,flag=0,from;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<int>> d(n+1,vector<int>(n+1,0));
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<n;i++){
        if(a[i-1]<a[i]) d[0][i]=i;
        else break;
    }
    int ans=d[0][n-1];
    for(k=1;k<=n;k++){
        d[k][1]=d[k-1][1];
        for(i=2;i<=n;i++){
            d[k][i]=d[k-1][i];
            if(a[i-1]+1==a[i])
                d[k][i]=max(d[k][i],d[k][i-1]+1);
            for(j=i-1;j>=1;j--){
                if(a[j]>a[i]) break;
                d[k][i]=max(d[k][i],d[k-1][j-1]+i-j);
            }
            //j+1~i까지는 증가한다는 게 보장됨.
            from = j+1;
            --j;
            for(;j>=1;j--){
                idx = lower_bound(from+a.begin(), i+1+a.begin(),a[j]) - a.begin(); //from~i+1
                if(idx>i) continue;
                d[k][i]=max(d[k][i],d[k-1][j]+i-idx+1);
            }
        }
        cout<<n-d[k][n]<<" ";
    }
    cout<<"\n";
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