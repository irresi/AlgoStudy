#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n;
string p;
deque<int> q;
int main()
{
	char _;
	int tc,num,rev=0,error=0,i,j;
    cin>>tc;
    while(tc--){
    	rev=0;
    	q.clear();
    	cin>>p>>n;
    	scanf(" %c",&_);
    	for(i=1;i<=n;i++) {
    		scanf("%d",&num);
    		if(i!=n) scanf("%c",&_);
    		q.push_back(num);
    	}
    	scanf("%c",&_);
    	error=0;
    	for(char ch : p){
    		if(ch=='R') rev=!rev;
    		else if(ch=='D' && !q.empty()){
    			if(!rev) q.pop_front();
    			else q.pop_back();
    		}
    		else{
    			error=1;
    			break;
    		}
    	}
    	if(error) puts("error");
    	else {
    		printf("[");
    		while(!q.empty()){
    			if(!rev) {
    				cout<<q.front();
    				q.pop_front();
    			}
    			else{
    				cout<<q.back();
    				q.pop_back();
    			}
    			if(!q.empty()) cout<<',';
    		}
    		cout<<"]\n";
    	}
    }
    return 0;
}
