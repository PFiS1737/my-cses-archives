// Given an array of n positive integers, your task is to count the number of subarrays
// having sum x.
//
// Input
// The first input line has two integers n and x: the size of the array and the target sum
// x. The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
//
// Output
// Print one integer: the required number of subarrays.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x,a_i \le 10^9

// clang-format off

// Sample Input
// 5 7
// 2 4 1 2 7

// Sample Output
// 3

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
  int n, x;
  cin >> n >> x;

  vi a(n);
  for (int &i : a)
    cin >> i;

  int l = 0, r = 0;
  int sum = a[0]; // sum of a[l..=r]
  int cnt = 0;

  while (l < n) {
    while (sum < x && r + 1 < n) {
      sum += a[++r];
    }

    if (sum == x) {
      cnt++;
    }

    sum -= a[l++];
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
