#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}
int n,m;
vector<int> ed[1003];
int chk[1003],rev[1003];
bool bipartite(int l){
	for(int r : ed[l]){
		if(chk[r]) continue;
		chk[r]=1;
		if(rev[r]<0 || bipartite(rev[r])){
			rev[r]=l;
			return true;
		}
	}
	return false;
}
int main()
{
	int tc,i,j,a,b;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n>>m;

    	for(i=0;i<n;i++) ed[i].clear();
    	fill(rev,rev+n,-1);

    	for(i=1;i<=m;i++){
    		cin>>a>>b;
    		ed[a].push_back(b);
    	}
    	int ans=0;
    	for(i=0;i<n;i++){
    		fill(chk,chk+n,0);
    		ans+=bipartite(i);
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}
