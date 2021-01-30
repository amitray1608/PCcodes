#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  double w;
  cin >> n >> w;
  vector<array<double, 2>> a(n);
  priority_queue<array<double, 3>> pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    pq.push({a[i][0]/a[i][1], a[i][0], a[i][1]});
  }

  double value = 0.0;
  while(w > 0 and !pq.empty()) {
    auto x = pq.top();
    pq.pop();
    if(x[2] <= w) {
      value += x[1];
      w -= x[2];
    } else {
      value += w * x[0];
      w = 0;
    }
  }
  cout << fixed << setprecision(4) << value << '\n';
  return 0;
}
