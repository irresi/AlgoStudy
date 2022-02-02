#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n;
struct Segtree{ //점 갱신 범위 쿼리
	int t[800003],n;
	Segtree(vector<int> v){
		n=1;
		while(n<v.size()) n<<=1;
		for(int i=0;i<v.size();i++) t[n+i]=v[i];
		for(int i=n-1;i>=0;i--) t[i]=__gcd(t[i<<1],t[i<<1|1]);
	}
	int query(int s, int e){ //[s,e)
		int ret=0;
		for(s+=n,e+=n;s<e;s>>=1,e>>=1){
			if(s&1)
                if(!ret) ret=t[s++];
                else ret=__gcd(ret,t[s++]);
			if(e&1)
                if(!ret) ret=t[--e];
                else ret=__gcd(ret,t[--e]);
		}
		return ret;
	}
};
vector<array<int,2>> v;
vector<int> ans;
int main()
{
	int i,j,num,a,flag;
    cin>>n;
	vector<int> A(n);
    for(i=0;i<n;i++) cin>>A[i];
    Segtree S(A);
    for(int l=0;l<n;l++){
    	int s=l,e=n-1,mid;
    	while(s<e){ //[s,e]
    		mid=s+e+1>>1;
    		if(S.query(l,mid+1)>=mid-l+1) s=mid;
    		else e=mid-1;
    	}
    	if(S.query(l,s+1)==s-l+1) v.push_back({l,s});
    }
    sort(all(v),[&](auto L, auto R){
    	return L[1]<R[1];
    });
    int maxr=-1;
    for(auto [l,r] : v) {
        if(maxr<l){
            maxr=r;
            ans.push_back(maxr);
        }
    }
    reverse(all(ans));
    for(i=0,num=0;i<n;i++){
        if(!ans.empty() && ans.back()<=i) {
            ans.pop_back();
            num++;
        }
        cout<<num<<' ';
    }
    return 0;
}
