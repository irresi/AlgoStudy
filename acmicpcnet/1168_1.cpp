#include <bits/stdc++.h>
using namespace std;
#define nm (ns+ne)/2
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,k,t[400003];
void update(int x, int val, int nn=1, int ns=1, int ne=n){ //x위치가 포함되는 노드에 val만큼 바꾸기
	if(x<ns || ne<x) return;
	t[nn]+=val;
	if(ns==ne)return;
	update(x,val,nn*2,ns,nm); update(x,val,nn*2+1,nm+1,ne);
}
int query(int x, int nn=1, int ns=1, int ne=n){ //합이 x가 되는 곳의 인덱스 반환
	if(ns==ne) return ns;
	if(x<=t[nn*2]) return query(x,nn*2,ns,nm);
	else return query(x-t[nn*2],nn*2+1,nm+1,ne);
}
int mod(int x, int n){
    return (x-1)%n+1;
}
int main()
{
	int tc,i,j,nx,era;
    sync()
    cin>>n>>k;
    for(i=1;i<=n;i++) update(i,1);
    cout<<'<';
    for(int x=n,i=n;i>=1;i--){
        nx=mod(x+k,i);
        cout<<(era=query(nx))<<((i==1)?">":", ");
        update(era,-1);
        x=mod(nx-1,i);
        if(nx<=x) x--;
    }
    return 0;
}
//segtree구현