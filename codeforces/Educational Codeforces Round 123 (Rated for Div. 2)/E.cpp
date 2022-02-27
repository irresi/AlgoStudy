#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
ll n,m,ans;
string str;
int main()
{
	ll tc,i,j,r,c,er,ec;
    sync()
    cin>>tc;
    while(tc--){
    	cin>>n>>str;
    	er=ec=1;
    	for(char ch : str){
    		if(ch=='R') ec++;
    		else er++;
    	}
        if(er==1 || ec==1){
            cout<<n<<'\n';
            continue;
        }
    	reverse(all(str));
    	str.pop_back();
    	ans=(n-er+1)*(n-ec+1);
    	c=ec; r=er;
    	for(char ch : str){
    		if(ch=='R'){
    			c--;
    			if(r==1) ans++;
    			else ans+=(n-r+1)-(er-r);
    		}
    		else{
    			r--;
    			if(c==1) ans++;
    			else ans+=(n-c+1)-(ec-c);
    		}
    	}
    	cout<<ans+1<<'\n';
    }
    return 0;
}
