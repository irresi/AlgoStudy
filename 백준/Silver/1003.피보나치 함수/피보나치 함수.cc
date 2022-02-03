#include <bits/stdc++.h>
using namespace std;
int t,num,fib[43]={0,1};
int main()
{
    int i;
    scanf("%d",&t);
    for(i=2;i<=41;i++) fib[i]=fib[i-1]+fib[i-2];
    while(t--){
        scanf("%d",&num);
        if(!num) printf("1 0\n");
        else printf("%d %d\n",fib[num-1],fib[num]);
    }
    return 0;
}
