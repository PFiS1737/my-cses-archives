// Consider an n \times n grid whose squares may have traps. It is not allowed to move to
// a square with a trap. Your task is to calculate the number of paths from the upper-left
// square to the lower-right square. You can only move right or down.
//
// Input
// The first input line has an integer n: the size of the grid.
// After this, there are n lines that describe the grid. Each line has n characters: .
// denotes an empty cell, and * denotes a trap.
//
// Output
// Print the number of paths modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 1000

// clang-format off

// Sample Input
// 4
// ....
// .*..
// ...*
// *...

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

#define take(x) \
  int x; \
  cin >> x

void solve() {
  take(n);

  vector<string> G(n + 1, string(n + 1, '.'));
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    G[i] = "." + s;
  }

  vvi dp(n + 1, vi(n + 1, 0));

  dp[1][1] = (G[1][1] == '.') ? 1 : 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (G[i][j] == '.') {
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        dp[i][j] %= M;
      }
    }
  }

  cout << dp[n][n] << endl;
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
