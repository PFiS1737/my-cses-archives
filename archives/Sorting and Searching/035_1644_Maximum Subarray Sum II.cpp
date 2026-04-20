// Given an array of n integers, your task is to find the maximum sum of values in a
// contiguous subarray with length between a and b.
//
// Input
// The first input line has three integers n, a and b: the size of the array and the
// minimum and maximum subarray length. The second line has n integers x_1,x_2,\dots,x_n:
// the array values.
//
// Output
// Print one integer: the maximum subarray sum.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le a \le b \le n
// -10^9 \le x_i \le 10^9

// clang-format off

// Sample Input
// 8 1 2
// -1 3 -2 5 3 -5 2 2

// Sample Output
// 8

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

// TODO: !!!

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<ll> sums;
  sums.push_back(0);
  multiset<ll> order;

  ll sum = 0;
  ll answer = -1e18;

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum += x;
    sums.push_back(sum);

    if (i >= a) {
      order.insert(sums[i - a]);
      answer = max(answer, sum - *order.begin());
    }

    if (i >= b) {
      order.erase(order.find(sums[i - b]));
    }
  }

  cout << answer << endl;
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
