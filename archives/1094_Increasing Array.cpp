// You are given an array of n integers. You want to modify the array so that it is
// increasing, i.e., every element is at least as large as the previous element. On each
// move, you may increase the value of any element by one. What is the minimum number of
// moves required?
//
// Input
// The first input line contains an integer n: the size of the array.
// Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the
// array.
//
// Output
// Print the minimum number of moves.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 10
// 6 10 4 10 2 8 9 2 7 7

// Sample Output
// 31

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void solve() {
  int n;
  cin >> n;
  ll max;
  cin >> max;
  ll a;
  ll ans = 0;
  while (--n) {
    cin >> a;
    ans += std::max(0ll, max - a);
    max = std::max(max, a);
  }
  cout << ans << "\n";
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
