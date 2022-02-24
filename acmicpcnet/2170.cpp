#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define S first
#define E second
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,ans,me;
vector<pii> v;
int main()
{
	int tc,i,j,a,b,e;
    sync()
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>a>>b;
    	v.emplace_back(a,b);
    }
    sort(all(v));
    e=v[0].S;
    for(i=0;i<n;i++){
    	if(e<v[i].S){
    		e=v[i].E;
    		ans+=e-v[i].S;
    	}
    	else{
    		if(e<v[i].E) ans+=v[i].E-e,e=v[i].E;
    	}
    }
    cout<<ans;
    return 0;
}
