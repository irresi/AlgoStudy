#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m;
int chk[3003];
vector<int> v[3003];
void dfs(int cur){
	chk[cur]=1;
	for(int nxt : v[cur]) if(!chk[nxt]){
		dfs(nxt);
	}
	return;
}
int main()
{
	int tc,i,j,a,b;
    sync()
    cin>>n>>m;
    for(i=1;i<=m;i++){
    	cin>>a>>b;
    	v[a].push_back(b);
    	v[b].push_back(a);
    }
    dfs(1);
    int odd=0;
    for(i=1;i<=n;i++) {
    	if(!chk[i]){y
    		cout<<"NO";
    		return 0;
    	}
    	odd+=v[i].size()&1;
    }
    if(odd==0 || odd==2) cout<<"YES";
    else cout<<"NO";
    return 0;
}
