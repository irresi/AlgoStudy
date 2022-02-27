#include <bits/stdc++.h>
using namespace std;
#define R first
#define C second
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
const int mod=998244353;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,k,q,cols[200003],rows[200003],ans,rowcnt,colcnt;
long long pr;
vector<pii> v;
int main()
{
	int tc,i,j,r,c;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n>>m>>k>>q;
    	fill(cols,cols+1+m,0);
    	fill(rows,rows+1+n,0);
    	v.clear();
    	for(i=1;i<=q;i++){
    		cin>>r>>c;
    		v.emplace_back(r,c);
    	}
    	
    	
    	reverse(all(v));
    	ans=rowcnt=colcnt=0;
    	for(auto [r,c] : v){
    		if((rows[r] || colcnt-cols[c]==m-1) && (cols[c] || rowcnt-rows[r]==n-1) &&(cols[c] || rows[r])) continue;
    		if(!rows[r])rows[r]=1,rowcnt++;
    		if(!cols[c])cols[c]=1,colcnt++;
    		ans++;
    	}
    	pr=1;
    	for(i=0;i<ans;i++) pr=pr*k%mod;
    	cout<<pr<<'\n';
    }
    return 0;
}
