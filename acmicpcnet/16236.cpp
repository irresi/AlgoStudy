#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,ans;
int chk[23][23],arr[23][23],w[4][2]={-1,0,0,-1,0,1,1,0};
int main()
{
 	int i,j,flag=1,r,c,lv=2,exp=0;
 	cin>>n;
 	for(i=1;i<=n;i++){
 		for(j=1;j<=n;j++){
 			cin>>arr[i][j];
 			if(arr[i][j]==9) {
                r=i,c=j;
                arr[i][j]=0;
 			}
 		}
 	}
 	int nr,nc,eattime,eatr,eatc;
 	while(flag){
 		flag=0;
 		memset(chk,0,sizeof(chk));
 		queue<pair<int, int> > q;
        eattime=eatr=eatc=1e9;

 		chk[r][c]=1;
 		q.push({r,c});
 		while(!q.empty()){
 			tie(r,c) = q.front(); q.pop();
 			if(arr[r][c] && arr[r][c]<lv && eattime>=chk[r][c]) {
                eattime=chk[r][c];
                if(r<eatr || (r==eatr && c<eatc)) eatr=r,eatc=c;
 				flag=1;
 			}
 			for(i=0;i<4;i++){
 				nr=r+w[i][0],nc=c+w[i][1];
 				if(!chk[nr][nc] && arr[nr][nc]<=lv && nr>0 && nc>0 && nr<=n &&nc<=n){
 					chk[nr][nc]=chk[r][c]+1; q.push({nr,nc});
 				}
 			}
 		}
 		if(flag){
 		    r=eatr,c=eatc;
 		    arr[r][c]=0;
 		    ans+=chk[r][c]-1; exp++;
        }
 		if(lv<=exp) exp-=lv,lv++;
 	}
 	cout<<ans;
    return 0;
}
