#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n;

int main()
{
	int tc,i,num,mx,ans;
	sync();
    cin>>tc;
    while(tc--){
    	ans=0;
    	cin>>n;
    	mx=-inf;
    	for(i=1;i<=n;i++){
    		cin>>num;
    		if(num>mx) mx=num;
    		if(mx==i) ans++;
    	}
    	cout<<ans<<'\n';
    }
    return 0;
}
