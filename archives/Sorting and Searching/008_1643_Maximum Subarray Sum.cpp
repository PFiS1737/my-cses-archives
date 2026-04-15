// Given an array of n integers, your task is to find the maximum sum of values in a
// contiguous, nonempty subarray.
//
// Input
// The first input line has an integer n: the size of the array.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.
//
// Output
// Print one integer: the maximum subarray sum.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// -10^9 \le x_i \le 10^9

// clang-format off

// Sample Input
// 8
// -1 3 -2 5 3 -5 2 2

// Sample Output
// 9

// clang-format on

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define pb push_back
#define endl "\n"

void solve() {
  int n;
  cin >> n;

  ll sum = -1e9;
  ll best = -1e9;
  while (n--) {
    ll x;
    cin >> x;
    // NOTE: 如果 sum + x < x, 那么说明 sum 之前的值是负数，
    //       加到 x 上不可能生成比直接使用 x 更大的和，
    //       所以直接丢弃之前的 sum
    sum = max(sum + x, x);
    best = max(best, sum);
  }

  cout << best << endl;
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
