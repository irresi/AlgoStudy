#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct BIT{
    ll t[100003];
    void upd(int x, int val){for(;x<=n;x+=x&-x) t[x]+=val;}
    ll get(int x){ll ret=0; for(;x;x-=x&-x) ret+=t[x]; return ret;}
}T;
int arr[100003];
int main(){
    int i,j,a,b,c;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        T.upd(i,arr[i]-arr[i-1]);
    }
    cin>>m;
    for(i=1;i<=m;i++){
        cin>>a;
        if(a==1){
            cin>>a>>b>>c;
            T.upd(a,c); T.upd(b+1,-c);
        }
        else {
            cin>>a;
            cout<<T.get(a)<<'\n';
        }
    }
}
