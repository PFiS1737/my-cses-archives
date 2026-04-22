// You are given an integer n. On each step, you may subtract one of the digits from the
// number. How many steps are required to make the number equal to 0?
//
// Input
// The only input line has an integer n.
//
// Output
// Print one integer: the minimum number of steps.
//
// Constraints
//
// 1 \le n \le 10^6
//
// Explanation
// An optimal solution is 27 -> 20 -> 18 -> 10 -> 9 -> 0.

// clang-format off

// Sample Input
// 27

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

#define pb push_back
#define endl "\n"
#define M 1000000007
#define INF 1e9

#define take(x) \
  int x; \
  cin >> x

void solve() {
  take(n);

  vi dp(n + 1, INF);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = i; j != 0; j /= 10) {
      int d = j % 10;
      if (d != 0) {
        dp[i] = min(dp[i], dp[i - d] + 1);
      }
    }
  }

  cout << dp[n] << endl;
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
