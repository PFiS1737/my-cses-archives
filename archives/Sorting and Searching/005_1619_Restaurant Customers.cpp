// You are given the arrival and leaving times of n customers in a restaurant.
// What was the maximum number of customers in the restaurant at any time?
//
// Input
// The first input line has an integer n: the number of customers.
// After this, there are n lines that describe the customers. Each line has two integers a
// and b: the arrival and leaving times of a customer. You may assume that all arrival and
// leaving times are distinct.
//
// Output
// Print one integer: the maximum number of customers.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le a < b \le 10^9

// clang-format off

// Sample Input
// 3
// 5 8
// 2 4
// 3 9

// Sample Output
// 2

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

  vi a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int i = 0, j = 0;
  int cur = 0, ans = 0;

  while (i < n && j < n) {
    if (a[i] < b[j]) {
      cur++;
      i++;
    } else if (a[i] > b[j]) {
      cur--;
      j++;
    } else {
      i++;
      j++;
    }
    ans = max(ans, cur);
  }

  cout << ans << endl;
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
