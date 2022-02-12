#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n,K;
char str[53][53];
int arr[53][53],ans=inf;
vector<int> lib;
pii P;
vector<pii> w={{0,1},{1,0},{0,-1},{-1,0}};
bool pos(int s, int e){
	if(arr[P.first][P.second]<s || e<arr[P.first][P.second]) return false;
	vector<vector<int>> chk(53,vector<int>(53,0));
	queue<pii> q;
	q.push(P);
	chk[P.first][P.second]=1;
	int cnt=0,pr,pc;
	while(!q.empty() && cnt<K){
		auto [r,c] = q.front(); q.pop();
		if(str[r][c]=='K') cnt++;
		for(pr=-1;pr<=1;pr++){
			for(pc=-1;pc<=1;pc++)if(!chk[r+pr][c+pc]){
				q.push({r+pr,c+pc});
				chk[r+pr][c+pc]=1;
			}
		}
	}
	return cnt==K;
}
int main()
{
	int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>str[i]+1;
    }
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		cin>>arr[i][j];
    		if(arr[i][j]=='P') P={i,j};
    		else if(arr[i][j]=='K') K++;
    		lib.emplace_back(arr[i][j]);
    	}
    }
    sort(all(lib));
    lib.erase(unique(all(lib)),lib.end());
    int l=0,r=0;
    while(r<lib.size()){
    	while(1){
    		if(pos(lib[l],lib[r])){
    			ans=min(ans,lib[r]-lib[l]);
    			l++;
    		}
    		else break;
    	}
    	r++;
    }
    cout<<ans;
    return 0;
}
