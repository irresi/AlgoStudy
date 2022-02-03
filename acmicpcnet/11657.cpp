#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf=1e18+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m;
vector<array<ll,3>> ed;
ll d[503];
int main()
{
	ll a,b,c,i;
    cin>>n>>m;
    for(i=1;i<=m;i++){
    	cin>>a>>b>>c;
    	ed.push_back({a,b,c});
    }
    bool improved=true;
    fill(d+2,d+n+1,inf);
    for(i=1;i<=n && improved;i++){
    	improved=false;
    	for(auto [a,b,c] : ed){
    		if(d[a]!=inf && d[a]+c<d[b]){
    			d[b]=d[a]+c;
    			improved=true;
    		}
    	}
    }
    if(improved) cout<<"-1";
    else for(i=2;i<=n;i++){
    	if(d[i]==inf) d[i]=-1;
    	cout<<d[i]<<'\n';
    }
    return 0;
}
