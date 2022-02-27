#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
ll n,x;
ll arr[5003],mz[5003];

int main()
{
	int tc,i,j;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n>>x;
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    	}
    	for(i=1;i<=n;i++){
    		ll sum=0;
    		for(j=i;j<=n;j++){
    			sum+=arr[i];
    			mz[j=i+1]=max(mz[j-i+1],sum);
    		}
    	}
    	for(i=0;i<=n;i++){
    		ll ans=-1e18;
    		for(j=1;j<=i;j++){
    			ans=max(ans,mz[j]+x*j);
    		}
    		for(j=i+1;j<=n;j++){
    			ans=max(ans,mz[j]+x*i);
    		}
    		cout<<ans<<'\n';
    	}
    }
    return 0;
}
