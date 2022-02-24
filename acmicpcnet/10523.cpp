#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,p,req;
vector<pll> inp;
int main()
{
    srand(time(NULL));
	ll tc,i,j,a,b,dx,dy,x,y,g;
    sync()
    cin>>n>>p;
    req=(n*p/100)+(n*p%100>0);
    for(i=0;i<n;i++){
    	cin>>x>>y;
    	inp.emplace_back(x,y);
    }
    if(n==1){
        cout<<"possible";
        return 0;
    }
    for(i=1;i<=150;i++){
   		int meet=0;
    	a=rand()%n;b=rand()%n;
    	while(a==b) b=rand()%n;
    	dx=inp[a].X-inp[b].X; dy=inp[a].Y-inp[b].Y;
    	for(j=0;j<n;j++){
    		if((inp[a].X-inp[j].X)*dy==(inp[a].Y-inp[j].Y)*dx) meet++;
    	}
    	if(meet>=req) break;
    }
    if(i<=100) cout<<"possible";
    else cout<<"impossible";
    return 0;
}
