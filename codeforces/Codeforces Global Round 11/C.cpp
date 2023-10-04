#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define int ll
using ll = long long;
using pii = pair<ll, ll>;
using iii = tuple<ll, ll, ll>;
int r, n, m;
vector<iii> v;
vector<int> mx, mx2;
bool reachable(int &prev, int &cur) {
  auto &[pt, px, py] = v[prev];
  auto &[ct, cx, cy] = v[cur];
  return abs(px - cx) + abs(py - cy) <= ct - pt;
}
void solve() {
  int i, j, t, x, y;
  cin >> r >> n;
  vector<ll> d(n+1,-1e9);
  mx.push_back(0);
  v.emplace_back(0, 1, 1);
  d[0]=0;
  for (i = 1; i <= n; i++) {
    cin >> t >> x >> y;
    v.emplace_back(t, x, y);
  }
  int flag = 0, ans = 0;
  for (int cur = 1; cur <= n; cur++) {
    for(int prev = max(0LL,cur-r*2);prev<cur;prev++){
      if(reachable(prev,cur)){
        d[cur] = max(d[cur],d[prev] + 1);
        ans=max(d[cur],ans);
      }
    }
  }
  cout << ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  solve();
  return 0;
}