#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,tc;
long long ans;
vector<pii> A;
vector<int> ylib;
int yrenum(int x){ return lower_bound(all(ylib),x)-ylib.begin()+1;}
struct BIT{
	int t[100003];
	BIT(){memset(t,0,4*(n+1));}
	void upd(int x){for(;x<=n;x+=x&-x) t[x]++;}
	int get(int x){int ret=0;for(;x;x-=x&-x) ret+=t[x]; return ret;}
	int get(int a, int b){return get(b)-get(a-1);}
};
int main()
{
    int i,j,x,y;
    sync()
    cin>>tc;
    while(tc--){
    	ans=0;
    	ylib.clear();
    	A.clear();
    	cin>>n;
    	BIT T;
    	for(i=1;i<=n;i++){
    		cin>>x>>y;
    		ylib.push_back(y);
    		A.push_back({x,y});
    	}
    	sort(all(ylib));
    	ylib.erase(unique(all(ylib)),ylib.end());
    	sort(all(A),[&](pii A, pii B){
    		return A.first<B.first ||(A.first==B.first && A.second>B.second);
    	});
    	for(auto [x,y]: A){
    		y=yrenum(y);
    		ans+=T.get(y,n);
    		T.upd(y);
    	}
    	cout<<ans<<'\n';
    }
    return 0;
}
// ans가 long long 범위인데 int로 써서 틀렸었음.
// 변수 범위 잘 확인하자.