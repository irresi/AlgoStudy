#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,ans;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> ed[10003];
int chk[10003];
int main()
{
 	int v,e,a,b,c;
 	cin>>v>>e;
 	for(int i=1;i<=e;i++){
 		cin>>a>>b>>c;
 		ed[a].push_back({b,c});
 		ed[b].push_back({a,c});
 	}
 	pq.push({0,1});
 	while(!pq.empty()){
 		tie(c,a) = pq.top(); pq.pop();
 		if(chk[a]) continue;
 		chk[a]=1;
 		ans+=c;
 		for(auto [na,nc] : ed[a])if(!chk[na]){
 			pq.push({nc,na});
 		}
 	}
 	cout<<ans;
    return 0;
}
