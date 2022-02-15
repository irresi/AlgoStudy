#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n;
vector<pii> ed[100003];
int d[100003],mx,mxi;
void tmake(int cur, int prev, int tot){ //{leafnode, cost}
	if(tot>mx) mx=tot,mxi=cur;
	for(auto [nxt,dist] : ed[cur])if(nxt!=prev){
		tmake(nxt,cur,tot+dist);
	}
	return;
}
int main()
{
	int i,idx,num,c;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>idx;
    	while(1){
    		cin>>num;
    		if(num<0) break;
    		cin>>c;
    		ed[idx].push_back({num,c});
    	}
    }
    tmake(1,0,0);
    mx=0;
    tmake(mxi,0,0);
    cout<<mx;
    return 0;
}
//트리에서 임의의 노드 a를 선택한 뒤, 이 노드에서 가장 먼 노드 b를 찾는다.
//b에서 가장 먼 노드 c를 찾는다. b와 c의 거리가 지름이 된다. 