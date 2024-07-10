#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    i64 ans = 0;
    std::vector<i64> f(n + 1); //cnt g를 gcd로 가지는 쌍의 개수
    //두 수가 ag, bg일 때 gcd(a,b)==1이어야 한다. 
    std::vector<int> g(n + 1); 
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        f[a] += 1;
        g[a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            g[j] |= g[i]; 
            f[i] += f[j]; //f[i] : i의 배수 중 a에 포함된 것의 개수
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i] *= f[i]; //gcd가 g의 배수인 것의 개수를 센다. 
    }
    for (int i = n; i; i--) { //거꾸로 돌기 때문에 겹치는 것들을 제외시키고 gcd가 i인 것을 구할 수 있다.
        for (int j = 2 * i; j <= n; j += i) {
            f[i] -= f[j]; //gcd가 2g,3g인 것들을 다 빼준다. 
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!g[i]) { //a의 어떠한 수로도 나누어 떨어지지 않는 i
            ans += f[i];
        }
    }
    ans /= 2; //쌍 앞, 뒤 / 뒤, 앞
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
