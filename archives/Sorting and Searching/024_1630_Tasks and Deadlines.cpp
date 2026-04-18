// You have to process n tasks. Each task has a duration and a deadline, and you will
// process the tasks in some order one after another. Your reward for a task is d-f where
// d is its deadline and f is your finishing time. (The starting time is 0, and you have
// to process all tasks even if a task would yield negative reward.) What is your maximum
// reward if you act optimally?
//
// Input
// The first input line has an integer n: the number of tasks.
// After this, there are n lines that describe the tasks. Each line has two integers a and
// d: the duration and deadline of the task.
//
// Output
// Print one integer: the maximum reward.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le a,d \le 10^6

// clang-format off

// Sample Input
// 3
// 6 10
// 8 15
// 5 12

// Sample Output
// 2

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

  vector<pii> tasks(n);
  for (auto &[du, end] : tasks) {
    cin >> du >> end;
  }

  // NOTE: 可以证明先执行持续时间短的任务是最优的

  sort(tasks.begin(), tasks.end());

  ll time = 0;
  ll ans = 0;
  for (auto [du, end] : tasks) {
    time += du;
    ans += (ll)end - time;
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
