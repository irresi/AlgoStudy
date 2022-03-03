#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}
int v,e,cnt,ans;
vector<int> ed[1003];
int g[1003],flag,odd[1003];
void dfs(int cur, int rep){
	g[cur]=rep;
	if(ed[cur].size()%2) odd[cnt]++;
	for(int nxt : ed[cur])if(!g[nxt]){
		dfs(nxt,rep);
	}
}
int main()
{
	int tc,i,j,a,b,grnum=0;
    sync()
    cin>>v>>e;
    for(i=1;i<=e;i++){
    	cin>>a>>b;
    	ed[a].push_back(b);
    	ed[b].push_back(a);
    }
    for(i=1;i<=v;i++){
    	if(!g[i]) {
            cnt++;
    		dfs(i,i);
    	}
    }
    for(i=1;i<=cnt;i++) {
        if(odd[i]==0) ans+=2;
        else ans+=odd[i];

    }
    cout<<max(0,ans/2-1);
    return 0;
}
