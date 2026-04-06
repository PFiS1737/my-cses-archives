// A number spiral is an infinite grid whose upper-left square has number 1. Here are the
// first five layers of the spiral:
//
// Your task is to find out the number in row y and column x.
//
// Input
// The first input line contains an integer t: the number of tests.
// After this, there are t lines, each containing integers y and x.
//
// Output
// For each test, print the number in row y and column x.
//
// Constraints
//
// 1 \le t \le 10^5
// 1 \le y,x \le 10^9

// clang-format off

// Sample Input
// 3
// 2 3
// 1 1
// 4 2

// Sample Output
// 8
// 1
// 15

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void solve() {
  ll x, y;
  cin >> y >> x;

  if (x > y) {
    if (x % 2 == 1) {
      cout << x * x - y + 1;
    } else {
      cout << (x - 1) * (x - 1) + y;
    }
  } else {
    if (y % 2 == 0) {
      cout << y * y - x + 1;
    } else {
      cout << (y - 1) * (y - 1) + x;
    }
  }

  cout << "\n";
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
