#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use printf, scanf, puts
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second

const int inf=(int)1e9+7;
const ll linf=(ll)1e18+3;

int tc,n,m;

int main()
{
    int i,j,tcnum;
	sync();
	string a,b;
    cin>>tc;
    for(tcnum=1;tcnum<=tc;tcnum++){
        cin>>n>>m;
        cin>>a;
        b=a;
        reverse(all(b));
        if(a!=b && m!=0) cout<<"2\n";
        else cout<<"1\n";
    }
    return 0;
}
