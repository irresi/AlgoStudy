// #include<bits/stdc++.h>
// using namespace std;
// #define all(x) (x).begin(),(x).end()
// #define int ll
// using ll = long long;
// using pii = pair<ll, ll>;
// int n,m;

// void solve(){
//   int i,j;
//   cin>>n;
// }
// signed main(){
//   ios::sync_with_stdio(0); cin.tie(0);
//   cin>>n;
//   int i,j,f,g,x;
//   for(i=1;i<=n;i++){
//     for(j=i,f=-1;j;j>>=1,f++);
//     for(g=1;f>=2 and pow(f,g)<=i;g++);
//     g--;
//     prevg=g;
//     if(g!=prevg) cout<<i<<' '<<f<<' '<<g<<'\n';
//   }
//   return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int mod=1e9+7;
int n,q;

void solve(){
  int i,j;
  cin>>n;
}
int lpow(int f, int g){
  int ret=1;
  while(g){
    ret*=f;
    g--;
  }
  if(ret<0) cout<<"overflow on "<<f<<' '<<g<<'\n';
  return ret;
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int mn,mx;
  int i,j,f,g,x,prevg=-1;
  vector<int> lib;
  for(f=1;f<=58;f++){
    for(g=1;g<=10;g++){
      lib.push_back((1ll<<f)-1);
      lib.push_back(lpow(f,g)-1);
      lib.push_back(1ll<<f);
      lib.push_back(lpow(f,g));
    }
  }
  vector<pii> v;
  sort(all(lib));
  for(int i : lib){
    for(j=i,f=-1;j;j>>=1,f++);
    for(g=1;f>=2 and lpow(f,g)>=0 and lpow(f,g)<=i;g++);
    g--;
    if(g!=prevg) {
      v.emplace_back(i,g);
      // cout<<i<<' '<<f<<' '<<g<<'\n';
    }
    prevg=g;
  }
  v.emplace_back(1000000000000000001ll,10);
  int l,r,cur,newx,pg,ans=0;
  cin>>q;
  while(q--){
    ans=0;
    cin>>l>>r;
    cur=l;
    for(auto &[x, g] : v){
      if(cur>r) break;
      newx=min(r+1,x);
      if(x>=cur){
        ans+=(newx-cur)*pg;
        ans%=mod;
        cur=newx;
      }
      pg=g;
    }
    cout<<ans<<'\n';
  }
  return 0;
}