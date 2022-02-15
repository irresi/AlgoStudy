#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n;
vector<int> ed[100003];
int toleaf[100003],maxlength[100003];
void treegen(int cur, int prev){
	int mx1=0,mx2=0;
	for(int nxt : ed[cur]) if(nxt!=prev){
		treegen(nxt,cur);
		if(toleaf[nxt]>mx1) mx2=mx1,mx1=toleaf[nxt];
		else if(toleaf[nxt]>mx2) mx2=toleaf[nxt];
	}
	maxlength[cur] = mx1+mx2+(mx1>0)+(mx2>0);
	toleaf[cur] = mx1+1;
	return;
}
int main()
{
	int i,j,num;
    cin>>n;
    for(i=1;i<=n;i++){
    	while(1){
    		cin>>num;
    		if(num<0) break;
    		ed[i].push_back(num);
    		ed[num].push_back(i);
    	}
    }
    treegen(1,0);
    cout<<maxlength[1];
    return 0;
}
//dp를 이용