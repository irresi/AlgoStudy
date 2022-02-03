#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m;
int arr[103][103];
int main()
{
	int i,j,k,a,b,c;
	cin>>n>>m;
	for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) arr[i][j]=arr[j][i]=inf;
	for(i=1;i<=m;i++){
		cin>>a>>b>>c;
		arr[a][b]=min(arr[a][b],c);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(arr[j][k]>arr[j][i]+arr[i][k]) arr[j][k]=arr[j][i]+arr[i][k];
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(arr[i][j]==inf) arr[i][j]=0;
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
    return 0;
}
