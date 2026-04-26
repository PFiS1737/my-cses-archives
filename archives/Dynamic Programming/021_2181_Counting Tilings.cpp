// Your task is to count the number of ways you can fill an n \times m grid using 1 \times
// 2 and 2 \times 1 tiles.
//
// Input
// The only input line has two integers n and m.
//
// Output
// Print one integer: the number of ways modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 10
// 1 \le m \le 1000

// clang-format off

// Sample Input
// 4 7

// Sample Output
// 781

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

template <typename... T> inline void see(T &...args) {
  ((cin >> args), ...);
}

#define takei(...) \
  int __VA_ARGS__; \
  see(__VA_ARGS__)

#define takevi(v, n) \
  vi v(n + 1); \
  for (int i = 1; i <= n; i++) \
  cin >> v[i]

vpii res;
void pre(int n, int i, int left, int right) {
  if (i > n)
    return;
  if (i == n) {
    res.pb({left, right});
    return;
  }
  pre(n, i + 1, left | 1 << i, right);
  pre(n, i + 1, left, right | 1 << i);
  pre(n, i + 2, left, right);
}

void solve() {
  takei(n, m);

  pre(n, 0, 0, 0);

  vi cur(1 << n), prev(1 << n);
  prev[0] = 1;

  while (m--) {
    fill(cur.begin(), cur.end(), 0);

    for (auto [x, y] : res) {
      cur[y] += prev[x];
      cur[y] %= M;
    }

    swap(cur, prev);
  }

  cout << prev[0] << endl;
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
