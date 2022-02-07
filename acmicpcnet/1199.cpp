#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n;
vector<pair<int, int>> g[1003];
int pos[1003];
void dfs(int v){
	while(pos[v]<g[v].size()){
		auto [w,ind] = g[v][pos[v]];
		if(w==-1) {
			pos[v]++; continue;
		}
		g[v][pos[v]].first=-1; g[w][ind].first=-1;
        pos[v]++;
		dfs(w);
	}
    cout<<v<<' ';
	return;
}
int main()
{
	int i,j,num,sum,flag;
    cin>>n;
    for(i=1;i<=n;i++){
            sum=0;
    	for(j=1;j<=n;j++){
    		cin>>num;
    		sum+=num;
    		if(i<j){
                while(num--){
                    g[i].emplace_back(j,g[j].size());
                    g[j].emplace_back(i,g[i].size()-1);
                }
    		}
    	}
        if(sum&1) flag=1;
    }
    if(flag) cout<<"-1";
    else dfs(1);
    return 0;
}
