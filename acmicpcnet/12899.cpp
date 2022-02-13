#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    sync;
    ordered_set X;
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a==1) X.insert(b);
        else{
            auto ptr = X.find_by_order(b-1);
            cout<<*ptr<<'\n';
            X.erase(ptr);
        }
    }
}
