#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,k;
vector<int> arr;
vector<int> ind[203];
vector<pii> v;
int d[203][203],chk[203][203];
int f(int s, int e){
	if(s==e) return 0;
	if(chk[s][e]) return d[s][e];
	chk[s][e]=1;
	if(arr[s]==arr[e]) d[s][e]=f(s+1,e-1)+1;
	d[s][e]=max({d[s][e],f(s+1,e),f(s,e-1)});
	for(int i=s+1;i<e;i++) d[s][e]=max(d[s][e],f(s,i)+f(i,e));
	return d[s][e];
}
int main()
{
	int i;
    cin>>n>>k;
    arr.resize(n);
    for(i=0;i<n;i++){
    	cin>>arr[i];
    }
    arr.erase(unique(all(arr)),arr.end());
    n=arr.size();
    cout<<n-1-f(0,n-1);
    return 0;
}
