// Given an array of n integers, your task is to calculate the number of subarrays that
// have at most k distinct values.
//
// Input
// The first input line has two integers n and k.
// The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
//
// Output
// Print one integer: the number of subarrays.
//
// Constraints
//
// 1 \le k \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 5 2
// 1 2 3 1 1

// Sample Output
// 10

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
  int n, k;
  cin >> n >> k;

  mii prev;
  set<pii> rank;
  ll cnt = 0;

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    rank.erase({prev[x], x});
    rank.insert({i, x});
    prev[x] = i;

    if ((ll)rank.size() > k + 1) {
      rank.erase(rank.begin());
    }

    if ((ll)rank.size() <= k) {
      cnt += i;
    } else {
      cnt += i - rank.begin()->first;
    }
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
