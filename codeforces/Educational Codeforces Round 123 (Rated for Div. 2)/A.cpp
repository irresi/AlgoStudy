#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m;
int cnt[256];
int main()
{
	int tc,i,j;
    sync()
    cin>>tc;
	while(tc--){
		string str;
		cin>>str;
		int flag=0;
		for(char ch : str){
			if('a'<=ch && ch <='z')cnt[ch-'a']++;
			else{
				if(cnt[ch-'a']<=0) flag=1;
				cnt[ch-'a']++;
			}
		}
		if(!flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}
