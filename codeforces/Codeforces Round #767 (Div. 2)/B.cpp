#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int l,r,n;
int tot,even,odd;
int main()
{
    int tc,i;
    cin>>tc;
    while(tc--){
    	cin>>l>>r>>n;
    	tot = (r-l+1);
    	even = r/2-(l-1)/2;
    	odd = tot-even;
    	if(tot==1){
    		if(l==1) cout<<"NO\n";
    		else cout<<"YES\n";
    	}
    	else if(n>=odd) cout<<"YES\n";
    	else cout<<"NO\n";
    }
    return 0;
}
