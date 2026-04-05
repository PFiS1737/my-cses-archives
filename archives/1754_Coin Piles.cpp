// You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
// Your task is to efficiently find out if you can empty both the piles.
//
// Input
// The first input line has an integer t: the number of tests.
// After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.
//
// Output
// For each test, print "YES" if you can empty the piles and "NO" otherwise.
//
// Constraints
//
// 1 \le t \le 10^5
// 0 \le a, b \le 10^9

// Sample Input
// 3
// 2 1
// 2 2
// 3 3

// Sample Output
// YES
// NO
// YES

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b)
    swap(a, b);
  if (2 * a < b || (a + b) % 3 != 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
