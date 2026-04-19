// Given an array of n integers, count the number of subarrays where each element is
// distinct.
//
// Input
// The first line has an integer n: the array size.
// The second line has n integers x_1,x_2,\dots,x_n: the array contents.
//
// Output
// Print the number of subarrays with distinct elements.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 4
// 1 2 1 3

// Sample Output
// 8

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

  // INFO: 另见 013_1141, 求最长子数组长度

  int l = 0;
  ll cnt = 0;
  map<int, int> last;

  // NOTE: 我们计算以每个位置结尾的有效子数组的数量。
  //       这些值的总和就是问题的答案。
  //       变量 l 存储有效子数组的左侧位置。
  //       当遇到之前已在数组中出现过的数字时，我们会根据需要更新此变量。

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    l = max(l, last[x]);
    cnt += i - l;
    last[x] = i;
  }

  cout << cnt << endl;
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
