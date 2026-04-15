// There are n sticks with some lengths. Your task is to modify the sticks so that each
// stick has the same length. You can either lengthen and shorten each stick. Both
// operations cost x where x is the difference between the new and original length. What
// is the minimum total cost?
//
// Input
// The first input line contains an integer n: the number of sticks.
// Then there are n integers: p_1,p_2,\ldots,p_n: the lengths of the sticks.
//
// Output
// Print one integer: the minimum total cost.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le p_i \le 10^9

// clang-format off

// Sample Input
// 5
// 2 3 1 5 2

// Sample Output
// 5

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

  vi arr(n);
  for (int &i : arr)
    cin >> i;

  sort(arr.begin(), arr.end());

  ll ans = 0;
  for (int i : arr) {
    ans += abs(i - arr[n / 2]);
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
