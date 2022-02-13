#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[1003][1003];
char ascii[256];
int flag=0;
string ans;
void arrT(){
    flag=!flag;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    swap(n,m);
    return;
}
void strT(string& S){
    for(char& ch : S){
        ch=ascii[ch];
    }
    return;
}
string strUD(const string &S){
    string ret=S;
    for(char &ch : ret){
        if(ch=='U') ch='D';
        else if(ch=='D') ch='U';
    }
    return ret;
}
string mv(int n, int m){
    string ret="";
    for(int i=1;i<=m;i++){
        if(i&1) ret+=string(n-1,'D');
        else ret+=string(n-1,'U');
        if(i!=m) ret+='R';
    }
    return ret;
}
string roll(int pos){
    string ret="";
    int flag=1;
    for(int i=1;i<=n;i++){
        if(i!=pos){
            if(flag) ret+='R';
            else ret+='L';
            flag=!flag;
        }
        if(i!=n) ret+='D';
    }
    return ret;
}
int main(){
    ascii['R']='D'; ascii['D']='R'; ascii['L']='U'; ascii['U']='L';
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    if(n&1) arrT();
    if(m&1){
        ans=mv(n,m);
        if(flag) strT(ans);
        cout<<ans;
    }
    else{
        int mi=2,mj=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)if(i+j&1){
                if(arr[i][j]<arr[mi][mj]) mi=i,mj=j;
            }
        }
        if(mi==1 || mj==m) {
            arrT();
            swap(mi,mj);
        }
        if(mj-1) ans=mv(n,mj-1)+'R';
        if(mj&1){
            ans+=roll(mi);
            if(m-mj-1){
                ans+='R'+strUD(mv(n,m-mj-1));
            }
        }
        else {
            ans+=strUD(roll(n+1-mi));
            if(m-mj-1){
                ans+='R'+mv(n,m-mj-1);
            }
        }
        if(flag) strT(ans);
        cout<<ans;
    }
}
