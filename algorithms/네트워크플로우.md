# 네트워크 플로우

## 포드풀커슨 방법

https://www.acmicpc.net/problem/6086

함수 G는 residual network(잔여 네트워크, capacity-flow인 잔여 용량으로 이루어진 그래프)를 나타냄.

getp 함수에서 p에 증강경로를 구하고, 증강경로의 존재여부를 반환. 증강경로가 존재한다면 증강경로에 그 것의 flow를 갱신시켜주기.

#### dfs naive 구현

```c++
#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int chk[63],flag;
bool getp(vector<vector<int>> &G, vector<int>&p, int cur, int t){
    if(cur==t) {
        p.push_back(cur);
        return true;
    }
    chk[cur]=1;
    for(int nxt=0;nxt<60;nxt++)if(!chk[nxt]&&G[cur][nxt]>0){
        if(getp(G,p,nxt,t)) {
            p.push_back(cur);
            return true;
        }
    }
    return false;
}
int ford_fulkerson(vector<vector<int>> &G, int s, int t){ //잔여네트워크, 시작점, 도착점
    //1. 임의의 잔여경로 p 찾기 & 그 경로의 min capacity 찾기(cfp)
    //2. 해당 경로에 -cfp 갱신, ans+=cfp
    vector<int> p;
    int cfp,ans=0,i;
    while(getp(G, p,s,t)){
        cfp = inf;
        reverse(all(p));
        for(i=0;i+1<p.size();i++) cfp = min(cfp,G[p[i]][p[i+1]]);
        for(i=0;i+1<p.size();i++) {
            G[p[i]][p[i+1]]-=cfp;
            G[p[i+1]][p[i]]+=cfp;
        }
        ans+=cfp;
        p.clear();
        memset(chk,0,sizeof(chk));
    }
    return ans;
}
int main()
{
    int i,j,c;
    char a,b;
    vector<vector<int>> cf = vector<vector<int>>(60,vector<int>(60)); //잔여네트워크
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
        cf[a-'A'][b-'A']+=c;
        cf[b-'A'][a-'A']+=c;
    }
    cout<<ford_fulkerson(cf,0,'Z'-'A');
    return 0;
}

```



#### 에드몬드카프 알고리즘 w/ 인접 행렬

```c++
#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
vector<int> getp(vector<vector<int>> &G, int s, int t){
    int cur,nxt;
    queue<int> q;
    vector<int> prev(60,-1);
    vector<int> ret;
    q.push(s);
    prev[s]=inf;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(nxt=0;nxt<60;nxt++){
            if(G[cur][nxt]>0 && prev[nxt]<0){
                q.push(nxt);
                prev[nxt]=cur;
            }
        }
    }
    if(prev[t]<0) return {};
    cur = t;
    while(cur!=inf) {
        ret.push_back(cur);
        cur = prev[cur];
    }
    reverse(all(ret));
    return ret;
}
int ford_fulkerson(vector<vector<int>> &G, int s, int t){ //잔여네트워크, 시작점, 도착점
    //1. 임의의 잔여경로 p 찾기 & 그 경로의 min capacity 찾기(cfp)
    //2. 해당 경로에 -cfp 갱신, ans+=cfp
    vector<int> p;
    int cfp,ans=0,i;
    while(!(p = getp(G, s, t)).empty()){
        cfp = inf;
        for(i=0;i+1<p.size();i++) cfp = min(cfp,G[p[i]][p[i+1]]);
        for(i=0;i+1<p.size();i++) {
            G[p[i]][p[i+1]]-=cfp;
            G[p[i+1]][p[i]]+=cfp;
        }
        ans+=cfp;
    }
    return ans;
}
int main()
{
    int i,j,c;
    char a,b;
    vector<vector<int>> cf = vector<vector<int>>(60,vector<int>(60)); //잔여네트워크
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
        cf[a-'A'][b-'A']+=c;
        cf[b-'A'][a-'A']+=c;
    }
    cout<<ford_fulkerson(cf,0,'Z'-'A');
    return 0;
}

```



#### 에드몬드카프 알고리즘 w/ 인접리스트

```c++
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const int inf = 1e9;
int n,m,k;
struct Edge{
    int target, capacity, flow;
    Edge* rev;
    Edge(int a, int b, int c):target(a), capacity(b), flow(c){}
    int cf(){return capacity-flow;}
    void push(int amt){
        flow+=amt;
        rev->capacity+=amt;
    }
};
vector<Edge*> G[2005];
void addEdge(int u, int v, int c){
    Edge *uv = new Edge(v,c,0),*vu= new Edge(u,0,0);
    uv->rev = vu; vu->rev = uv;
    G[u].push_back(uv); G[v].push_back(vu);
}
bool getp(vector<Edge*> &p, int s,int t){
    vector<Edge*> prev(2005,nullptr);
    queue<int> q;
    q.push(s);
    prev[s]=new Edge(s, inf, 0);
    while(!q.empty() && prev[t]==nullptr){
        int cur = q.front(); q.pop();
        for(auto& nxt : G[cur])if(prev[nxt->target]==nullptr && nxt->cf()){
            q.push(nxt->target);
            prev[nxt->target]=nxt;
        }
    }
    if(prev[t]==nullptr) return false;
    int cur = t;
    while(cur!=s){
        p.push_back(prev[cur]);
        cur = prev[cur]->rev->target;
    }
    reverse(all(p));
    return true;
}
int maxflow(int s, int t){
    //1. 증강경로 찾기
    //2. 증강경로의 flow를 찾고 경로에 push해주기
    vector<Edge*> p;
    int ans=0;
    while(getp(p,s,t)){
        int minflow = inf;
        for(auto &E : p) minflow = min(minflow, E->cf());
        for(auto &E : p) E->push(minflow);
        ans+=minflow;
        p.clear();
    }
    return ans;
}
```



## 이분 매칭

이분 그래프에서 매칭의 개수  = {s,L},{R,t}의 flow

#### 에드몬드 카프 알고리즘 w/ 인접 리스트

```C++
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ed[1003],c(1003);
int rev[1003];
bool dfs(int l){
    for(int r : ed[l]){
        if(c[r]) continue;
        c[r]=1;
        if(rev[r]==0 || dfs(rev[r])){
            rev[r]=l;
            return true;
        }
    }
    return false;
}
```

## MCMF(Minmum Cost Maximum Flow)

유량과 비용이 있는 그래프에서 최소비용으로 최대 유량을 구하는 문제

최소 비용 구하기 -> 최단 거리 구하기 -> 벨만포드 / SPFA(비용 음수 가능)
