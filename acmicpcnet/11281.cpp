#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}
int n,m;
int no(int num){
    return 2*n-num;
}
vector<int> ed[20003],red[20003];
vector<int> v;
int chk[20003],gr[20003],ans[10003];
vector<int> grnums[20003];
void dfs(int num){
    chk[num]=1;
    for(int nxt : ed[num])if(!chk[nxt]){
        dfs(nxt);
    }
    v.push_back(num);
}
void rdfs(int num, int rep){
    gr[num]=rep;
    grnums[rep].push_back(num);
    chk[num]=0;
    for(int nxt : red[num])if(chk[nxt]){
        rdfs(nxt,rep);
    }
    return;
}
void SCC(){
    int i,j;
    //1. dfs를 돌며 종료할 때 스택에 넣기
    //2. 스택에서 pop하면서 컴포넌트에 포함 X라면 역그래프에 연결된 것으로 컴포넌트 만들기
    for(i=0;i<=2*n;i++)if(i!=n){
        if(!chk[i]) dfs(i);
    }
    while(!v.empty()){
        i=v.back(); v.pop_back();
        if(chk[i]){
            rdfs(i,i);
        }
    }
    return;
}
bool Topo_Sort(){
    //dfs를 돌면서 나가는 순으로 넣는다.
    for(int i=0;i<=2*n;i++)if(i!=n && gr[i]==i){
        if(!chk[i]) dfs(i);
    }
    memset(chk,0,sizeof(chk));
    while(!v.empty()){
        int gr = v.back(); v.pop_back();
        set<int> lib;
        for(int num : grnums[gr]){
            if(lib.find(no(num))!=lib.end()){
                return false;
            }
            lib.insert(num);
            if(!ans[abs(num-n)]) ans[abs(num-n)]=(num-n)/abs(num-n);
        }
    }
    return true;
}
int main()
{
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        a+=n; b+=n;
        ed[no(a)].push_back(b);
        ed[no(b)].push_back(a);
        red[b].push_back(no(a));
        red[a].push_back(no(b));
    }
    SCC();
    bool bg = Topo_Sort();
    cout<<bg<<'\n';
    if(bg) for(int i=1;i<=n;i++) cout<<(ans[i]==-1)<<' ';
    return 0;
}
