#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}
int n,m,chk[20003],gr[20030],ans[20003];
vector<int> ed[20003],red[20003];
stack<int> st;
inline int no(int num){
    if(num<=n) return num+n;
    return num-n;
}
void dfs(int num){
    chk[num]=1;
    for(int nxt : ed[num])if(!chk[nxt]){
        dfs(nxt);
    }
    st.push(num);
    return;
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
void kosaraju(){
    //1. dfs가 끝나는 순으로 리스트를 만든다.
    //2. 리스트 역순으로 그룹을 만든다. 등장하는 노드를 false로 체크한다.
    int i,tp;
    for(i=1;i<=2*n;i++) if(!chk[i]) dfs(i);
    while(!st.empty()){
        tp = st.top(); st.pop();
        if(chk[tp]) rdfs(tp,tp);
    }
    return;
}
int main()
{
    int i,a,b;
    sync()
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>a>>b;
        if(a<0) a=-a+n;
        if(b<0) b=-b+n;
        ed[no(a)].push_back(b);
        ed[no(b)].push_back(a);
        red[b].push_back(no(a));
        red[a].push_back(no(b));
    }
    kosaraju();
    int flag=1;
    for(i=1;i<=n;i++) if(gr[i]==gr[i+n]) flag=0;
    cout<<flag<<'\n';
    if(flag){
        for(i=1;i<=n;i++) cout<<ans[i]<<' ';
    }
    return 0;
}
