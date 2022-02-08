#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,topl;
int arr[200003];
int main()
{
	int i,j,tc,ans;
    cin>>tc;
    while(tc--){
    	cin>>n;
    	for(i=1;i<=n;i++) cin>>arr[i];
    	int num =arr[n],cnt=1,ed=n-1;
    	ans=0;
    	while(ed>0){
    		while(ed>0 &&arr[ed]==num) cnt++,ed--;
    		if(ed<=0) break;
    		ans++;
    		topl=0;
    		for(i=1;i<=cnt;i++){
    			arr[ed--]=num;
    			topl++;
    			if(ed==0) break;
    		}
    		cnt+=topl;
    	}
    	cout<<ans<<'\n';
    }
    return 0;
}
