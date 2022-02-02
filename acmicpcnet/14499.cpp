#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m,c,r,k;
int arr[30][30];
int w[4][2]={0,1,0,-1,-1,0,1,0};
int cha[4][7]={
	0,1,6,2,3,5,4,
	0,1,3,4,6,5,2,
	0,3,2,5,4,6,1,
	0,6,2,1,4,3,5
};
vector<int> dice(7),nxtdice(7);
int main()
{
	int i,j,num,r,c,nc,nr;
 	cin>>n>>m>>r>>c>>k;
 	for(i=0;i<n;i++){
 		for(j=0;j<m;j++){
 			cin>>arr[i][j];
 		}
 	}
 	for(i=0;i<k;i++){
 		cin>>num;
 		num--;
 		nr=r+w[num][0],nc=c+w[num][1];
 		if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
 		r=nr,c=nc;
 		for(j=1;j<=6;j++) nxtdice[j]=dice[cha[num][j]];
 		cout<<nxtdice[3]<<'\n';
 		if(arr[r][c]==0) arr[r][c]=nxtdice[6];
 		else nxtdice[6]=arr[r][c],arr[r][c]=0;
 		dice=nxtdice;
 	}
    return 0;
}
