// The edit distance between two strings is the minimum number of operations required to
// transform one string into the other. The allowed operations are:
//
// Add one character to the string.
// Remove one character from the string.
// Replace one character in the string.
//
// For example, the edit distance between LOVE and MOVIE is 2, because you can first
// replace L with M, and then add I. Your task is to calculate the edit distance between
// two strings.
//
// Input
// The first input line has a string that contains n characters between A–Z.
// The second input line has a string that contains m characters between A–Z.
//
// Output
// Print one integer: the edit distance between the strings.
//
// Constraints
//
// 1 \le n,m \le 5000

// clang-format off

// Sample Input
// LOVE
// MOVIE

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
  string s1, s2;
  cin >> s1 >> s2;

  int n = s1.size();
  int m = s2.size();

  vvi dp(n + 1, vi(m + 1, 0));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= m; j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
      }
    }
  }

  cout << dp[n][m] << endl;
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
