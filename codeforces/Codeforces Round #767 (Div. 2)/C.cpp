#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n;
int cnt[200003];
int premex,chk[200003],nxtmex;
vector<int> v,ans;
int main()
{
    int tc,i,mex,num;
    cin>>tc;
    while(tc--){
    	cin>>n;
    	for(i=1;i<=n;i++){
    		cin>>num;
    		cnt[num]++;
    		v.push_back(num);
    	}
    	for(mex=0;cnt[mex];mex++);
        nxtmex=mex;
	    for(int num : v){

	    	cnt[num]--;
	    	if(cnt[num]==0) nxtmex=min(nxtmex,num);

	    	if(chk[num]==ans.size() && num<mex){
	    		chk[num]=ans.size()+1;
	    		premex++;
	    	}
	    	if(premex==mex){
	    		premex=0;
	    		ans.push_back(mex);
	    		mex=nxtmex;
	    	}
	    }
	    cout<<ans.size()<<'\n';
	    for(int num : ans) cout<<num<<' ';
	    cout<<'\n';

    	v.clear();
    	memset(cnt,0,4*(n+1));
    	memset(chk,0,4*(n+1));
    	ans.clear();
    }

    return 0;
}
