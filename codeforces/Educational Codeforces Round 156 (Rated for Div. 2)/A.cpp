#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
using point = pair<double, double>;
int n,m;
double d(point &A, point &B){
  return sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
}
void solve(){
  int i,j;
  point A,B,P,O={0,0};
  cin>>P.first>>P.second>>A.first>>A.second>>B.first>>B.second;
  double AO = d(A,O),AP=d(A,P),BO=d(B,O),BP=d(B,P),AB=d(A,B);
  cout.precision(10);
  cout<<min({max(AO,AP),max(BO,BP),max({AO,BP,AB/2}),max({BO,AP,AB/2})})<<'\n';
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}