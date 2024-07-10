#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using namespace std;

int rand(int a, int b){
    return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int n = rand(2,5);
    printf("1\n%d\n",n);
    vector<int> v(n);
    iota(all(v),1);
    random_shuffle(all(v));
    for(int &num : v) printf("%d ",num);
    return 0;
}