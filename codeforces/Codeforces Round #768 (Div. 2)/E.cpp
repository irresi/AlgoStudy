#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,arr[200003],ans;
int s[200003],e[200003];
vector<pii> v;
int main()
{
	int i,tc;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>arr[i];
		if(!s[arr[i]]) s[arr[i]]=i;
		else ans+=(s[arr[i]]!=e[arr[i]]);
		e[arr[i]]=i;
	}
	for(i=1;i<=n;i++)if(s[i]){
		v.push_back({s[i],e[i]});
	}
	sort(all(v));
	int maxb=0,topl=0;
	for(auto [a,b] : v){
		if(maxb<a){
			maxb=b;
		}
		else{
			if(maxb<b){
				ans++;
				maxb=b;
			}
			else {
                ans+=topl;    
			}
		}
		topl=1+(a!=b);
		
	}
	cout<<ans;

    return 0;
}
//Greedy하게 풀었는데 틀렸음. 그리디 전략이 성립하지 않는 듯?