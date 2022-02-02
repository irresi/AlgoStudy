#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use 
int n;

int main()
{
    int tc,i;
    string str;
    cin>>tc;
    while(tc--){
    	cin>>n>>str;
    	if(n==1 ||(str=="10" ||str=="01")) cout<<"YES\n";
    	else cout<<"NO\n";
    }
    return 0;
}
