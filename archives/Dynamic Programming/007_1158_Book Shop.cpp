// You are in a book shop which sells n different books. You know the price and number of
// pages of each book. You have decided that the total price of your purchases will be at
// most x. What is the maximum number of pages you can buy? You can buy each book at most
// once.
//
// Input
// The first input line contains two integers n and x: the number of books and the maximum
// total price. The next line contains n integers h_1,h_2,\ldots,h_n: the price of each
// book. The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each
// book.
//
// Output
// Print one integer: the maximum number of pages.
//
// Constraints
//
// 1 \le n \le 1000
// 1 \le x \le 10^5
// 1 \le h_i, s_i \le 1000

// clang-format off

// Sample Input
// 4 10
// 4 8 5 3
// 5 12 8 1

// Sample Output
// 13

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
  takei(x);

  takevi(h, n);
  takevi(s, n);

  // INFO: dp[i][j] 表示花最多 j 元钱，索引为 1..=i 的书能获得的最大页数
  vvi dp(n + 1, vi(x + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (h[i] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
      }
    }
  }

  cout << dp[n][x] << endl;
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
