#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
int n, m;
void solve() {
  int i, j, s, e, s0, e0, ans;
  cin >> n;
  cin >> s0 >> e0;
  ans = s0;
  for (i = 1; i < n; i++) {
    cin >> s >> e;
    if (e >= e0 and s >= s0) ans = -1;
  }
  cout << ans << '\n';
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