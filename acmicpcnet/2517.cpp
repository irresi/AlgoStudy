#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n;
int t[2000003];
void update(int x){for(;x<=n;x+=x&-x) t[x]++;}
int query(int x){int ret=0;for(;x;x-=x&-x) ret+=t[x]; return ret;}
int query(int a, int b){return query(b)-query(a-1);}
vector<int> v,lib;
int renum(int num){return lower_bound(all(lib),num)-lib.begin()+1;}
int main()
{
	int i,num;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>num;
    	v.push_back(num);
    	lib.push_back(num);
    }
    sort(all(lib));
    for(int num : v){
    	num = renum(num);
    	cout<<query(num+1,n)+1<<'\n';
    	update(num);
    }
    return 0;
}
