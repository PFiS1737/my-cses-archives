// You are given all numbers between 1,2,\ldots,n except one. Your task is to find the
// missing number.
//
// Input
// The first input line contains an integer n.
// The second line contains n-1 numbers. Each number is distinct and between 1 and n
// (inclusive).
//
// Output
// Print the missing number.
//
// Constraints
//
// 2 \le n \le 2 \cdot 10^5

// clang-format off

// Sample Input
// 5
// 2 3 1 5

// Sample Output
// 4

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void solve() {
  ll n;
  cin >> n;
  ll exp_sum = n * (n + 1) / 2;
  ll sum = 0;

  int i;
  while (--n) {
    cin >> i;
    sum += i;
  }

  cout << exp_sum - sum << endl;
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
