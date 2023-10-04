#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
#define input(a,n)      for(int i=0;i<n;i++)cin>>a[i]
typedef vector<int>        vi;

vi a(5000);
vector<vi> dp(5000,vi(5000,0));

void solve(){
    int i,j,k,n;
    cin>>n;
    input(a,n);
    ll ans = 0;
    for(i=n-1;i>=0;i--){
            for(j=i+1;j<n;j++){
                    if(a[i]>a[j]) dp[i][j]=j-i;
                    else if(j==i+1) dp[i][j]=(a[i]>a[j]);
                    else dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                    ans+=dp[i][j];
            }
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    // linear_sieve();
    ll t = 1; 
    cin>>t;
    while(t--){
           solve(); 
    }

    return 0;
}

