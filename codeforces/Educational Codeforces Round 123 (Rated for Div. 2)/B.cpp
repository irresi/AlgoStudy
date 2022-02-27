#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,cnt;
int chk[53];
vector<int> ans;
void f(int lv){
	if(lv==n){
		for(int num : ans) cout<<num<<" ";
		cout<<'\n';
		cnt++;
		if(cnt==n) return;
	}
	for(int i=1;i<=n;i++){
		if((lv<2 ||ans.back()+ans[ans.size()-2]!=i) && !chk[i]){
			chk[i]=1;
			ans.push_back(i);
			f(lv+1);
			if(cnt==n) return;
			ans.pop_back();
			chk[i]=0;
		}
	}
}
int main()
{
	int tc,i,j;
    sync()
    cin>>tc;
    while(tc--){
    	cnt=0;
    	cin>>n;
    	f(0);
    }
    return 0;
}
