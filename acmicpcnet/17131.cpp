#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod=1e9+7;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
struct Point{
	int x, y;
	bool operator<(const Point &r)const{
		return x<r.x || (x==r.x && y>r.y);
	}
}inp[200003];
ll sumy[400003],ans;
struct BIT{
	ll t[400003];
	void update(int s){for(;s<=400001;s+=s&-s) t[s]++;}
	ll query(int x){ll ret=0;for(;x;x-=x&-x) ret+=t[x]; return ret;}
	ll query(int s, int e){	return query(e)-query(s-1);}
}T;
int main()
{
	int tc,i,j;
    sync()
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>inp[i].x>>inp[i].y;
    	inp[i].y+=200001;
    	sumy[inp[i].y]+=1;
    }
    for(i=0;i<=400001;i++) sumy[i]+=sumy[i-1];
    sort(inp+1,inp+1+n);
    int prev=1;
    ll Tq,topl;
    inp[0]={mod,mod};
    for(i=1;i<=n;i++){
    	if(i>1 && inp[i].x!=inp[i-1].x){
    		for(;prev<=i-1;prev++){
    			T.update(inp[prev].y);
    		}
    	}
    	Tq=T.query(inp[i].y+1,400001);
    	if(inp[i].y==inp[i-1].y && inp[i].x==inp[i-1].x) ans+=topl;
    	else ans+=(topl=Tq*(sumy[400001]-sumy[inp[i].y]-Tq-(i-prev)));

    	ans%=mod;
    }
    cout<<ans;
    return 0;
}
//같은 좌료가 2번 등장할 때를 잘 처리해 주어야 한다.