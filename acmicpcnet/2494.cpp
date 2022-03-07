#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define mod(x) ((x+10)%10)
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}
int n,m,ansi=0;
int arr[10003],d[10003][11],tr[10003][11];
int main()
{
	int tc,i,j,num;
    sync()
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%1d",arr+i);
    for(i=1;i<=n;i++){
        scanf("%1d",&num);
    	arr[i]=mod(num-arr[i]);
    }
    fill(d[0],d[0]+sizeof(d)/sizeof(int),inf);
    d[0][0]=0;
    for(i=1;i<=n;i++){
    	for(j=0;j<10;j++){
    	    if(d[i][arr[i]]>d[i-1][j]+mod(arr[i]-j)){
                d[i][arr[i]]=d[i-1][j]+mod(arr[i]-j);
                tr[i][arr[i]]=mod(arr[i]-j);
    	    }
    	    if(d[i][j]>d[i-1][j]+mod(j-arr[i])){
                d[i][j]=d[i-1][j]+mod(j-arr[i]);
                tr[i][j]=-mod(j-arr[i]);
    	    }
    	}
    }
    for(i=0;i<10;i++)
        if(d[n][ansi]>d[n][i]) ansi=i;
    cout<<d[n][ansi]<<'\n';
    for(i=n;i>=1;i--){
        cout<<i<<' '<<tr[i][ansi]<<'\n';
        if(tr[i][ansi]>0) ansi=mod(ansi-tr[i][ansi]);
    }
    return 0;
}
