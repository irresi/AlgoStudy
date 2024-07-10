#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vector<int> l(n),r(n);
    for(int i=0;i<n;i++) cin>>l[i]>>r[i];
    map<int, vector<int>> u;
    for(int i=0;i<n;i++){
      u[l[i]].push_back(r[i]);
      u[r[i]+1].push_back(l[i]);
    }
    int ans=0;
    int cnt=0, zac=0, kon=0; //어차피 맨 앞 혹은 맨 뒤가 min값이니까
    for(pair<int, vector<int>> p : u){
      int x = p.first;
      if(x>m) break;
      for(int y : p.second){
        if(x<=y){ //구간 더하기
          if(x==1) zac++;
          if(y==m) kon++;
          cnt++;
        }
        else{ //구간 빼기
          if(y==1) zac--;
          cnt--;
        }
      }
      ans = max(ans, cnt - min(zac, kon));
    }
    cout<<ans<<'\n';
  }
  return 0;
}