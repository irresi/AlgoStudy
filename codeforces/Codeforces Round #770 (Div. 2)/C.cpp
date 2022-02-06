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
    cin>>tc;
    for(tcnum=1;tcnum<=tc;tcnum++){
        cin>>n>>m;
        if((n&1) && m!=1) cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(i=1;i<=n;i++){
                for(j=0;j<m;j++){
                    cout<<i+j*n<<' ';
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}