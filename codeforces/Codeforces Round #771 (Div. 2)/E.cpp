#include <bits/stdc++.h>
using namespace std;
#define nm (ns+ne)/2
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,q;
int val[4000003],col[4000003];
map<int,int> mp[4000003];
void lazy_update(int nn, int ns, int ne){
	val[nn]+=mp[nn][col[nn]];
	if(ns!=ne){
		for(auto [a,b] : mp){
			mp[nn*2][a]+=b;
			mp[nn*2+1][a]+=b;
		}
	}
	return;
}
void color(int ql, int qr, int qc, int nn=1,int ns=1, int ne=n){
	lazy_update(nn,ns,ne);
	if(qr<ns || ne<ql) return;
	else if(ql<=ns && ne<=qr) {
		col[nn]=qc; return;
	}
	color(ql,qr,qc,nn*2,ns,nm); color(ql,qr,qc,nn*2+1,nm+1,ne);
}
void add(int c, int x){
	mp[1][c]+=x;
	return;
}
int query(int x, int nn=1, int ns=1, int ne=n){
	if(x<ns || ne<x) return 0;
	lazy_update(nn,ns,ne);
	if(ns==ne) return val[nn];
	return query(x,nn*2,ns,nm)+query(x,nn*2+1,nm+1,ne);
}
int main()
{
	string str;
	int i,a,b,c;
    cin>>n>>q;
    for(i=1;i<=q;i++){
    	cin>>str;
    	if(str=="Color"){
    		cin>>a>>b>>c;
    		color(a,b,c);
    	}
    	else if(str=="Query"){
    		cin>>a;
    		cout<<query(a)<<'\n';
    	}
    	else if(str=="Add"){
    		cin>>a>>b;
    		add(a,b);
    	}
    }
    return 0;
}
//수정해야 함.
