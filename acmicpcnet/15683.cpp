#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m,cnt,ans;
int w[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<int>> cw={{},{0},{0,2},{0,3},{0,2,3},{0,1,2,3}};
int arr[10][10];
vector<pii> cctv;
void f(int num){
    vector<vector<int>> chk(n+2,vector<int>(m+2,0));
    int nr,nc,res=0;
    for(auto [r,c] : cctv){
        int tpl = num%4;
        num>>=2;
        for(int t : cw[arr[r][c]]){
            t=(t+tpl)%4;
            nr=r+w[t][0],nc=c+w[t][1];
            while(arr[nr][nc]!=6){
                if(!chk[nr][nc] && arr[nr][nc]==0) res++;
                chk[nr][nc]=1;
                nr+=w[t][0],nc+=w[t][1];
            }
        }
    }
    ans=max(ans,res);
    return;
}
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==0) cnt++;
            if(0< arr[i][j] && arr[i][j]<6){
                cctv.push_back({i,j});
            }
        }
    }
    for(i=1;i<=n;i++) arr[i][0]=arr[i][m+1]=6;
    for(i=1;i<=m;i++) arr[0][i]=arr[n+1][i]=6;
    for(i=0;i<(1<<2*cctv.size());i++){
        f(i);
    }
    cout<<cnt-ans;
    return 0;
}
