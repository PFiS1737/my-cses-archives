// There is a street of length x whose positions are numbered 0,1,\ldots,x. Initially
// there are no traffic lights, but n sets of traffic lights are added to the street one
// after another. Your task is to calculate the length of the longest passage without
// traffic lights after each addition.
//
// Input
// The first input line contains two integers x and n: the length of the street and the
// number of sets of traffic lights. Then, the next line contains n integers
// p_1,p_2,\ldots,p_n: the position of each set of traffic lights. Each position is
// distinct.
//
// Output
// Print the length of the longest passage without traffic lights after each addition.
//
// Constraints
//
// 1 \le x \le 10^9
// 1 \le n \le 2 \cdot 10^5
// 0 < p_i < x

// clang-format off

// Sample Input
// 8 3
// 3 6 2

// Sample Output
// 5 3 3 

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
  int x, n;
  cin >> x >> n;

  set<int> pos = {0, x};   // 维护所有灯的位置
  multiset<int> len = {x}; // 维护所有区间长度

  while (n--) {
    int p;
    cin >> p;

    // 找到 p 后面的第一个灯的位置
    auto it = pos.upper_bound(p);

    int r = *it;
    int l = *--it;

    // 删除旧区间长度 [l, r]
    len.erase(len.find(r - l));

    // 插入新区间
    len.insert(p - l);
    len.insert(r - p);

    // 插入这个灯
    pos.insert(p);

    // 输出当前最大区间
    cout << *len.rbegin() << " ";
  }
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
