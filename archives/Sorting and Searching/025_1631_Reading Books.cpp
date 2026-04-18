// There are n books, and Kotivalo and Justiina are going to read them all. For each book,
// you know the time it takes to read it. They both read each book from beginning to end,
// and they cannot read a book at the same time. What is the minimum total time required?
//
// Input
// The first input line has an integer n: the number of books.
// The second line has n integers t_1,t_2,\dots,t_n: the time required to read each book.
//
// Output
// Print one integer: the minimum total time.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le t_i \le 10^9

// clang-format off

// Sample Input
// 3
// 2 8 3

// Sample Output
// 16

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

  // NOTE: 1) 有一本书很长，读这本书的时间bi其他书的总和还要长
  //          那么最短时间是 2 倍的最长书的阅读时间。
  //          此时，一人先读最长的书，另一人读其他的书，然后互换。
  //       2) 否则，答案是所有书的阅读时间之和。
  //          因为两个人按阅读时间从长到短依次读书，注意，一人从最长的开始读，
  //          另一人从第二长的开始读，而将最长的放在最后读。

  ll total = 0;
  ll longest = 0;
  while (n--) {
    ll x;
    cin >> x;
    total += x;
    longest = max(longest, x);
  }

  cout << max(total, 2 * longest) << endl;
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
