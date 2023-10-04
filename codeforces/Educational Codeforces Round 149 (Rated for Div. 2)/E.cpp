#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int MN = 1e6; //modify!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const int mod = 998244353;
const int inf= 1e9;
int n,m,arr[MN],fac[MN];
void solve(){
    cin>>n;
    int i,j,k,cur=(1<<n),cnt;
    for(i=0;i<(1<<n);i++){
        cin>>arr[i];
    }
    int unknown,ans=1,flag;
    for(i=2;i<=(1<<n);i<<=1){
        cnt=unknown=flag=0;
        for(j=0;j<(1<<n);j++){
            if(cur/2+1<=arr[j] and arr[j]<=cur) {
                cnt++;
                flag++;
            }
            else if(arr[j]==-1) {
                unknown++;
            }
            if(j%i==i-1){
                if(!flag){
                    ans=ans*unknown%mod;
                    for(k=j;arr[k]!=-1 and k>j-i;k--);
                    if(k==j-i){
                        cout<<0;
                        return;
                    }
                    arr[k]=inf;
                }
                else if(flag>1){ //이게 빠졌었음.
                    cout<<0<<'\n';
                    return;
                }
                unknown=0;
                flag=0;
            }
        }
        ans=ans*fac[cur/2-cnt]%mod;
        cur/=2;
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    fac[0]=1;
    for(int i=1;i<MN;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    solve();
    return 0;
}