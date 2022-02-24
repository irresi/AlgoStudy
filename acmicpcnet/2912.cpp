#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
int n,c,arr[300003],m;
vector<int> lib[10003];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i,j,a,b;
    srand(time(NULL));
    cin>>n>>c;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        lib[arr[i]].push_back(i);
    }
    cin>>m;
    int col,flag,cnt;
    for(i=1;i<=m;i++){
        cin>>a>>b;
        flag=0;
        for(j=1;j<=20;j++){
            col=arr[a+rand()%(b-a+1)];
            cnt=lower_bound(all(lib[col]),b+1)-lower_bound(all(lib[col]),a);
            if(cnt*2>b-a+1) {
                flag=1;
                break;
            }
        }
        if(flag) cout<<"yes "<<col<<'\n';
        else cout<<"no\n";
    }
    return 0;
}
