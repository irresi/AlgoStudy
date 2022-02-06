#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m;
vector<int> t[400003];
int arr[100003];
void upd(int nn, int ns, int ne){
	for(int i=ns;i<=ne;i++) t[nn].push_back(arr[i]);
	if(ns==ne) return;
	upd(nn*2,ns,(ns+ne)/2+1); upd(nn*2,(ns+ne)/2+1,ne);
}
int query(int nn, int ns, int ne, int s, int e, int val){
	if(e<ns && ne<s) return 0;
	else if(s<=ns && ne<=e) return upper_bound(all(t[nn]),val)-t[nn].begin();
	else return query(nn*2,ns,(ns+ne)/2,s,e,val)+query(nn*2+1,(ns+ne)/2+1,ne,s,e,val);
}
int main()
{
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		arr[i]=i;
 	}
 	upd(1,1,n);
 	for(int i=1;i<=n*4;i++) sort(all(t[i]));
 	int a,b,c,s,e,mid;
 	for(int i=1;i<=m;i++){
 		cin>>a>>b>>c;
 		s=-1e9,e=1e9;
 		while(s<e){
 			mid=(s+e)/2;
 			if(query(1,1,n,a,b,mid)<c) s=mid+1;
 			else e=mid;
 		}
 		cout<<s<<"\n";
 	}
    return 0;
}
