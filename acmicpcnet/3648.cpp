#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
int ans[2003];
vector<int> ed[2003],red[2003],ned;
stack<int> st;
int chk[2003],gr[2003];
int no(int num){
	if(num<=n) return num+n;
	return num-n;
}
void dfs(int num){
	chk[num]=1;
	for(int nxt : ed[num])if(!chk[nxt]){
		dfs(nxt);
	}
	st.push(num);
}
void rdfs(int num, int rep){
	chk[num]=0;
	gr[num]=rep;
	if(!ans[num] && !ans[no(num)]) ans[no(num)]=1;
	for(int nxt : red[num])if(chk[nxt]){
		rdfs(nxt,rep);
	}
	return;
}
void SCC(){
	for(int i=1;i<=2*n;i++){
		if(!chk[i]) dfs(i);
	}
	while(!st.empty()){
		int tp = st.top(); st.pop();
		if(chk[tp]) rdfs(tp,tp);
	}
}
int main()
{
	int i,a,b;
	sync()
 	while(cin>>n>>m){
 		for(i=1;i<=m;i++){
 			cin>>a>>b;
 			if(a<0) a=-a+n;
 			if(b<0) b=-b+n;
 			ed[no(a)].push_back(b);
 			ed[no(b)].push_back(a);
 			red[b].push_back(no(a));
 			red[a].push_back(no(b));
 		}
 		//SCC의 같은 그룹에 x와 x+n이 있으면 안 됨.
 		SCC();
 		int flag=0;
 		for(i=1;i<=n;i++) if(gr[i]==gr[i+n]) flag=1;
 		if(flag || ans[1+n]) cout<<"no\n";
 		else cout<<"yes\n";

 		for(i=1;i<=2*n;i++){
 			ed[i].clear();
 			red[i].clear();
 		}
 		fill(ans+1,ans+1+2*n,0);
 	}
    return 0;
}
//2SAT을 SCC와 위상정렬을 2번 할 필요없이 SCC만 하면 되었다.
//dfs가 끝나는 순으로 저장한 리스트가 있다고 할 때
//코사라주 알고리즘은 이 리스트의 역방향으로 iterate하면서 SCC를 만들고
//위상정렬의 역방향, 즉 리스트의 순방향으로 돌면서 true를 넣어줘야 했다.
//위상정렬을 또 할 필요 없이 SCC를 할 때 리스트의 역방향으로 돌며 false를 넣어주면 된다.