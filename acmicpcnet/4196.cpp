#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
const int msz=1e5+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m,In[msz],chk[msz],ans,dep[msz];
vector<int> ed[msz],red[msz];
stack<int> st;
void dfs(int num){
	chk[num]=0;
	for(int nxt : ed[num])if(chk[nxt]){
		dfs(nxt);
	}
	st.push(num);
}
void rdfs(int num, int rep){
	chk[num]=rep;
	for(int nxt : red[num])if(!chk[nxt]){
		rdfs(nxt,rep);
	}
	return;
}
int main()
{
	int i,a,b,tc;
	cin>>tc;
	while(tc--){
	    cin>>n>>m;
		ans=0;
	    fill(chk+1,chk+n+1,1);
	    fill(In+1,In+n+1,0);
	    fill(dep+1,dep+n+1,0);

	    for(i=1;i<=n;i++){
	    	ed[i].clear();
	    	red[i].clear();
	    }

	    for(i=1;i<=m;i++){
	    	cin>>a>>b;
	    	ed[a].push_back(b);
	    	red[b].push_back(a);
	    }
	    for(i=1;i<=n;i++)if(chk[i]){
	    	dfs(i);
	    }
	    while(!st.empty()){
	    	int cur = st.top(); st.pop();
	    	if(!chk[cur]){
	    		rdfs(cur,cur);
	    	}
	    }
	    for(i=1;i<=n;i++){
            for(int nxt : ed[i])if(chk[nxt]!=chk[i]){
                dep[chk[nxt]]=1;
            }
	    }
	    for(i=1;i<=n;i++) ans+=(dep[i]==0 && chk[i]==i);
	    cout<<ans<<'\n';
	}
    return 0;
}
