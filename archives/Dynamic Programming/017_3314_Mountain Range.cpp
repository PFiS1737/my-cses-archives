// There are n mountains in a row, each with a specific height. You begin your hang
// gliding route from some mountain. You can glide from mountain a to mountain b if
// mountain a is taller than mountain b and all mountains between a and b. What is the
// maximum number of mountains you can visit on your route?
//
// Input
// The first line has an integer n: the number of mountains.
// The next line has n integers h_1, h_2,\dots, h_n: the heights of the mountains.
//
// Output:
// Print one integer: the maximum number of mountains.
//
// Constraints
//
// 1\le n \le 2 \cdot 10^5
// 1\le h_i \le 10^9

// clang-format off

// Sample Input
// 10
// 20 15 17 35 25 40 12 19 13 12

// Sample Output
// 5

// clang-format on

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using mii = map<int, int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvll = vector<vll>;

#define pb push_back
#define endl "\n"
#define M 1000000007
#define INF 1e9

#define takei(x) \
  int x; \
  cin >> x

#define takevi(v, n) \
  vi v(n + 1); \
  for (int i = 1; i <= n; i++) \
  cin >> v[i]

void solve() {
  takei(n);

  vpii hs;
  for (int i = 1; i <= n; i++) {
    takei(h);
    hs.pb({h, i});
  }
  sort(hs.begin(), hs.end(), greater<pii>());

  mii dp;
  dp[0] = 0;
  dp[n + 1] = 0;

  int prev = 0;
  vpii updates;

  int ans = 0;

  for (auto [h, i] : hs) {
    if (h != prev) {
      for (auto [pos, count] : updates) {
        dp[pos] = count;
      }
      updates.clear();
      prev = h;
    }

    auto it = dp.upper_bound(i);
    int next_pos = it->first;
    it--;
    int prev_pos = it->first;

    int new_count = max(dp[prev_pos], dp[next_pos]) + 1;
    updates.pb({i, new_count});
    ans = max(ans, new_count);
  }

  cout << ans << endl;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
