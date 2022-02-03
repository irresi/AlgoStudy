#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int v,e;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> ed[20003];
int dist[20003];
int main()
{
	int i,j,a,b,c,s;
    cin>>v>>e>>s;
    for(i=1;i<=e;i++){
    	cin>>a>>b>>c;
    	ed[a].push_back({b,c});
    }
    fill(dist+1,dist+v+1,inf);
    dist[s]=0; 
    pq.push({0,s});
    while(!pq.empty()){
    	auto [c,a] = pq.top(); pq.pop();
    	if(dist[a]<c) continue;
    	for(auto [b,nc] : ed[a])if(dist[b]>dist[a]+nc){
    		dist[b]=dist[a]+nc;
    		pq.push({dist[b],b});
    	}
    }
    for(i=1;i<=v;i++) {
    	if(dist[i]==inf) cout<<"INF";
    	else cout<<dist[i];
    	cout<<"\n";
    }
    return 0;
}
