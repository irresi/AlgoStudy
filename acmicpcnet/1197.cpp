//kruscal
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int v,e,ans=0;
struct UnionFind{
	vector<int> G;
	UnionFind(int n){G.resize(n); iota(all(G),0);}
	int fnd(int num){return num==G[num]?num:G[num]=fnd(G[num]);}
	bool merge(int a, int b){
		G[fnd(a)]=G[fnd(b)];
		return a!=b;
	}
};
struct MST{
	vector<vector<ll>> ed; //cost, u, v
	vector<vector<ll>*> getp(){
		sort(all(ed));
		vector<vector<ll>*> p;
		UnionFind UF(v+1);
		for(auto& t : ed){
			if(UF.merge(t[1],t[2])) p.push_back(&t);
		}
		return p;
	}
	ll getcost(){
	    ll ans=0;
        auto path = getp();
        for(auto t : path) ans+=(*t)[0];
        return ans;
	}
};
int main()
{
    cin>>v>>e;
	MST T;
	int a,b,c;
    for(int i=1;i<=e;i++){
    	cin>>a>>b>>c;
    	T.ed.push_back({c,a,b});
    }
    cout<<T.getcost();
    return 0;
}
