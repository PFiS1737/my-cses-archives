// Your task is to calculate the number of bit strings of length n.
// For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
//
// Input
// The only input line has an integer n.
//
// Output
// Print the result modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 10^6

// Sample Input
// 3

// Sample Output
// 8

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back

void solve() {
  ull n;
  cin >> n;

  ull ans = 1;
  while (n--) {
    ans = ans * 2 % 1000000007;
  }

  cout << ans << "\n";
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
