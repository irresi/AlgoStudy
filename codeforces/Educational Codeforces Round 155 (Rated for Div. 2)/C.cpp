#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
const int mod = 998244353;
int n, m;
char str[200003];
void solve() {
  int i, j, cont = 1, PN = 0, PR = 0, ans = 1;
  cin >> str;
  n = strlen(str);
  for (i = 1; i < n; i++) {
    if (str[i] == str[i - 1])
      cont++;
    else {
      if (cont > 1) {
        ans *= cont;
        ans %= mod;
        PN += (cont - 1);
      }
      cont = 1;
    }
  }
  if (cont > 1) {
    ans *= cont;
    ans %= mod;
    PN += (cont - 1);
  }

  for (i = PN; i > 1; i--) {
    ans = ans * i % mod;
  }
  cout << PN - PR << " " << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}