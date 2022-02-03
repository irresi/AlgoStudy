#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n;
int tc;
int main()
{
	int i,j,mb;
    cin>>tc;
    while(tc--){
    	cin>>n;
    	for(mb=1;mb<n;mb<<=1); mb>>=1;
    	for(i=mb-1;i>=1;i--) if(i!=n-1-mb)cout<<i<<" ";
    	cout<<"0 ";
    	for(i=mb;i<n;i++) cout<<i<<' ';
    	if(n-1-mb)cout<<n-1-mb;
    	cout<<"\n";
    }
    return 0;
}
