#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int inf=(int)1e9;
int n,m,ans,ansr,ansc;
vector<pii> B;
int getdist(int r, int c){
  int ret=0;
  for(auto &[br,bc] : B){
    ret=max(ret,abs(r-br)+abs(c-bc));
  }
  if(ret<ans){
    ansr=r,ansc=c,ans=ret;
  }
  return ret;
}
int ternaryc(int r){
  int sc=1,ec=m,ret=inf,mc1,mc2,d1,d2;
  while(sc<=ec){
    mc1=sc+(ec-sc)/3; mc2=ec-(ec-sc)/3;
    d1 = getdist(r,mc1), d2 = getdist(r,mc2);
    ret=min({ret,d1,d2});
    if(d1<=d2) ec=mc2-1;
    if(d1>=d2) sc=mc1+1;
  }
  return ret;
}
void solve(){
  ans=inf;
  B.clear();
  char str[1003];
  cin>>n>>m;
  int i,j,Bcnt=0,sr=1,er=n,mr1,mr2,d1,d2;
  for(i=1;i<=n;i++){
    cin>>str+1;
    for(j=1;j<=m;j++){
      if(str[j]=='B') B.emplace_back(i,j);
    }
  }
  while(sr<=er){
    mr1=sr+(er-sr)/3,mr2=er-(er-sr)/3;
    d1 = ternaryc(mr1), d2 = ternaryc(mr2);
    if(d1<=d2) er=mr2-1;
    if(d1>=d2) sr=mr1+1;
  }
  cout<<ansr<<' '<<ansc<<'\n';
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}