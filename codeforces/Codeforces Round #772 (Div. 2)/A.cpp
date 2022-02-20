#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,ans;

int main()
{
	int tc,i,j;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n;
    	ans=0;
    	for(i=1;i<=n;i++){
    		cin>>m;
    		ans|=m;
    	}
    	cout<<ans<<'\n';
    }
    return 0;
}
