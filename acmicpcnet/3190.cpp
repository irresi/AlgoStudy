#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,k,l;
int w[4][2]={0,-1,-1,0,0,1,1,0};
int arr[103][103],chk[103][103];
int main()
{
	int a,b,i,j,r=1,c=1,t=2,curt=0;
	char ch;
	int len=1;
    cin>>n>>k;
    fill(&chk[0][0],&chk[0][0]+sizeof(chk)/sizeof(int),-1);
    chk[1][1]=0;
    for(i=1;i<=k;i++){
    	cin>>a>>b;
    	arr[a][b]=1;
    }
    cin>>l;
   	vector<pair<int,char>> v; 
    for(i=1;i<=l;i++){
    	cin>>a>>ch;
    	v.push_back({a,ch});
    }
    v.push_back({1e9,0});
    for(i=0;i<=l;i++) {
    	tie(a,ch) = v[i];
    	while(curt<a){
    		++curt;
    		r+=w[t][0]; c+=w[t][1];
    		if(len+chk[r][c]>=curt || r>n || c>n || r<=0 || c<=0){
    			cout<<curt;
    			exit(0);
    		}
    		chk[r][c]=curt;
    		len+=arr[r][c]; arr[r][c]=0;
    	}
    	if(ch=='D') t=(t+1)%4;
    	else t=(t+3)%4;
    }
    return 0;
}
