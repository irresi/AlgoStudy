#include <bits/stdc++.h>
using namespace std;
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
int p[10003];
set<int> lib;
int main()
{
	int a,b,i,j,tc;
	sync()
	cin>>tc;
	while(tc--){
        cin>>n;
        for(i=1;i<n;i++){
            cin>>a>>b;
            p[b]=a;
        }
        lib.clear();
        cin>>a>>b;
        while(true){
            if(a==b || (a!=0 && lib.find(a)!=lib.end())){
                cout<<a<<'\n'; break;
            }
            if(b!=0 && lib.find(b)!=lib.end()){
                cout<<b<<'\n'; break;
            }
            lib.insert(a);
            lib.insert(b);
            a=p[a]; b=p[b];
        }
	}
    return 0;
}
