#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
int a[200005];
//ans1 : odd거리 합, ans2 : 3이상의 segment 개수, 단 ans1==0인 경우 그대로
int get_state(int &a, int &b){
  if(a!=b) return -1;
  return a;
}
void solve(){
  int ans1=0,ans2=1,i,nxtstate,curstate=-1;
  scanf("%lld",&n);
  for(i=1;i<=n;i++){
    scanf("%1lld",&a[i]);
  }
  for(i=1;i<=n;i+=2){
    nxtstate=get_state(a[i],a[i+1]);
    if(nxtstate<0) ans1++;
    if(curstate<0) curstate=nxtstate;
    else{
      if(nxtstate+curstate==1){
        curstate=nxtstate;
        ans2++;
      }
    }
  }
  cout<<ans1<<' '<<ans2<<'\n';
}
signed main(){
  // ios::sync_with_stdio(0); cin.tie(0);
  int tc; scanf("%lld",&tc); while(tc--)
    solve();
  return 0;
}