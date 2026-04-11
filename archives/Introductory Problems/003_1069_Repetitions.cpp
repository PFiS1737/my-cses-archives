// You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your
// task is to find the longest repetition in the sequence. This is a maximum-length
// substring containing only one type of character.
//
// Input
// The only input line contains a string of n characters.
//
// Output
// Print one integer: the length of the longest repetition.
//
// Constraints
//
// 1 \le n \le 10^6

// clang-format off

// Sample Input
// ATTCGGGA

// Sample Output
// 3

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void solve() {
  string s;
  cin >> s;
  int max = 0;
  int cnt = 1;
  for (unsigned i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      max = std::max(max, cnt);
      cnt = 1;
    }
  }
  cout << std::max(max, cnt) << endl;
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
