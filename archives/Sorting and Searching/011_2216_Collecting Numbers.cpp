// You are given an array that contains each number between 1 \dots n exactly once. Your
// task is to collect the numbers from 1 to n in increasing order. On each round, you go
// through the array from left to right and collect as many numbers as possible. What will
// be the total number of rounds?
//
// Input
// The first line has an integer n: the array size.
// The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
//
// Output
// Print one integer: the number of rounds.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5

// clang-format off

// Sample Input
// 5
// 4 2 1 5 3

// Sample Output
// 3

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

  vi arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[x] = i;
  }

  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (arr[i - 1] > arr[i])
      cnt++;
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
