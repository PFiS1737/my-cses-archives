// You know that an array has n integers between 1 and  m, and the absolute difference
// between two adjacent values is at most 1. Given a description of the array where some
// values may be unknown, your task is to count the number of arrays that match the
// description.
//
// Input
// The first input line has two integers n and m: the array size and the upper bound for
// each value. The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
// Value 0 denotes an unknown value.
//
// Output
// Print one integer: the number of arrays modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 10^5
// 1 \le m \le 100
// 0 \le x_i \le m

// clang-format off

// Sample Input
// 3 5
// 2 0 2

// Sample Output
// 3

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
  takei(m);

  takevi(x, n);

  // INFO: dp[i][j] 表示前 i 个元素，且最后一个元素值为 j 的方案数
  vvi dp(n + 1, vi(m + 2, 0));

  for (int j = 1; j <= m; j++) {
    if (x[1] == 0 || x[1] == j) {
      dp[1][j] = 1;
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (x[i] == 0 || x[i] == j) {
        for (int k : {-1, 0, 1}) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j + k]) % M;
        }
      }
    }
  }

  int ans = 0;
  for (int j = 1; j <= m; j++) {
    ans = (ans + dp[n][j]) % M;
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
