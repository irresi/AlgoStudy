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

int tc,n,m,ans=1e9;

int main()
{
    int a,b,ap,bp,aporbp,hb,mask=0x0fffffff;
    sync()
    cin>>tc;
    while(tc--){
        cin>>a>>b;
        ans=b-a;
        for(ap=a;ap<b;ap++){
            if(ap&(~b)) {
                hb=31-__builtin_clz(ap&(~b));
                bp=(b>>hb|1)<<hb;
            }
            else bp=b;
            ans=min(ans,(ap+(ap|bp)+1-a-b));
        }
        cout<<ans<<'\n';
    }
    return 0;
}
