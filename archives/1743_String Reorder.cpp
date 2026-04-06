// Your task is to reorder the characters of a string so that no two adjacent characters
// are the same. What is the lexicographically minimal such string?
//
// Input
// The only line has a string of length n consisting of characters A–Z.
//
// Output
// Print the lexicographically minimal reordered string where no two adjacent characters
// are the same. If it is not possible to create such a string, print -1.
//
// Constraints
//
// 1 \le n \le 10^6

// Sample Input
// clang-format off

// HATTIVATTI

// Sample Output
// AHATITITVT

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
  string s;
  cin >> s;

  int n = s.size();

  int cnt[30] = {0};

  for (char c : s) {
    cnt[c - 'A']++;
  }

  // NOTE: 关键 check：
  //       可以证明，使用 cnt 记录的词频，构造满足条件的序列（任意相邻两个字符不同），
  //       的充要条件为：2*maxn <= len+1，其中 maxn 为出现次数最多的字符的次数。
  auto check = [&](int len) {
    for (int i = 0; i < 26; i++) {
      if (cnt[i] * 2 > len + 1) {
        return false;
      }
    }
    return true;
  };

  if (!check(n)) {
    cout << -1 << endl;
    return;
  }

  char prev = -1;

  // 此处 i 指示此次循环将要构造出序列第 i 位
  for (int i = 1; i <= n; i++) {
    // 顺序遍历，以贪心地找到满足条件的最小字符
    for (int curr = 0; curr < 26; curr++) {
      if (!cnt[curr] || curr == prev) {
        continue;
      }

      // 尝试使用 curr 构造出第 i 位，看看剩下的字符能否构造出满足条件的序列
      cnt[curr]--;
      if (check(n - i)) {
        cout << char('A' + curr);
        prev = curr;
        break;
      }

      // 否则还原 cnt，继续尝试下一个字符
      cnt[curr]++;
    }
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
