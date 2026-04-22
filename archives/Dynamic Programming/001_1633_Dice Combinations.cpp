// Your task is to count the number of ways to construct sum n by throwing a dice one or
// more times. Each throw produces an outcome between 1 and  6. For example, if n=3, there
// are 4 ways:
//
// 1+1+1
// 1+2
// 2+1
// 3
//
// Input
// The only input line has an integer n.
//
// Output
// Print the number of ways modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 10^6

// clang-format off

// Sample Input
// 3

// Sample Output
// 4

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

#define take(x) \
  int x; \
  cin >> x

void solve() {
  take(n);

  vll dp(n + 1);

  // 投出和为 0 的方法数为 1（不投出任何骰子）
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    // 本次投出一个骰子，可能的点数为 1 到 6
    for (int j = 1; j <= 6; j++) {
      // 还需要投出 i - j 的点数，方法数为 dp[i - j]
      if (i - j >= 0) {
        dp[i] = (dp[i] + dp[i - j]) % M;
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
