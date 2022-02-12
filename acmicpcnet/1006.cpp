#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,w,arr[2][10003],d[10003][4],ans;
void f(){
	for(int i=1;i<=n;i++){
		if(d[i][0]<inf){
			d[i][1]=min(d[i][1],d[i][0]+1);
			d[i][3]=min(d[i][3],d[i][0]+1);
			if(arr[0][i]+arr[0][i+1]<=w) d[i][2]=min(d[i][2],d[i][0]+1);
			if(arr[0][i]+arr[1][i]<=w) d[i+1][0]=min(d[i+1][0],d[i][0]+1);
		}
		if(d[i][1]<inf){
			d[i+1][0]=min(d[i+1][0],d[i][1]+1);
			if(arr[1][i]+arr[1][i+1]<=w)d[i+1][3]=min(d[i+1][3],d[i][1]+1);
		}
		if(d[i][2]<inf){
			d[i+1][1]=min(d[i+1][1],d[i][2]+1);
			if(arr[1][i]+arr[1][i+1]<=w) d[i+2][0]=min(d[i+2][0],d[i][2]+1);
		}
		if(d[i][3]<inf){
			d[i+1][0]=min(d[i+1][0],d[i][3]+1);
			if(arr[0][i]+arr[0][i+1]<=w) d[i+1][1]=min(d[i+1][1],d[i][3]+1);
		}
	}
}
int main()
{
    int tc,i;
    sync()
    cin>>tc;
    while(tc--){
        ans=inf;
    	cin>>n>>w;
    	for(i=1;i<=n;i++) cin>>arr[0][i];
    	for(i=1;i<=n;i++) cin>>arr[1][i];

    	fill(d[0],d[0]+sizeof(d)/sizeof(int),inf);
    	d[1][0]=0;
    	f();
    	ans=min(ans,d[n+1][0]);
    	if(arr[0][1]+arr[0][n]<=w){
	    	fill(d[0],d[0]+sizeof(d)/sizeof(int),inf);
	    	d[1][1]=1;
	    	f();
	    	ans=min(ans,d[n][3]);
    	}
    	if(arr[1][1]+arr[1][n]<=w){
	    	fill(d[0],d[0]+sizeof(d)/sizeof(int),inf);
	    	d[1][3]=1;
	    	f();
	    	ans=min(ans,d[n][1]);
    	}
    	if(arr[0][1]+arr[0][n]<=w && arr[1][1]+arr[1][n]<=w){
	    	fill(d[0],d[0]+sizeof(d)/sizeof(int),inf);
	    	d[2][0]=2;
	    	f();
	    	ans=min(ans,d[n][0]);
    	}
    	cout<<ans<<'\n';
    }
    return 0;
}
//arr을 써야 하는 자리에 d배열을 써서 틀렸었다.
//배열이름에 주의하자.