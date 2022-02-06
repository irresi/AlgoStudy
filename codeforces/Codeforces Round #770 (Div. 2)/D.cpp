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
vector<int> v,nv;
void cand(vector<int> A){
    vector<vector<int>> B={{A[0],A[1],A[2]}, {A[0],A[1],A[3]},{A[0],A[2],A[3]},{A[1],A[2],A[3]}};
    vector<int> chk(4,0);
    vector<int> res(4);
    int i=0,j,mx=0;
    for(auto vb : B){
        printf("? ");
        for(int num : vb)
            printf("%d ",num);
        printf("\n");
        fflush(stdout);
        scanf("%d",&res[i]);
        mx=max(mx,res[i]);
        i++;
    }
    for(i=0;i<4;i++){
        if(mx==res[i]) chk[3-i]=1;
    }
    for(i=0;i<4;i++)if(!chk[i]) nv.push_back(A[i]);
}
int main()
{
    int i,j,tcnum;
	//sync();
    cin>>tc;
    for(tcnum=1;tcnum<=tc;tcnum++){
        v.clear();
        nv.clear();
        
        cin>>n;
        for(i=1;i<=n;i++) v.push_back(i);
        while(v.size()>2){
            if(v.size()==3){
                for(i=1;i==v[0] || i==v[1] || i==v[2];i++);
                v.push_back(i);
            }
            nv.clear();
            n=v.size();
            for(i=0;i+3<n;i+=4){
                cand({v[i],v[i+1],v[i+2],v[i+3]});
            }
            for(;i<n;i++) nv.push_back(v[i]);
            v=nv;
        }
        printf("! %d %d\n",v[0],v[1]);
        fflush(stdout);
    }
    return 0;
}
