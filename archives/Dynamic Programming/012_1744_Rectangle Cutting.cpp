// Given an a \times b rectangle, your task is to cut it into squares. On each move you
// can select a rectangle and cut it into two rectangles in such a way that all side
// lengths remain integers. What is the minimum possible number of moves?
//
// Input
// The only input line has two integers a and b.
//
// Output
// Print one integer: the minimum number of moves.
//
// Constraints
//
// 1 \le a,b \le 500

// clang-format off

// Sample Input
// 3 5

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
  takei(a);
  takei(b);

  vvi dp(a + 1, vi(b + 1, 0));

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i == j) {
        continue;
      } else {
        dp[i][j] = INF;
        for (int k = 1; k < i; k++) {
          dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        }
        for (int k = 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
      }
    }
  }

  cout << dp[a][b] << endl;
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
