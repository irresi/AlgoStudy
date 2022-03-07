#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll=long long;
struct line{
    ll x,sy,ey,t;
    bool operator<(const line &r)const{
        return x<r.x;
    }
};
vector<ll> lib;
struct segtree{
    ll t[1600003],cnt[1600003];
    void update(int qs, int qe, int qv, int nn=1, int ns=1, int ne=lib.size()-1){
        if(qe<ns || ne<qs) return;
        if(qs<=ns && ne<=qe) cnt[nn]+=qv;
        else{
            update(qs,qe,qv,nn*2,ns,(ns+ne)/2);
            update(qs,qe,qv,nn*2+1,(ns+ne)/2+1,ne);
        }
        t[nn]=0;
        if(cnt[nn]>0) t[nn]=lib[ne]-lib[ns-1];
        else if(ns!=ne) t[nn]=t[nn*2]+t[nn*2+1];
        return;
    }
}T;
int n;
ll ans;
vector<line> v;
int renum(ll num) {return lower_bound(all(lib),num)-lib.begin();}
int main(){
    int i,j,sx,ex,sy,ey;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>sx>>ex>>sy>>ey;
        v.push_back({sx,sy,ey,1});
        v.push_back({ex,sy,ey,-1});
        lib.push_back(sy);
        lib.push_back(ey);
    }
    sort(all(v));
    sort(all(lib));
    lib.erase(unique(all(lib)),lib.end());
    for(i=0;i<v.size();i++){
        if(i) ans+=(v[i].x-v[i-1].x)*T.t[1];
        T.update(renum(v[i].sy)+1,renum(v[i].ey),v[i].t);
    }
    cout<<ans;
    return 0;
}
