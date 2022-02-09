#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
vector<vector<int>> ed,red;
vector<int> chk,leaf;
stack<int> st;
vector<int> ans;
void dfs(int num){
	chk[num]=-1;
	for(int nxt : ed[num])if(chk[nxt]!=-1){
		dfs(nxt);
	}
	st.push(num);
}
void rdfs(int num, int rep){
	chk[num]=rep;
	for(int nxt : red[num])if(chk[nxt]==-1){
		rdfs(nxt,rep);
	}
	return;
}
int main()
{
    int tc;
    sync()
    cin>>tc;
    while(tc--){
    	int i,j,a,b;
    	cin>>n>>m;
    	ed.assign(n,{}); red.assign(n,{});
    	chk.assign(n,0); leaf.assign(n,1);
    	ans.clear();

    	for(i=1;i<=m;i++){
    		cin>>a>>b;
    		ed[a].push_back(b);
    		red[b].push_back(a);
    	}
    	for(i=0;i<n;i++)if(chk[i]!=-1){
    		dfs(i);
    	}
    	while(!st.empty()){
    		int tp = st.top(); st.pop();
    		if(chk[tp]==-1){
    			rdfs(tp,tp);
    		}
    	}
    	for(i=0;i<n;i++){
    		for(int nxt : ed[i])if(chk[i]!=chk[nxt]){
    			leaf[chk[nxt]]=0;
    		}
    	}
    	for(i=0;i<n;i++) if(i==chk[i] && leaf[i]) ans.push_back(i);
    	if(ans.size()>=2){
    		cout<<"Confused\n";
    	}
    	else if(ans.size()==1){
    		for(i=0;i<n;i++) if(chk[i]==ans[0]) cout<<i<<"\n";
    	}
    	else{
    		for(i=0;i<n;i++) cout<<i<<'\n';
    	}
    	cout<<'\n';
    }
    return 0;
}
