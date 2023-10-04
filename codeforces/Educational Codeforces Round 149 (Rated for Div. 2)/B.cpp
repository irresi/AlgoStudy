#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
char str[300003];
void solve(){
    cin>>str;
    int i,j,s=0,e=strlen(str)-1,ans=0;
    while(str[s]=='?') str[s++]='0';
    while(str[e]=='?') str[e--]='1';
    int prev=-1,cur=-1;
    char ch;
    for(i=s;i<=e;i++){
        if(str[i]!='?'){
            if(prev>=0){
                if(str[prev]==str[i]) ch = str[prev];
                else ch='0';
                ++prev;
                while(prev<i) str[prev]=ch;
            }
            prev=i;
        }
    }
    cout<<str<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}