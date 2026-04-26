// There are n people who want to get to the top of a building which has only one
// elevator. You know the weight of each person and the maximum allowed weight in the
// elevator. What is the minimum number of elevator rides?
//
// Input
// The first input line has two integers n and x: the number of people and the maximum
// allowed weight in the elevator. The second line has n integers w_1,w_2,\dots,w_n: the
// weight of each person.
//
// Output
// Print one integer: the minimum number of rides.
//
// Constraints
//
// 1 \le n \le 20
// 1 \le x \le 10^9
// 1 \le w_i \le x

// clang-format off

// Sample Input
// 4 10
// 4 8 6 1

// Sample Output
// 2

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

// TODO:

void solve() {
  takei(n, x);

  vi w(n);
  for (int &i : w)
    cin >> i;

  const int N = 20;

  vpii dp(1 << N);
  dp[0] = {1, 0};

  for (int s = 1; s < (1 << n); s++) {
    dp[s] = {N + 1, 0};

    for (int p = 0; p < n; p++) {
      if (s & (1 << p)) {
        auto [r, l] = dp[s ^ (1 << p)];
        pii added;
        if (l + w[p] <= x) {
          added = {r, l + w[p]};
        } else {
          added = {r + 1, w[p]};
        }
        dp[s] = min(dp[s], added);
      }
    }
  }

  cout << dp[(1 << n) - 1].first << endl;
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
