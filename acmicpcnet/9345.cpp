#include <bits/stdc++.h>
using namespace std;
#define nm (ns+ne)/2
const int mz=1<<17; //17
const int inf=1e9;
int n,k,sz,mx[2*mz],mn[2*mz],cur[mz];
void build(){
    for(int i=mz-1;i>=1;i--){
        mx[i]=max(mx[i<<1],mx[i<<1|1]);
        mn[i]=min(mn[i<<1],mn[i<<1|1]);
    }
    return;
}
void upd(int idx, int num){
    mx[idx+=mz]=num;
    mn[idx]=num;
    for(idx>>=1;idx;idx>>=1){
        mx[idx]=max(mx[idx<<1],mx[idx<<1|1]);
        mn[idx]=min(mn[idx<<1],mn[idx<<1|1]);
    }
    return;
}
bool query(int s, int e){
    int l=s, r=e+1;
    for(l+=mz,r+=mz;l<r;l>>=1,r>>=1){
        if(l&1){
            if(mn[l]<s || e<mx[l]) return false;
            l++;
        }
        if(r&1){
            --r;
            if(mn[r]<s || e<mx[r]) return false;
        }
    }
    return true;
}
int main(void)
{
    int tc,a,b,c,i;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        fill(mx,mx+sizeof(mx)/sizeof(int),-inf);
        fill(mn,mn+sizeof(mn)/sizeof(int),inf);

        for(i=0;i<n;i++){
            cur[i]=i;
            mx[i+mz]=mn[i+mz]=i;
        }
        build();
        for(i=1;i<=k;i++){
            cin>>a>>b>>c;
            if(a==0) {
                swap(cur[b],cur[c]);
                upd(b,cur[b]);
                upd(c,cur[c]);
            }
            else{
                cout<<(query(b,c)?"YES":"NO")<<'\n';
            }
        }
    }
}
