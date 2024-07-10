#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;

void solve(){
  int i,j,len,pos,cnt=0;
  stack<int> st;
  string s;
  cin>>s>>pos;
  len = s.size();
  vector<int> v(len);
  int r=len,c=pos;
  for(r=len;r>=1;r--){
    if(c<=r) break;
    c-=r;
  }
  r=len+1-r;
  for(i=0;i<len;i++){
    while(!st.empty() and s[st.top()]>s[i]){
      v[st.top()] = ++cnt;
      st.pop();
    }
    st.push(i);
  }
  while(!st.empty()){
    v[st.top()] = ++cnt;
    st.pop();
  }
  for(i=0;i<len;i++){
    if(v[i]<r) continue;
    c--;
    if(!c) break;
  }
  cout<<s[i];
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}