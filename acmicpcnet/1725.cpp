#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
using pll = pair<long long,long long>;
vector<pll> v;
set<int> lib;
int n;
long long ans;
int main(){
    int i,j,a;
    cin>>n;
    lib.insert(0);
    lib.insert(n+1);
    for(i=1;i<=n;i++){
        cin>>a;
        v.push_back({a,i});
    }
    sort(all(v));
    set<int>::iterator vi,vj;
    for(auto [val,idx] : v){
        vj=lib.lower_bound(idx);
        vi=vj; --vi;
        ans=max(ans,(*vj-*vi-1)*val);
        lib.insert(idx);
    }
    cout<<ans;
}
