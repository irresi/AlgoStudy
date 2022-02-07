#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
const int msz=1e5+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
#define nm (ns+ne)/2
ll n,m,A[msz],t[msz*4];
void upd(ll qs, ll qe, ll val, ll nn=1, ll ns=1, ll ne=n){
	if(ne<qs || qe<ns) return;
	if(qs<=ns && ne<=qe) {
        t[nn]+=val;
        return;
	}
	upd(qs,qe,val,nn*2,ns,nm); upd(qs,qe,val,nn*2+1,nm+1,ne);
}
ll query(ll x, ll nn=1,ll ns=1, ll ne=n){
	if(x<ns || ne<x) return 0;
	if(ns==ne) return t[nn];
	return query(x,nn*2,ns,nm)+query(x,nn*2+1,nm+1,ne)+t[nn];
}
int main()
{
	ll a,b,c,d,i,j;
	sync()
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>A[i];
    	upd(i,i,A[i]);
    }
    cin>>m;
    for(i=1;i<=m;i++){
    	cin>>a;
    	if(a==1){
    		cin>>b>>c>>d;
    		upd(b,c,d);
    	}
    	else{
    		cin>>b;
    		cout<<query(b)<<'\n';
    	}
    }
    return 0;
}
//upd에서는 업데이트할 구간을 쪼개어서 구간에 val를 더한다.
//query에서는 인덱스 x가 포함되는 모든 구간의 값을 더해서 리턴한다.