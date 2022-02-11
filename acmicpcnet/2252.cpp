#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m;
int state[32003];
vector<int> ed[32003];
vector<int> ans;
bool hascycle=false;
void dfs(int cur){
	state[cur]=1;
	for(int nxt : ed[cur]){
		if(!state[nxt]) dfs(nxt);
		else if(state[nxt]==1) hascycle=true;
	}
	state[cur]=2;
	ans.push_back(cur);
}
int main()
{
	int i,a,b;
	sync()
    cin>>n>>m;
    for(i=1;i<=m;i++){
    	cin>>a>>b;
    	ed[a].push_back(b);
    }
    for(i=1;i<=n;i++){
    	if(!state[i]) dfs(i);
    }
    reverse(all(ans));
    for(int num : ans) cout<<num<<' ';
    return 0;
}
