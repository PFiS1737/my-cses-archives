// Your task is to construct an n \times n grid where each square has the smallest
// nonnegative integer that does not appear to the left on the same row or above on the
// same column.
//
// Input
// The only line has an integer n.
//
// Output
// Print the grid according to the example.
//
// Constraints
//
// 1 \le n \le 100

// clang-format off

// Sample Input
// 5

// Sample Output
// 0 1 2 3 4
// 1 0 3 2 5
// 2 3 0 1 6
// 3 2 1 0 7
// 4 5 6 7 0

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (i ^ j) << " \n"[j == n - 1];
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
