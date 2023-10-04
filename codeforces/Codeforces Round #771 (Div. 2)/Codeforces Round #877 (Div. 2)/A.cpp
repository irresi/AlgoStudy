#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9;
int n,m;
int main(){
    int tc,i,j,k;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>tc;
    while(tc--){
        int cnt=0;
        cin>>n>>m;
        int arr[n][m];
        if(n%2==0){
            for(j=0;j<m;j++){
                for(i=0;i<n;i++){
                    arr[i][j]=++cnt;
                }
            }
        }
        else if(m%2==0){
            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    arr[i][j]=++cnt;
                }
            }
        }
        else{
            for(i=n,k=0;i>=1;i-=2,k++){
                for(j=0;j<m;j++){
                    arr[k][j]=(i-1)*m+j+1;
                }
            }
            for(i=n-1;i>=2;i-=2,k++){
                for(j=0;j<m;j++){
                    arr[k][j]=(i-1)*m+j+1;
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cout<<arr[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}