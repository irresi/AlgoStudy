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

ll tc,n,m,a;
vector<ll> chk(4),nxt(4);
int main()
{
    ll i,j,tcnum,x,y;
	sync();
    cin>>tc;
    for(tcnum=1;tcnum<=tc;tcnum++){
        cin>>n>>x>>y;
        x%=4; y%=4;
        chk={0,0,0,0};
        chk[y]=1;
        for(i=1;i<=n;i++){
            nxt={0,0,0,0};
            cin>>a;
            a%=4;
            for(j=0;j<4;j++)if(chk[j]){
                nxt[(4+j-a)%4]=1;
                nxt[j^a]=1;
            }
            chk=nxt;
        }
        if(chk[x]) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    return 0;
}
