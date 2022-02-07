#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n;
int arr[23][23],inp[23][23],ans;
vector<int> nxt[23];
queue<int> q[23];
vector<int> sr[4],sc[4];
int w[4][2]={0,1,1,0,0,-1,-1,0};
void f(int t){
    int r,c,prev,i,j;
    for(i=0;i<n;i++)nxt[i].clear();

	for(i=0;i<n;i++){
        r=sr[t][i];c=sc[t][i]; prev=0;
        for(j=0;j<n;j++){
            if(prev){
                if(arr[r][c]==prev){
                    prev*=2; arr[r][c]=-1;
                }
            }
            if(arr[r][c]) {
                if(prev) nxt[i].push_back(prev);
                if(arr[r][c]>0) prev=arr[r][c];
                else prev=0;
            }
            r+=w[t][0];c+=w[t][1];
        }
        if(prev) nxt[i].push_back(prev);
	}

	memset(arr,0,sizeof(arr));
	for(i=0;i<n;i++){
        nxt[i].resize(n,0);
        r=sr[t][i]; c=sc[t][i];
        for(j=0;j<n;j++){
            arr[r][c]=nxt[i][j];
            ans=max(arr[r][c],ans);
            r+=w[t][0];c+=w[t][1];
        }
	}
	return;
}
int main()
{
    int i,j,curi;
    cin>>n;
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		cin>>inp[i][j];
    	}
    }
    sr[1].resize(n,1);
    sc[0].resize(n,1);
    sr[3].resize(n,n);
    sc[2].resize(n,n);
    sr[0].resize(n);
    iota(all(sr[0]),1);
    sc[1]=sc[3]=sr[2]=sr[0];
    for(i=0;i<1024;i++){
    	curi=i;
        copy(inp[0],inp[0]+sizeof(inp)/sizeof(int),arr[0]);
    	for(j=0;j<5;j++){
    		f(curi&3);
    		curi>>=2;
    	}
    }
    cout<<ans;
    return 0;
}
