#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,arr[200003];

int main()
{
	int tc,i,j,flag;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n;
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    	}
    	flag=0;
    	for(i=1;i<n;i++){
    		if(arr[i]>arr[i+1]) flag=1;
    	}
    	if(!flag){
    		cout<<"0\n"; continue;
    	}
    	if(arr[n]<0 || arr[n-1]>arr[n]){
    		cout<<"-1\n"; continue;
    	}
    	cout<<n-2<<'\n';
    	for(i=n-1;i>=2;i--){
    		cout<<i-1<<" "<<i<<' '<<n<<'\n';
    	}
    }
    
    return 0;
}
