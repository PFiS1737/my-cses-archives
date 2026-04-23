// Given two arrays of integers, find their longest common subsequence.
// A subsequence is a sequence of array elements from left to right that can contain gaps.
// A common subsequence is a subsequence that appears in both arrays.
//
// Input
// The first line has two integers n and m: the sizes of the arrays.
// The second line has n integers a_1,a_2,\dots,a_n: the contents of the first array.
// The third line has m integers b_1,b_2,\dots,b_m: the contents of the second array.
//
// Output
// First print the length of the longest common subsequence.
// After that, print an example of such a sequence. If there are several solutions, you
// can print any of them.
//
// Constraints
//
// 1 \le n,m \le 1000
// 1 \le a_i, b_i \le 10^9

// clang-format off

// Sample Input
// 8 6
// 3 1 3 2 7 4 8 2
// 6 5 1 2 3 4

// Sample Output
// 3
// 1 2 4 

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

void print_lcs(vvi &dp, vi &s1, vi &s2, int i, int j) {
  if (i == 0 || j == 0)
    return;

  if (s1[i] == s2[j]) {
    print_lcs(dp, s1, s2, i - 1, j - 1);
    cout << s1[i] << " ";
  } else if (dp[i - 1][j] > dp[i][j - 1]) {
    print_lcs(dp, s1, s2, i - 1, j);
  } else {
    print_lcs(dp, s1, s2, i, j - 1);
  }
}

void solve() {
  takei(n);
  takei(m);

  takevi(s1, n);
  takevi(s2, m);

  vvi dp(n + 1, vi(m + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i] == s2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  cout << dp[n][m] << endl;

  print_lcs(dp, s1, s2, n, m);
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
