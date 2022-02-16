#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,root;
ll p[100003],subtreesz[10003];
vector<ll> ed[100003],visitorder={0};
ll whatorder[100003];
struct BIT{
    ll t[100003];
    void upd(ll a, ll b, ll val){
        upd(b,val); upd(a-1,-val);
    }
    void upd(ll idx, ll val){
        for(;idx;idx-=idx&-idx) t[idx]+=val;
    }
    ll get(ll idx){
        ll ret=0;
        for(;idx<=n;idx+=idx&-idx) ret+=t[idx];
        return ret;
    }
}T;
void dfs(ll cur, ll prev)
{
    whatorder[cur] = visitorder.size();
    visitorder.push_back(cur);
    subtreesz[cur]=1;
    for(ll nxt : ed[cur])if(prev!=nxt){
        dfs(nxt,cur);
        subtreesz[cur]+=subtreesz[nxt];
    }
    return;
}

int main(){
    ll i,a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a;
        p[i]=a;
        if(a==-1) root=i;
        else{
            ed[a].push_back(i);
        }
    }
    dfs(root,0);
    for(i=1;i<=m;i++){
        cin>>a>>b;
        T.upd(whatorder[a],whatorder[a]+subtreesz[a]-1,b);
    }
    for(i=1;i<=n;i++) cout<<T.get(whatorder[i])<<' ';
    return 0;
}
//오프라인 쿼리로 처리해도 되는데 온라인으로 처리해 봤다.
