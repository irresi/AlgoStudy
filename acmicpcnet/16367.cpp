#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,k;
vector<int> ed[10003],red[10003];
stack<int> st;
int chk[10003],ans[10003],gr[10003];
int no(int num){
    if(num<=n) return num+n;
    return num-n;
}
void dfs(int num){
    chk[num]=1;
    for(int nxt : ed[num])if(!chk[nxt]){
        dfs(nxt);
    }
    st.push(num);
}
void rdfs(int num, int rep){
    chk[num]=0;
    gr[num]=rep;
    if(!ans[num] && !ans[no(num)]) ans[no(num)]=1;
    for(int nxt : red[num])if(chk[nxt]){
        rdfs(nxt,rep);
    }
    return;
}
void SCC(){
    int i;
    for(i=1;i<=2*n;i++)if(!chk[i]){
        dfs(i);
    }
    while(!st.empty()){
        int tp = st.top(); st.pop();
        if(chk[tp]) rdfs(tp,tp);
    }
    return;
}
void con(int a, int b){
    ed[no(a)].push_back(b);
    ed[no(b)].push_back(a);
    red[b].push_back(no(a));
    red[a].push_back(no(b));
    return;
}
int main()
{
    int a,b,c,i;
    char ca,cb,cc;
    cin>>n>>k;
    for(i=1;i<=k;i++){
        cin>>a>>ca>>b>>cb>>c>>cc;
        if(ca=='B') a=no(a);
        if(cb=='B') b=no(b);
        if(cc=='B') c=no(c);
        con(a,b);
        con(a,c);
        con(b,c);
    }
    SCC();
    for(i=1;i<=n;i++){
        if(gr[i]==gr[i+n]){
            cout<<-1;
            return 0;
        }
    }
    for(i=1;i<=n;i++){
        if(ans[i]) cout<<'R';
        else cout<<'B';
    }
    return 0;
}
//
