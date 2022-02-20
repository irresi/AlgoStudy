#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n;

int main()
{
	int tc,i,num,odd,even,flag;
	sync();
    cin>>tc;
    while(tc--){
    	cin>>n;
    	flag=1;
    	odd=even=-inf;
    	for(i=1;i<=n;i++){
    		cin>>num;
    		if(num&1) {
    			if(num<odd) flag=0;
    			odd=num;
    		}
    		else {
    			if(num<even) flag=0;
    			even=num;
    		}
    	}
    	if(flag) cout<<"Yes\n";
    	else cout<<"No\n";
    }
    return 0;
}
