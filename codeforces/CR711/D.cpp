
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  auto print = [&](int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    string inp;
    cin >> inp;
    return (inp == "Yes");
  };

  vector<vector<bool>> bi;
  priority_queue<array<int, 3>> pq;
  pq.push({0, 0, 0});
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (print(i, j) and print(j, i)) {
        pq.push({abs(a[i] - a[j]), i, j});   
      }
    }
  }
  cout << "! " << pq.top()[1] << ' ' << pq.top()[2] << endl; 
  return 0;
} //Hajimemashite

