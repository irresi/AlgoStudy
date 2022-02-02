#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m;
vector<int> v;
int main()
{
    sync();
    int tc,num,i;
    cin>>tc;
    while(tc--) {
        v.clear();
        cin>>n;
        for(i=1; i<=n; i++) {
            cin>>num;
            v.push_back(num);
        }
        cin>>m;
        vector<int> d(10001+m,0);
        d[0]=1;
        for(int topl : v) {
            for(i=0; i<=m; i++)if(d[i]){
                d[i+topl]+=d[i];
            }
        }
        cout<<d[m]<<'\n';
    }
    return 0;
}
