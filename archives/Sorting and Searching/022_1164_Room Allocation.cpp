// There is a large hotel, and n customers will arrive soon. Each customer wants to have a
// single room. You know each customer's arrival and departure day. Two customers can stay
// in the same room if the departure day of the first customer is earlier than the arrival
// day of the second customer. What is the minimum number of rooms that are needed to
// accommodate all customers? And how can the rooms be allocated?
//
// Input
// The first input line contains an integer n: the number of customers.
// Then there are n lines, each of which describes one customer. Each line has two
// integers a and b: the arrival and departure day.
//
// Output
// Print first an integer k: the minimum number of rooms required.
// After that, print a line that contains the room number of each customer in the same
// order as in the input. The rooms are numbered 1,2,\ldots,k. You can print any valid
// solution.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le a \le b \le 10^9

// clang-format off

// Sample Input
// 3
// 1 2
// 2 4
// 4 4

// Sample Output
// 2
// 1 2 1 

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

struct Event {
  int t;
  enum { arrive, leave } ty;
  int i;

  bool operator<(const Event &other) const {
    if (t != other.t)
      return t < other.t;
    if (ty != other.ty)
      return ty < other.ty;
    return i < other.i;
  }
};

void solve() {
  int n;
  cin >> n;

  vector<Event> events;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    events.pb({a, Event::arrive, i});
    events.pb({b, Event::leave, i});
  }

  sort(events.begin(), events.end());

  vi rooms;
  int cnt = 0;
  vi ans(n);

  for (auto e : events) {
    if (e.ty == Event::arrive) {
      if (rooms.empty()) {
        ans[e.i] = ++cnt;
      } else {
        ans[e.i] = rooms.back();
        rooms.pop_back();
      }
    } else {
      rooms.pb(ans[e.i]);
    }
  }

  cout << cnt << endl;
  for (int i : ans) {
    cout << i << " ";
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
