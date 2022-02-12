#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,m,dlim;
struct student{
	int sz,d;
	vector<int> v;
	bool operator<(const student &r)const{
		return d<r.d;
	}
};
vector<student> A;
vector<int> inp;
int cnt[31],tot,ans;
int main()
{
	int num,i,j;
    cin>>n>>m>>dlim;
    A.resize(n);
    for(i=0;i<n;i++){
    	inp.clear();
    	cin>>A[i].sz>>A[i].d;
    	for(j=0;j<A[i].sz;j++){
    		cin>>num;
    		A[i].v.push_back(num);
    	}
    }
    sort(all(A));
    int l=0,r=0,all,E,some;
    while(r<A.size()){
    	while(r<A.size() && A[r].d-A[l].d<=dlim){
    		tot+=A[r].sz;
    		all=some=0;
    		for(int num : A[r].v){
    			cnt[num]++;
    		}
    		for(int i=1;i<=m;i++){
    			if(cnt[i]==r-l+1) all++;
    			if(cnt[i]) some++;
    		}
    		E=(some-all)*(r-l+1);
    		ans=max(E,ans);
    		r++;
    	}
    	for(int num : A[l].v) cnt[num]--;
    	l++;
    }
    cout<<ans;
    return 0;
}
