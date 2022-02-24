#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define nm (ns+ne)/2
using ll = long long;
using pii = pair<int, int>;
typedef tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,k;
int t[400003];
ordered_set s;
int main()
{
	int tc,i,j,x,nx;
    //sync()
    cin>>n>>k;
    for(i=1;i<=n;i++)s.insert(i);
    x=n-1;
    cout<<'<';
    for(;n>=1;n--){
    	nx=(x+k)%n;
    	ordered_set::iterator t = s.find_by_order(nx);
    	cout<<*t;
    	if(n-1)cout<<", ";
        s.erase(t);
        x=(nx-1+n)%n;
        if(nx<x) x--;
    }
    cout<<'>';
    return 0;
}
