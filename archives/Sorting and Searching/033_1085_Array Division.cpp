// You are given an array containing n positive integers.
// Your task is to divide the array into k subarrays so that the maximum sum in a subarray
// is as small as possible.
//
// Input
// The first input line contains two integers n and k: the size of the array and the
// number of subarrays in the division. The next line contains n integers
// x_1,x_2,\ldots,x_n: the contents of the array.
//
// Output
// Print one integer: the maximum sum in a subarray in the optimal division.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le k \le n
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 5 3
// 2 4 7 3 5

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

void solve() {
  int n, k;
  cin >> n >> k;

  vi x(n);
  for (int &i : x) {
    cin >> i;
  }

  // 检查是否可以将数组分割成 k 个子数组，使得每个子数组的和至多为 s
  // 从左到右贪心的最大化每个子数组的和。
  auto check = [&](ll s) {
    int p = 1;
    ll c = 0;
    for (int i = 0; i < n; i++) {
      if (x[i] > s)
        return false;
      c += x[i];
      if (c > s) {
        p++;
        c = x[i];
      }
    }
    return p <= k;
  };

  // 找到最大值 s ，使得无法创建子数组。那么问题的答案就是 s+1 。
  ll s = 0;
  for (ll b = 1e18; b >= 1; b /= 2) {
    while (!check(s + b))
      s += b;
  }

  cout << s + 1 << endl;
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
