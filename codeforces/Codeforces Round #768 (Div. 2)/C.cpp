#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,k;
int main()
{
    int tc,i;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n>>k;
    	if(k==n-1) {
    		if(n==4){
    			cout<<"-1\n";
    		}
    		else{
    			cout<<n-1<<' '<<n/2-1<<'\n';
    			cout<<n/2<<' '<<n/2+1<<'\n';
    			cout<<n/2-2<<' '<<0<<'\n';
    			for(i=1;i<=n/2-3;i++){
    				cout<<i<<' '<<n-1-i<<"\n";
    			}
    		}
    	}
    	else{
    		for(i=1;i<n/2;i++){
    			if(i!=k && i!=n-1-k){
    				cout<<i<<' '<<n-1-i<<'\n';
    			}
    		}
    		cout<<n-1<<' '<<k<<'\n';
    		if(k!=0)cout<<"0 "<<n-1-k<<'\n';
    	}
    }
    return 0;
}
