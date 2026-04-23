// Your task is to build a tower whose width is 2 and height is n. You have an unlimited
// supply of blocks whose width and height are integers. For example, here are some
// possible solutions for n=6:
//
// Given n, how many different towers can you build? Mirrored and rotated towers are
// counted separately if they look different.
//
// Input
// The first input line contains an integer t: the number of tests.
// After this, there are t lines, and each line contains an integer n: the height of the
// tower.
//
// Output
// For each test, print the number of towers modulo 10^9+7.
//
// Constraints
//
// 1 \le t \le 100
// 1 \le n \le 10^6

// clang-format off

// Sample Input
// 3
// 2
// 6
// 1337

// Sample Output
// 8
// 2864
// 640403945

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
  const int N = 1000001;

  // 另一种解法参考：
  //                                      _  _
  // dp[i][1] = last blocks are separate | || |
  //                                   _ _
  // dp[i][0] = last blocks are fused |   |
  //
  // transition:
  //                    _  _    _  _    _  _    _  _
  //  _  _             | || |  |_|| |  | ||_|  |_||_|
  // | || | =>  s = 1  | || |, | || |, | || |, | || |
  //                    _ _
  //                   |_ _|
  //            s = 0  | | |
  //
  //                    _ _
  //  _ _              |_|_|
  // |   |  =>  s = 1  |   |
  //                    _ _    _ _
  //                   |   |  |_ _|
  //            s = 1  |   |, |   |

  // dp[i][1] = 4 * dp[i-1][1] +     dp[i-1][0]
  // dp[i][0] =     dp[i-1][1] + 2 * dp[i-1][0]

  vll dp(N);

  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 8;

  for (int i = 3; i < N; i++) {
    // NOTE: 神秘递推公式：https://oeis.org/A034999
    dp[i] = (6 * dp[i - 1] + (M - 7) * dp[i - 2]) % M;
  }

  takei(T);
  while (T--) {
    takei(n);
    cout << dp[n] << endl;
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
