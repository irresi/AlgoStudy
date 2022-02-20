#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,arr[200003],ans;

int main()
{
	int tc,i,j;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n;
    	ans=0;
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    	}
    	for(i=2;i<n;i++){
    		if(arr[i-1]<arr[i] && arr[i]>arr[i+1]) {
    			arr[i+1]=max(arr[i],arr[i+2]);
    			ans++;
    		}
    	}
    	cout<<ans<<'\n';
    	for(i=1;i<=n;i++) cout<<arr[i]<<' ';
    	cout<<'\n';
    }
    return 0;
}
