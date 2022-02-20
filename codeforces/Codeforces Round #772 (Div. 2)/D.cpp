#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod=1e9+7;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,p,arr[200003],fib[200003]={1,1},sum[200003]={1,2},ans;
set<int> lib;
int main()
{
	int tc,i,j;
	long long num;
    sync()
    for(i=2;i<=200000;i++){
    	fib[i]=(fib[i-1]+fib[i-2])%mod;
    	sum[i]=(sum[i-1]+fib[i])%mod;
    }
    cin>>n>>p;
    queue<long long> q;
    for(i=1;i<=n;i++){
    	cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    for(i=1;i<=n;i++){
    	num = arr[i];
    	while(num){
    		if(lib.find(num)!=lib.end()) break;
    		if(num&1) num=(num-1)/2;
    		else if(num%4==0) num/=4;
    		else{
                num=0;
                break;
    		}
    	}
    	if(num) continue;
    	lib.insert(arr[i]);
    	num = 31-__builtin_clz(arr[i]);
    	if(p-num-1<0) continue;
    	ans+=sum[p-num-1];
    	ans%=mod;
    }
    cout<<ans;
    return 0;
}
