#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const ll inf=1e18+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,w;
ll d[503];
vector<array<ll,3>> ed;
int main()
{
	int i,j,tc;
	ll a,b,c;
    cin>>tc;
    while(tc--){
    	cin>>n>>m>>w;
    	for(i=1;i<=m;i++){
    		cin>>a>>b>>c;
    		ed.push_back({a,b,c});
    		ed.push_back({b,a,c});
    	}
    	for(i=1;i<=w;i++){
    		cin>>a>>b>>c;
    		ed.push_back({a,b,-c});
    	}
    	bool isimproved=true;
    	
    	fill(d+2,d+n+1,inf);
    	for(i=1;i<n && isimproved;i++){
    		isimproved=false;
    		for(auto [a,b,c] : ed){
    			if(d[a]+c<d[b]){
    				d[b]=d[a]+c;
    				isimproved=true;
    			}
    		}
    	}
    	if(i>=n && isimproved) cout<<"YES\n";
    	else cout<<"NO\n";
    	
    	ed.clear();
    }
    return 0;
}
//도로는 양방향이었다! 양방향 단방향 잘 읽자. 