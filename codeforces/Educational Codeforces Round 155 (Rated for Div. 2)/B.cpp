#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n, m;
void solve() {
  int i, j;
  cin >> n;
  int asum = 0, amn = 1e9;
  int bsum = 0, bmn = 1e9, num;
  for (i = 1; i <= n; i++) {
    cin >> num;
    asum += num;
    amn = min(amn, num);
  }
  for (i = 1; i <= n; i++) {
    cin >> num;
    bsum += num;
    bmn = min(bmn, num);
  }
  cout << min(asum + bmn * n, bsum + amn * n) << '\n';
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