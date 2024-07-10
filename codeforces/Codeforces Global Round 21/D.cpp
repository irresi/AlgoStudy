#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m,a[250003];
void solve(){
  vector<pair<int, int>> proc_idx;
  set<int> left;
  cin>>n;
  int i,j;
  for(i=1;i<=n;i++){
    cin>>a[i];
    left.insert(i);
  }
  vector<int> checked =  {a[1]};
  left.erase(a[1]);
  int flag = a[1]<a[2],curflag,lst=a[1];
  for(i=2;i<=n;i++){
    curflag = checked.back()<a[i];
    if(flag==1){ //증가
      lst = max(lst,a[i]);
      if(curflag==0) {
        checked.push_back(lst); //감소
        flag=0;
        lst=a[i];
      }
    }
    else{ //감소
      lst = min(lst,a[i]);
      if(curflag==1) {
        checked.push_back(lst); //증가
        flag=1;
        lst=a[i];
      }
    }
    left.erase(a[i]);
  }
  checked.push_back(lst);
  if(lst!=a[n]) checked.push_back(a[n]);
  cout<<checked.size()-1<<'\n';
  return;
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}