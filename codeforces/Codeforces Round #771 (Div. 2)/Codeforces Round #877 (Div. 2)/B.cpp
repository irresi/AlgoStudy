#include<bits/stdc++.h>
using namespace std;
char str[100003],revstr[100003];
int n;
int main(){
    int tc,i,j,diff=0;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n;
        cin>>str;
        strcpy(revstr,str);
        reverse(revstr,revstr+n);
        diff=0;
        for(i=0;i<n;i++){
            if(str[i]!=revstr[i]) diff++;
        }
        diff/=2;
        for(i=0;i<=n;i++){
            if((i<diff) or (n-diff<i) or (n%2==0 and i%2==1)) cout<<'0';
            else cout<<'1';
        }
        cout<<'\n';
    }
}