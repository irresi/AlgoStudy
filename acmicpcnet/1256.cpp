#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,k;
long long C[203][203];
string str;
int main()
{
	int i,j;
    C[0][0]=1;
    cin>>n>>m>>k;
    for(i=1;i<=200;i++){
    	C[i][0]=1;
    	for(j=1;j<=i;j++){
    		C[i][j]=C[i-1][j]+C[i-1][j-1];
    		if(C[i][j]>k) C[i][j]=inf;
    	}
    }
    if(C[n+m][n]<k){
    	cout<<-1;
    	return 0;
    }
    while(n+m){
    	if(k<=C[n+m-1][m]) str+='a',n--;
    	else{
    		k-=C[n+m-1][m]; str+='z'; m--;
    	}
    }
    cout<<str;
    return 0;
}
