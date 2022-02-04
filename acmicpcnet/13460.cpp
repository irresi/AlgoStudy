#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
array<int,2> w[4]={0,1,1,0,0,-1,-1,0};
char str[12][12];
bool pos(array<int,2> A){
    return str[A[0]][A[1]]!='#';
}
array<int,2> nxt(array<int,2>A,int tp){
    return {A[0]+w[tp][0],A[1]+w[tp][1]};
}
int main()
{
	array<int,2> B,R,O,nB,nR,nnB,nnR;
    queue<tuple<int,array<int,2>,array<int,2>>>q; //lv, B,R
    int i,j,lv;
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	cin>>str[i]+1;
    	for(j=1;j<=m;j++){
    		if(str[i][j]=='B') B={i,j};
    		if(str[i][j]=='R') R={i,j};
    		if(str[i][j]=='O') O={i,j};
    	}
    }
    q.push({0,B,R});
    int bcnt,rcnt,flag;
    while(!q.empty()){
    	tie(lv,B,R) = q.front(); q.pop();
    	for(i=0;i<4;i++){
            nB=B;nR=R;
            bcnt=rcnt=flag=0;
            while(pos(nxt(nB,i))) {
                nB=nxt(nB,i),bcnt++;
                if(nB==O) flag|=1;
            }
            while(pos(nxt(nR,i))) {
                nR=nxt(nR,i),rcnt++;
                if(nR==O) flag|=2;
            }
    		if(flag==1 || flag==3) continue;
    		if(flag==2){cout<<lv+1; exit(0);}
    		if(nB==nR){
                if(bcnt<rcnt) nR=nxt(nR,i^2);
                else nB=nxt(nB,i^2);
    		}
    		if(lv+1<=9)q.push({lv+1,nB,nR});
    	}
    }
    cout<<"-1";
    return 0;
}
//코드 짜기 전에 어떻게 구현할지 좀 더 생각해 보기