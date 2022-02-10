#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,flag;
multiset<string> lib;
vector<string> inp,rev;
string t;
int main()
{
    int tc,i;
    cin>>tc;
    while(tc--){
    	lib.clear();
        flag=0;
    	cin>>n;
    	inp.assign(n+1,"");
    	rev.assign(n+1,"");
    	for(i=1;i<=n;i++){
    		cin>>inp[i];
    		lib.insert(inp[i]);
    		rev[n-i+1]=inp[i];
    		reverse(all(rev[n-i+1]));
    		if(inp[i].size()==1) flag=1;
    	}
    	if(flag){
    		cout<<"YES\n";
    		continue;
    	}
    	for(i=1;i<=n;i++){
    		if(lib.find(rev[i])!=lib.end()) flag=1;
    		else if(rev[i].size()==2){
    			auto si = lib.lower_bound(rev[i]);
    			if(si==lib.end()) continue;
    			else t=*si;
    			if(t[0]==rev[i][0] && t[1]==rev[i][1]) flag=1;
    		}
    		else if(rev[i].size()==3){
    			if(lib.find(rev[i].substr(0,2))!=lib.end()) flag=1;
    		}
    		if(flag) break;
    		lib.erase(inp[n-i+1]);
    	}
    	if(flag) cout<<"YES\n";
    	else cout<<"NO\n";
    }
    return 0;
}
