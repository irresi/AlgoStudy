#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,tc;
int a[103],b[103];
int main()
{
	int i;
	sync()
    cin>>tc;
    while(tc--){
    	cin>>n;
    	int m1,m2;
    	m1=m2=0;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    	}
    	for(i=1;i<=n;i++){
    		cin>>b[i];
    		m1=max(m1,min(a[i],b[i]));
    		m2=max(m2,max(a[i],b[i]));
    	}
    	cout<<m1*m2<<'\n';
    }
    return 0;
}
