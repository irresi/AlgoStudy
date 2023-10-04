#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n,q;
void solve(){
    int i,j,num,minlst;
    cin>>n>>q;
    vector<int> v(n),added[2],div[2],resid(2),lessn,lessn_mn;
    for(int &num : v) cin>>num;
    sort(all(v));
    for(i=0;i<n and v[i]==v[0];i++);
    minlst = --i;
    //n-1 or n
    added[0]=added[1]=v;
    for(i=0;i<n;i++)
        added[n&1][i]+=n-i;
    for(i=0;i<n-1;i++)
        added[!(n&1)][i]+=(n-1-i);
    lessn=added[n&1];
    lessn_mn = lessn;
    for(i=1;i<n;i++){        
        lessn_mn[i] = min(lessn_mn[i-1],lessn[i]);
    }
    sort(all(added[0])); sort(all(added[1])); //incase of same element
    for(i=0;i<2;i++){
        int sz=added[i].size();
        for(j=1;j<sz;j++){
            resid[i]+=added[i][j]-added[i][0];
        }
    }
    int tominus,ans,allplus,curmin;
    for(i=0;i<q;i++){
        cin>>num;
        if(num<n){
            cout<<min(lessn_mn[num]-(n-num),lessn[num+1])<<' ';
            continue;
        }
        if((num&1)==(n&1)){
            allplus = num-n;
            tominus = allplus/2;
            tominus = resid[n&1]-tominus;
            curmin = allplus + added[n&1][0];
        }
        else {
            allplus = num-n+1;
            vector<int> &curv = added[!(n&1)];
            //allplus + (1~n-1) is added to n-1 element, and assume allplus is added to all n element, so minus allplus on largest element;
            tominus = allplus/2;
            tominus = resid[!(n&1)] - tominus;
            if(v.back()>=curv.front()+allplus){
                curmin = curv.front() + allplus;
                tominus -=allplus;
            }
            else{
                curmin = v.back();
                tominus -=  v.back() - curv.front();
                tominus += (curv.front()+allplus-v.back())*(n-1);
            }
        }
        if(tominus<0) curmin+=(tominus-n+1)/n;
        cout<<curmin<<' ';
    }
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // int tc; cin>>tc;
    // while(tc--){
        solve();
    // }
    return 0;
}