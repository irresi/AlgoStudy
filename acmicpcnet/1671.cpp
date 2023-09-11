#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);}

int n,m,chk[53],rev[53],ans;
vector<array<int,3>> stat;
vector<int> ed[53];
bool f(int l){
	for(int r : ed[l]){
		if(chk[r]) continue;
		chk[r]=1;
		if(!rev[r] || f(rev[r])){
			rev[r]=l;
			return true;
		}
	}
	return false;
}
int main()
{
	int tc,i,j,a,b,c;
    sync()
    cin>>n;
    stat.push_back({0,0,0});
    for(i=1;i<=n;i++){
    	cin>>a>>b>>c;
    	stat.push_back({a,b,c});
    }
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++)if(i!=j){
    		if(stat[i]==stat[j]){
    			if(i>j) ed[i].push_back(j);
    		}
    		else if(stat[i][0]>=stat[j][0] && stat[i][1]>=stat[j][1] && stat[i][2]>=stat[j][2]){
    			ed[i].push_back(j);
    		}
    	}
    }
    for(i=2;i<=2*n+1;i++){
    	memset(chk,0,sizeof(chk));
    	ans+=f(i/2);
    }
    cout<<n-ans;
    return 0;
}
