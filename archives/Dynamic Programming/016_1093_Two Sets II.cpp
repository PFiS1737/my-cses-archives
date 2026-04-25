// Your task is to count the number of ways numbers 1,2,\ldots,n can be divided into two
// sets of equal sum. For example, if n=7, there are four solutions:
//
// \{1,3,4,6\} and \{2,5,7\}
// \{1,2,5,6\} and \{3,4,7\}
// \{1,2,4,7\} and \{3,5,6\}
// \{1,6,7\} and \{2,3,4,5\}
//
// Input
// The only input line contains an integer n.
//
// Output
// Print the answer modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 500

// clang-format off

// Sample Input
// 7

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

  int sum = n * (n + 1) / 2;
  if (sum % 2 != 0) {
    cout << 0 << endl;
    return;
  }
  sum /= 2;

  // dp[i] 表示分为两组，每组和为 i，的划分数量
  vi dp(sum + 1);
  dp[0] = 1;

  for (int x = 1; x < n; x++) { // 考虑前 x 个元素
    for (int s = sum; s - x >= 0; s--) {
      dp[s] = (dp[s] + dp[s - x]) % M;
    }
  }

  cout << dp[sum] << endl;
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
