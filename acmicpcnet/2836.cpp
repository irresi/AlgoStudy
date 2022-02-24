#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,ans;
vector<pii> v;
int main()
{
	int tc,i,j,a,b;
    sync()
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	cin>>a>>b;
    	if(a>b){
    		v.push_back({b,a});
    	}
    }
    sort(all(v));
    int me=0;
    for(auto [cs,ce] : v){
    	if(me<cs){
    		me=ce;
    		ans+=ce-cs;
    	}
    	else if(me<ce) ans+=ce-me,me=ce;
    }
    cout<<(ll)ans*2+m;
    return 0;
}
