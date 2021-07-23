
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> left(l);
    vector<int> right(r);
    priority_queue<array<int, 2>> lpq, rpq;
    map<int, int> ml, mr;
    vector<array<int, 2>> a(n);
    int lcount = 0, rcount = 0;
    for (int &i : left) {
      cin >> i;
      i--;
      ml[i]++;
      a[i][0]++;
    }
    for (int &i : right) {
      cin >> i;
      i--;
      mr[i]++;
      a[i][1]++;
    }
    int j = 0;
    for (auto i : ml) {
      if (i.second > 0)
        lpq.push({i.second, i.first});
    }
    for (auto i : mr) {
      if (i.second > 0) 
        rpq.push({i.second, i.first});
    }
    for (int i = 0; i < n; i++) {
      if (a[i][0] + a[i][1] == 0) continue;
      int mini = min(a[i][0], a[i][1]);
      a[i][0] -= mini;
      a[i][1] -= mini;
      if (a[i][0] > a[i][1]) lcount += a[i][0];
      else rcount += a[i][1];
    }
    
    int mini = min(lcount, rcount);
    int count = mini;
    lcount -= mini;
    rcount -= mini;

    int rest = mini;
    for (int i = 0; i < n; i++) {
      if (lcount) {
        if (a[i][0] and mini and a[i][0] & 1) {
          a[i][0]--;
          mini--;
        }
      } else {
        if (a[i][1] and mini and a[i][1] & 1) {
          a[i][1]--;
          mini--;
        }
      }
    }
    int L = 0;
    for (int i = 0; i < n; i++) {
      if (lcount) {
        if (a[i][0]) {
          int x = min(mini, a[i][0]);
          mini -= x;
          a[i][0] -= x;
          count += a[i][0] / 2;
          if (a[i][0] & 1) L++; 
        }
      } else {
        if (a[i][1]) {
          int x = min(mini, a[i][1]);
          mini -= x;
          a[i][1] -= x;
          count += a[i][1] / 2;
          if (a[i][1] & 1) L++;
        }
      }
    }
    
    cout << count + L << '\n';
  }	
  return 0;
} //Hajimemashite

