// Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed
// on a k \times k chessboard so that they do not attack each other.
//
// Input
// The only input line contains an integer n.
//
// Output
// Print n integers: the results.
//
// Constraints
//
// 1 \le n \le 10000

// clang-format off

// Sample Input
// 8

// Sample Output
// 0
// 6
// 28
// 96
// 252
// 550
// 1056
// 1848

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void solve() {
  int n;
  cin >> n;

  for (ll k = 1; k <= n; k++) {
    // https://math.stackexchange.com/q/3266257
    ll k2 = k * k;
    cout << k2 * (k2 - 1) / 2 - 4 * (k - 1) * (k - 2) << endl;
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
