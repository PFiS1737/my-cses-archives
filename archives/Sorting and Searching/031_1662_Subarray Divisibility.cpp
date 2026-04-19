// Given an array of n integers, your task is to count the number of subarrays where the
// sum of values is divisible by n.
//
// Input
// The first input line has an integer n: the size of the array.
// The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
//
// Output
// Print one integer: the required number of subarrays.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// -10^9 \le a_i \le 10^9

// clang-format off

// Sample Input
// 5
// 3 1 2 7 4

// Sample Output
// 1

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
  int n;
  cin >> n;

  // NOTE: let s(i) be the prefix sum (i.e., s(i) = sum of a[0..=i]),
  //       sum of a[l..=r] | n <==> s(r) mod n == s(l-1) mod n

  vi sums(n); // 各种前缀和 mod n 出现的次数
  sums[0] = 1;

  ll sum = 0;
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
    sum = (sum % n + n) % n;
    cnt += sums[sum];
    sums[sum]++;
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
