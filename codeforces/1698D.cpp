#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
int a[10003];
vector<int> ask(int s, int e){
  printf("? %lld %lld\n",s,e);
  fflush(stdout);
  vector<int> ret(e-s+1);
  for(int i=0;i<e-s+1;i++){
    scanf("%lld",&ret[i]);
  } 
  return ret;
}
void f(int s, int e){ //s,e에 속한게 홀수개 -> 해당 구간에 답 있음.
  m=(s+e)/2;
  int cnt=0,lst;
  vector<int> ans = ask(s,m);
  for(int &num : ans){
    if(s<=num and num<=m) {
      cnt++;
      lst=num;
    }
  }
  if(cnt==1){
    printf("! %lld\n",lst);
    fflush(stdout);
    return;
  }
  if(cnt&1) f(s,m);
  else f(m+1,e);
}
void solve(){
  int i,j;
  cin>>n;
  f(1,n);
}
signed main(){
  // ios::sync_with_stdio(0); cin.tie(0);
  int tc; scanf("%lld",&tc); while(tc--)
    solve();
  return 0;
}
//1 2 3 4 5 6 7 8 9
//8 3 2 6 5 4 9 1 7
//구간 안에 2개가 다 있다 : 둘 끼리 바뀜
//구간 안에 
//2 3 5 6 8
//[s,e]에 2개가 있다. : 둘끼리 바뀜
//[s,e]에 1개가 있다. : 이게 답.
//[s,e]에 0개가 있다. : 반대쪽이랑 매칭.