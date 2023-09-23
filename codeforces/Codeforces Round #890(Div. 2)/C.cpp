#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int mn=1000;
int d[mn+3][mn*2+3],arr[mn+3],s,e,mx,ans,n,k;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int tc,i,j;
	cin>>tc;
	while(tc--){
		cin>>n>>k;
		mx=ans=0;
		for(i=n;i>=1;i--){
			cin>>arr[i];
			mx=max(mx,arr[i]);
		}
		s=max(mx-mn,0); e=mx+mn;
		
		for(j=0;j<=e-s;j++) d[0][j]=inf;
		for(i=1;i<=n;i++){
			for(j=0;j<=e-s;j++) d[i][j]=inf;
			for(j=0;j<=arr[i]-s;j++) d[i][j]=0;
			if(arr[i-1]>=s-1)
				d[i][0]=max(s-arr[i],0);
			for(j=s+1;j<=e;j++){
				d[i][j-s]=min(d[i][j-s],d[i-1][j-s-1]+max(j-arr[i],0));
				if(d[i][j-s]<=k) ans=max(ans,j);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
