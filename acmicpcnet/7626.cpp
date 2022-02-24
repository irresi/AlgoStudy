#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m;
struct line{
	ll x,y1,y2,t;
	bool operator<(const line &r)const{
		return x<r.x;
	}
}inp[400003];
vector<int> lib;
int renum(int num) {return lower_bound(all(lib),num)-lib.begin()+1;}
ll query(int nn=1, )
int main()
{
	int tc,i,j;
    sync()
    for(i=1;i<=n;i++){
    	cin>>x1>>x2>>y1>>y2;
    	inp[i]={x1,y1,y2,1};
    	inp[i+n]={x2,y1,y2,-1};
    	lib.emplace_back(y1);
    	lib.emplace_back(y2);
    }
    sort(all(lib));
    lib.erase(unique(all(lib)),lib.end());
    sort(inp+1,inp+1+2*n);
    for(i=1;i<=2*n;i++){
    	ans+=query()*(inp[i].x-inp[i-1].x);
    	update(renum(inp[i].y1),renum(inp[i].y2),inp[i].t);
    }
    return 0;
}
