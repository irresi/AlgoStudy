#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,m;
int ask(int tp, int idx){
  int num;
  cout<<"? 2 "<<tp+1<<' '<<idx+1<<endl;
  cin>>num;
  return num;
}
void solve(){
  int i,j,lstsz,s,e,mid,fnd;
  cin>>n;
  vector<int> tp(n,-1),lstidx(26,-1),type_order(26); //1~26
  string lib(30,0);
  string ans;
  //i번째 인덱스의 종류, 종류별 마지막 인덱스, 종류 순서(최근에 나온 것이 앞으로)
  tp[0]=0; lstidx[0]=0;
  lstsz=0;
  for(i=1;i<n;i++){
    s=0;e=lstsz; fnd=-1;
    while(s<=e){ //mid개의 문자를 고려할 때 mid+2가 안 나오는 가장 작은 수
      mid=(s+e)/2;
      if(ask(lstidx[type_order[mid]],i)==mid+2) s=mid+1;
      else {
        fnd=mid;
        e=mid-1;
      }
    }
    if(fnd==-1){ //새로운 문자 추가
      tp[i]=++lstsz;
      lstidx[tp[i]]=i;
      for(j=lstsz;j>=1;j--) type_order[j]=type_order[j-1];
      type_order[0]=lstsz;
    }
    else{ //fnd만큼 전에 있는 문자와 같은 문자
      tp[i]=type_order[fnd];
      lstidx[tp[i]]=i;
      type_order.erase(type_order.begin()+fnd);
      type_order.insert(type_order.begin(),tp[i]);
    }
  }
  char ch;
  for(i=0;i<26;i++){
    if(lstidx[i]!=-1){
      cout<<"? 1 "<<lstidx[i]+1<<endl;
      cin>>ch;
      lib[i]=ch;
    }
  }
  for(i=0;i<n;i++){
    ans+=lib[tp[i]];
  }
  cout<<"! "<<ans<<endl;
  return;
}
signed main(){
  // ios::sync_with_stdio(0); cin.tie(0);
  // int tc; cin>>tc; while(tc--)
    solve();
  return 0;
}