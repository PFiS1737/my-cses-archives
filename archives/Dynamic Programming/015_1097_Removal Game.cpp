// There is a list of n numbers and two players who move alternately. On each move, a
// player removes either the first or last number from the list, and their score increases
// by that number. Both players try to maximize their scores. What is the maximum possible
// score for the first player when both players play optimally?
//
// Input
// The first input line contains an integer n: the size of the list.
// The next line has n integers x_1,x_2,\ldots,x_n: the contents of the list.
//
// Output
// Print the maximum possible score for the first player.
//
// Constraints
//
// 1 \le n \le 5000
// -10^9 \le x_i \le 10^9

// clang-format off

// Sample Input
// 4
// 4 5 1 3

// Sample Output
// 8

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

  takevi(x, n);

  // dp[i][j] 为先手在区间 [i, j] 中能获得的最高分
  vvll dp(n + 1, vll(n + 1));

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][i] = x[i];
    sum += x[i];
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i + l - 1 <= n; i++) {
      int j = i + l - 1;
      dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
    }
  }

  cout << (sum + dp[1][n]) / 2 << endl;
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
