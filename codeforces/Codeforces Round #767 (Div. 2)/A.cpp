#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,k,a[103],b[103];
vector<pii> v;
int main()
{
    int tc,i,j;
    sync();
    cin>>tc;
    while(tc--){
    	v.clear();
    	cin>>n>>k;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    	}
    	for(i=1;i<=n;i++) {
    		cin>>b[i];
    		v.push_back({a[i],b[i]});
    	}
    	sort(all(v));
    	for(auto [a,b] : v){
    		if(a<=k) k+=b;
    		else break; 
    	}
    	cout<<k<<'\n';
    }
    return 0;
}
