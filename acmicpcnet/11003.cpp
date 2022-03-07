#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} 
int n,m,arr[5000003];
deque<pair<int,int>> dq; //값, idx
int main()
{
	int tc,i,j;
    sync()
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	cin>>arr[i];
    	if(i>m) while(dq.front().second<=i-m) dq.pop_front();
    	if(dq.empty() || arr[i]<dq.front().first) dq.push_front({arr[i],i});
    	else{
    		while(dq.back().first<=arr[i])	dq.pop_back();
    		dq.push_back({arr[i],i});
    	}
    	cout<<dq.front().first<<' ';
    }
    return 0;
}
