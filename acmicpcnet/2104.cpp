#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0); //do not use ;
ll sum[100003],arr[100003],ans,n;
vector<pll> v;
set<ll> lib;
int main()
{
	int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>arr[i];
    	sum[i]=sum[i-1]+arr[i];
    	v.push_back({arr[i],i});
    }
    lib.insert(0);
    lib.insert(n+1);
    sort(all(v));
    set<ll>::iterator si,sj;
    for(auto [val,idx] : v){
    	sj = lib.lower_bound(idx);
    	si=sj; --si;
    	ans=max(ans,val*(sum[*sj-1]-sum[*si]));
    	lib.insert(idx);
    }
    cout<<ans;
    return 0;
}
