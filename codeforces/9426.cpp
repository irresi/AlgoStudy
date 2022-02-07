#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
const int mx=65536;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,k;
int t[mx*4],arr[250003];
long long ans;
void upd(int idx, int val,int nn=1, int ns=0, int ne=65535){
	if(idx<ns || ne<idx) return;
	if(ns<=idx && idx<=ne) t[nn]+=val;
	if(ns==ne) return;
	upd(idx,val,nn*2,ns,(ns+ne)/2); upd(idx,val,nn*2+1,(ns+ne)/2+1,ne);
}
int query(int x, int nn=1, int ns=0, int ne=65535){
	if(ns==ne) return ns;
	if(t[nn*2]<=x) return query(x-t[nn*2],nn*2+1,(ns+ne)/2+1,ne);
	return query(x, nn*2,ns,(ns+ne)/2);
}
int main()
{
	int i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(i=1;i<k;i++){
		upd(arr[i],1);
	}
	for(i=k;i<=n;i++){
		upd(arr[i],1);
		if(i!=k) upd(arr[i-k],-1);
		ans+=query((k+1)/2-1);
	}
	cout<<ans;
    return 0;
}
//세그먼트 트리의 쿼리를 합을 구하는 것 같은 고정적인 구조로 생각하지 말자. 좀 더 폭 넓게 생각.