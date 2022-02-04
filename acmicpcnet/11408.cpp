//https://www.crocus.co.kr/1090
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end();
const int inf=1e9;
int n,m;
int cf[805][805],d[805][805]; //(i,j)의 잔여용량, cost(distance)
vector<int> ed[805]; //연결된 노드 인접리스트 
int S,T;
int main(){
    int i,idx,cost,sz;
    cin>>n>>m;
    S=n+m+1; T=n+m+2;
    //그래프 연결 
    for(i=1;i<=n;i++){
        cin>>sz;
        ed[S].push_back(i);
        ed[i].push_back(S);
        cf[S][i]=1;
        while(sz--){
            cin>>idx>>cost;
            ed[i].push_back(n+idx);
            ed[n+idx].push_back(i);
            d[i][n+idx]=cost;
            d[n+idx][i]=-cost;
            cf[i][n+idx]=1;
        }
    }
    for(i=n+1;i<=n+m;i++){
        cf[i][T]=1;
        ed[i].push_back(T);
        ed[T].push_back(i);
    }
    
    int cnt=0,sum=0;
    while(1){
        vector<int> prev(805,-1),dist(805,inf);
        vector<bool> inQ(805,false);
        queue<int> q;
        dist[S]=0; inQ[S]=true;
        q.push(S);
        while(!q.empty()){ //spfa방식으로 증강경로 구하기
            int cur = q.front(); q.pop(); inQ[cur] = false; //Q처리
            for(int nxt : ed[cur]){
                if(cf[cur][nxt]>0 && dist[nxt]>dist[cur]+d[cur][nxt]){ //잔여용량이 있고 거리가 갱신될 수 있다면 
                    dist[nxt] = dist[cur]+d[cur][nxt]; //거리 갱신 
                    prev[nxt] = cur; //전 노드 체크
                    if(!inQ[nxt]){ //Q중복 삽입 처리
                        inQ[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        if(prev[T]==-1) break;
        int flow = inf;
        for(i=T;i!=S;i=prev[i]){
            flow = min(flow,cf[prev[i]][i]);
        }
        for(i=T;i!=S;i=prev[i]){
            cf[prev[i]][i]-=flow;
            cf[i][prev[i]]+=flow;
            sum+=flow*d[prev[i]][i]; //flow*(flow당 비용)
        }
        cnt+=flow;
    }
    cout<<cnt<<'\n'<<sum;
    return 0;
}
