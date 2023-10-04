#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
char str[300003];
int ans[300003];
void solve(){
    int state=0,cur=0,i,flag, ansnum=0;
    cin>>n>>str;
    for(i=0;i<n;i++){
        if(cur==0) flag=1;
        if(str[i]=='(') cur++;
        else cur--;
        if(flag) state=(cur+1)/2;
        ans[i]=state;
        flag=0;
        ansnum|=(1<<state);
    }
    if(cur!=0) cout<<"-1\n";
    else{
        if(ansnum==3) {
            cout<<"2\n";
            for(i=0;i<n;i++) cout<<ans[i]+1<<' ';
        }
        else {
            cout<<"1\n";
            for(i=0;i<n;i++) cout<<"1 ";
        }
        cout<<'\n';
    }
    return;
}
signed main(){
    // ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}