// A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent
// elements whose difference is 1. Given n, construct a beautiful permutation if such a
// permutation exists.
//
// Input
// The only input line contains an integer n.
//
// Output
// Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions,
// you may print any of them. If there are no solutions, print "NO SOLUTION".
//
// Constraints
//
// 1 \le n \le 10^6

// clang-format off

// Sample Input
// 4

// Sample Output
// 2 4 1 3

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void solve() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "1\n";
    return;
  }

  if (n < 4) {
    cout << "NO SOLUTION\n";
    return;
  }

  int x = 2;
  while (x <= n) {
    cout << x << " ";
    x += 2;
  }

  x = 1;
  while (x <= n) {
    cout << x << " ";
    x += 2;
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
