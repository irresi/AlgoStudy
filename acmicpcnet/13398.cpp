#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m,ans,sum,sum2;
vector<int> v;
int main()
{
    sync();
    int tc,num,i,mn=-1e9;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>num;
        mn = max(num,mn);
        sum2=max({0,sum,sum2+num,sum+num});
        sum+=num;
        if(sum<0) sum=0;
        ans=max(ans,sum2);
    }
    if(ans==0 && mn!=0) ans=mn;
    cout<<ans;
    return 0;
}
