// Consider an infinite string that consists of all positive integers in increasing order:
// 12345678910111213141516171819202122232425...
// Your task is to process q queries of the form: what is the digit at position k in the string?
//
// Input
// The first input line has an integer q: the number of queries.
// After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.
//
// Output
// For each query, print the corresponding digit.
//
// Constraints
//
// 1 \le q \le 1000
// 1 \le k \le 10^{18}

// Sample Input
// 4
// 7
// 19
// 12
// 672274832941907421

// Sample Output
// 7
// 4
// 1
// 7

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define pb push_back
#define endl "\n"

void solve() {
  ll k;
  cin >> k;

  if (k < 10) {
    cout << k << endl;
    return;
  }

  k--;

  // i 为当前讨论的数字位数
  int i = 1;
  // m = 9 * 10^(i-1) 为当前位数的数字个数
  ll m = 9;
  while (m * i < k) {
    k -= m * i;
    i++;
    m *= 10;
  }

  // m / 9 = 10^(i-1) 是第 i 位数的起始数字
  // 定位到第 i 位数的第 k / i 个数字，
  string s = to_string(m / 9 + k / i);

  cout << s[k % i] << endl;
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
