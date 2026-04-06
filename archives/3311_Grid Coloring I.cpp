// You are given an n\times m grid where each cell contains one character A, B, C or D.
// For each cell, you must change the character to A, B, C or D. The new character must be different from the old one.
// Your task is to change the characters in every cell such that no two adjacent cells have the same character.
//
// Input
// The first line has two integers n and m: the number of rows and columns.
// The next n lines each have m characters: the description of the grid.
//
// Output
// Print n lines each with m characters: the description of the final grid.
// You may print any valid solution.
// If no solution exists, just print IMPOSSIBLE.
//
// Constraints
//
// 1 \le n, m \le 500

// Sample Input
// 3 4
// AAAA
// BBBB
// CCDD

// Sample Output
// CDCD
// DCDC
// ABAB

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define pb push_back
#define endl "\n"

void solve() {
  int n, m;
  cin >> n >> m;

  char cc[2][2] = {{'A', 'B'}, {'C', 'D'}};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      // 是 A B 就按奇偶换成 C D，是 C D 就按奇偶换成 A B
      cout << cc[c < 'C'][(i + j) % 2];
    }
    cout << endl;
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
