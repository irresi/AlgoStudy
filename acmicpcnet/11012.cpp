#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}
int n,m,ans;
vector<array<int,3>> query; //x,y,qt(0 : add, 1 : ans-=[1,x]*[1,y], 3 : ans+= ``)
struct segtree{
	int t[100003]; //1~100001
	void update(int x){for(;x<=100001;x+=x&-x) t[x]++;}
	int query(int x){int ret=0;for(;x;x-=x&-x) ret+=t[x]; return ret;}
	void clear(){memset(t,0,sizeof(t));}
}T;
int main()
{
	int tc,i,j,sx,ex,sy,ey,x,y;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n>>m;
    	for(i=1;i<=n;i++){
    		cin>>x>>y; ++x; ++y;
    		query.push_back({x,y,0});
    	}
    	for(i=1;i<=m;i++){
    		cin>>sx>>ex>>sy>>ey; ++sx,++ex,++sy,++ey;
    		query.push_back({ex,ey,3});
    		query.push_back({sx-1,ey,1});
    		query.push_back({ex,sy-1,1});
    		query.push_back({sx-1,sy-1,3});
    	}
    	sort(all(query));
    	for(auto [x,y,qt] : query){
    		if(!qt) T.update(y);
    		else{
    			ans+=(qt-2)*T.query(y);
    		}
    	}
    	cout<<ans<<'\n';
    	query.clear();
    	T.clear();
    	ans=0;
    }
    return 0;
}
