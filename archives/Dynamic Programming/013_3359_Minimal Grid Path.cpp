// You are given an n \times n grid whose each square contains a letter.
// You should move from the upper-left square to the lower-right square. You can only move
// right or down. What is the lexicographically minimal string you can construct?
//
// Input
// The first line has an integer n: the size of the grid.
// After this, there are n lines that describe the grid. Each line has n letters between A
// and Z.
//
// Output
// Print the lexicographically minimal string.
//
// Constraints
//
// 1 \le n \le 3000

// clang-format off

// Sample Input
// 4
// AACA
// BABC
// ABDA
// AACA

// Sample Output
// AAABACA

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

  vs G(n);
  for (string &s : G)
    cin >> s;

  cout << G[0][0];

  vpii level = {{0, 0}};

  // 纯贪

  for (int i = 0; i < 2 * n - 2; i++) {
    vpii next_level;
    char min_letter = 'Z' + 1;

    auto update_next_level = [&](int y, int x) {
      if (y < n && x < n) {
        char letter = G[y][x];
        if (letter < min_letter) {
          next_level.clear();
          min_letter = letter;
        }
        if (letter == min_letter) {
          next_level.pb({y, x});
        }
      }
    };

    for (auto [y, x] : level) {
      update_next_level(y + 1, x);
      update_next_level(y, x + 1);
    }

    cout << min_letter;

    level = next_level;
    level.erase(unique(level.begin(), level.end()), level.end());
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
