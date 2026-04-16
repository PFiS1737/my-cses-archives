// You are given a playlist of a radio station since its establishment. The playlist has a
// total of n songs. What is the longest sequence of successive songs where each song is
// unique?
//
// Input
// The first input line contains an integer n: the number of songs.
// The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
//
// Output
// Print the length of the longest sequence of unique songs.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le k_i \le 10^9

// clang-format off

// Sample Input
// 8
// 1 2 1 3 2 7 4 2

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

  int last = 0;
  int ans = 0;
  map<int, int> t; // 记录每个数上次出现的位置

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    last = max(last, t[x]);
    ans = max(ans, i - last);
    t[x] = i;
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
