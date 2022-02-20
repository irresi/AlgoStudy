#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n;
int main()
{
	sync()
    int tc,num;
    cin>>tc;
    while(tc--){
    	cin>>n;
    	int l=0,r=0;
    	vector<int> arr(n+1);
    	for(int i=1;i<=n;i++){
    		cin>>arr[i];
    		if(arr[i]!=i && l==0){
    			l=i;
    		}
    		else if(arr[i]==l) r=i;
    	}
    	reverse(arr.begin()+l+1,arr.begin()+r+1);
    	for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
    	cout<<'\n';
    }
    return 0;
}
