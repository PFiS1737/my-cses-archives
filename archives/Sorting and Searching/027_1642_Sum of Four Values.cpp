// You are given an array of n integers, and your task is to find four values (at distinct
// positions) whose sum is x.
//
// Input
// The first input line has two integers n and x: the array size and the target sum.
// The second line has n integers a_1,a_2,\dots,a_n: the array values.
//
// Output
// Print four integers: the positions of the values. If there are several solutions, you
// may print any of them. If there are no solutions, print IMPOSSIBLE.
//
// Constraints
//
// 1 \le n \le 1000
// 1 \le x,a_i \le 10^9

// clang-format off

// Sample Input
// 8 15
// 3 2 5 8 1 3 2 3

// Sample Output
// 1 2 4 7

// clang-format on

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using mii = map<int, int>;

#define pb push_back
#define endl "\n"
#define M 1000000007

void solve() {
  int n, x;
  cin >> n >> x;

  vi a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<int, pii> mp;

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int need = x - a[i] - a[j];

      if (mp.count(need)) {
        auto [p, q] = mp[need];

        if (p != i && p != j && q != i && q != j) {
          cout << p << " " << q << " " << i << " " << j << endl;
          return;
        }
      }
    }

    for (int k = 1; k < i; k++) {
      mp[a[k] + a[i]] = {k, i};
    }
  }

  cout << "IMPOSSIBLE\n";
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
