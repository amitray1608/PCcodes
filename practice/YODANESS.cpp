
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    unordered_map<string, int> ordered;
    vector<string> s(n);
    for (auto &i : s) {
      cin >> i;
    }

    vector<string> ss(n);
    for (auto &i : ss) {
      cin >> i;
    }
    int curr = 0;
    for (int i = 0; i < n; i++) {
      ordered[ss[i]] = curr++;
    }
    
    vector<int> a;
    for (auto &i : s) {
      a.push_back(ordered[i]);
    }
    fenwick<int> f(n + 1);
    long long count = 0;
    for (int i = n - 1; i >= 0; i--) {
      count += f.get(a[i]);
      f.modify(a[i], 1);
    }
    cout << count << '\n';
  }	
  return 0;
} //Hajimemashite

