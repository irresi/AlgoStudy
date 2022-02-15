#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n;
vector<int> ed[10003];
vector<pii> eulerpath; //idx, depth
pii t[80003];
int ss=1,pos[10003],cnt[10003];
pii sel(pii A, pii B){
	if(A.second<B.second) return A;
	else return B;
}
void dfs(int cur, int prev, int depth){
	pos[cur]=eulerpath.size();
	eulerpath.push_back({cur,depth});
	for(int nxt : ed[cur]) if(nxt!=prev){
		dfs(nxt,cur,depth+1);
        eulerpath.push_back({cur,depth});
	}
	return;
}
void build(){
	for(int i=ss-1;i>=1;i--){
		t[i]=sel(t[i<<1],t[i<<1|1]);
	}
}
int query(int s, int e){
	pii ret={0,inf};
	for(s+=ss,e+=ss;s<=e;s>>=1,e>>=1){
		if(s&1) ret=sel(ret,t[s++]);
		if(e%2==0) ret=sel(ret,t[e--]);
	}
	return ret.first;
}
int main()
{
    sync()
	int tc,a,b,i;
    cin>>tc;
    while(tc--){
    	cin>>n;
    	for(i=1;i<n;i++){
	    	cin>>a>>b;
	    	ed[a].push_back(b);
	    	cnt[b]++;
    	}
    	for(i=1;i<=n;i++) if(!cnt[i]) break;
 	    dfs(i,0,1);
    	cin>>a>>b;
    	while(ss<2*n-1) ss<<=1;
    	for(i=0;i<2*n-1;i++){
    		t[ss+i]=eulerpath[i];
    	}
    	build();
    	if(pos[a]>pos[b]) swap(a,b);
    	cout<<query(pos[a],pos[b])<<"\n";

    	for(i=1;i<=n;i++) cnt[i]=0,ed[i].clear();
    	ss=1;
    	fill(t,t+sizeof(t)/sizeof(pii),pii(0,0));
    	eulerpath.clear();
    }
    return 0;
}
