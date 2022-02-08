#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,k,A[200003];
vector<int> lib;
int main()
{
    int tc,x,y,ansi,i;
    cin>>tc;
    while(tc--){
    	cin>>n>>k;
    	lib={0};
    	x=inf; y=-inf;
    	for(i=1;i<=n;i++){
    		cin>>A[i];
    		lib.push_back(A[i]);
    		x=min(A[i],x);
    		y=max(A[i],y);
    	}
    	int toera=(n-k)/2;
    	sort(1+all(lib));
    	for(i=1;i<=toera+1;i++){
    		if(lib[i+n-toera-1]-lib[i]<y-x){
    			y=lib[i+n-toera-1]; x=lib[i]; ansi=i;
    		}
    	}
    	cout<<x<<' '<<y<<'\n';
    	int cnt=0,prev=1;
    	for(i=1;i<=n;i++){
            if(k==1) break;
    		if(x<=A[i] && A[i]<=y) cnt++;
    		else cnt--;

    		if(cnt>0){
    			cout<<prev<<' '<<i<<'\n';
    			prev=i+1;
    			cnt=0;
    			k--;
    		}
    	}
    	cout<<prev<<' '<<n<<'\n';
    }
    return 0;
}
