// You have n coins with certain values. Your task is to find all money sums you can
// create using these coins.
//
// Input
// The first input line has an integer n: the number of coins.
// The next line has n integers x_1,x_2,\dots,x_n: the values of the coins.
//
// Output
// First print an integer k: the number of distinct money sums. After this, print all
// possible sums in increasing order.
//
// Constraints
//
// 1 \le n \le 100
// 1 \le x_i \le 1000

// clang-format off

// Sample Input
// 4
// 4 2 5 2

// Sample Output
// 9
// 2 4 5 6 7 8 9 11 13 

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

  const int X = 100 * 1000;

  // dp[i] 表示是否可以组合出和为 i 的数
  vi dp(X + 1, false);
  dp[0] = true;

  while (n--) {
    takei(x);
    for (int i = X; i >= x; i--) {
      if (dp[i - x]) {
        dp[i] = true;
      }
    }
  }

  int s = 0;
  for (int i = 1; i <= X; i++) {
    s += dp[i];
  }
  cout << s << endl;
  for (int i = 1; i <= X; i++) {
    if (dp[i]) {
      cout << i << " ";
    }
  }
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
