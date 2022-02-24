#include <bits/stdc++.h>
#include<random>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf=1e9+3;
#define all(x) (x).begin(),(x).end()
#define sync() {ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);} //do not use
int n,m,ans;
char str[33][33];
unsigned int coin[33],mask=0xffffffff;
int getE(){
	int res=0;
	for(int i=0;i<n;i++) res+=__builtin_popcount(coin[i]);
	return res;
}
void op(int tp, int num){
    if(!tp){
        coin[num]^=mask;
    }
    else{
        for(int i=0;i<n;i++){
            coin[i]^=(1<<num);
        }
    }
}
int main()
{
	int tc,i,j,curE,nextE,tp,num;
    sync()
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>str[i];
    	for(j=0;j<n;j++){
    		coin[i]<<=1;
    		coin[i]|=str[i][j]=='T';
    	}
    }
    mask>>=(32-n);
    random_device rd;
    mt19937_64 seed(rd());
    uniform_int_distribution<int> tog(0,1),rg(0,n-1);
    uniform_real_distribution<double>rng(0,1);
    long double T=100*n,Tlim=1e-9,p;
    ans=curE=getE();
    while(T>Tlim){
    	tp = tog(seed);
    	num = rg(seed);
    	if(tp==0) {
            nextE=curE+n-__builtin_popcount(coin[num])*2;
        }
    	else {
            nextE=curE;
            for(i=0;i<n;i++) {
                if(coin[i]&(1<<num)) nextE--;
                else nextE++;
            }
    	}
    	p=exp((curE-nextE)/T);
    	ans=min(ans,nextE);
    	double prob=rng(seed);
    	if(p>prob) {
            op(tp,num);
            curE=nextE;
        }
    	T*=0.99999;
    }
    cout<<ans;
    return 0;
}
/*
이 코드에서는 열과 행에 관한 연산을 모두 랜덤으로 처리했지만
열만 연산을 한후
한 행에 대해 0의 개수 와 1의 개수 중 더 작은 것을 생각할 수 있다.

열에 대한 연산도 모든 행에 어떤 수 x를 xor 하는 것으로 생각할 수 있다.
배열을 직접 바꾸지 않고 x만을 바꿔도 된다.
*/
