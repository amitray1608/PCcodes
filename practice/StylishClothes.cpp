
#include<bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " = " << x << endl;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n0, n1, n2, n3;
  cin >> n0;
  vector<int> a(n0); 
  for (int i = 0; i < n0; i++) {
    cin >> a[i];
  }
  cin >> n1;
  vector<int> b(n1);
  for (int i = 0; i < n1; i++) {
    cin >> b[i];
  }
  cin >> n2;
  vector<int> c(n2);
  for (int i = 0; i < n2; i++) {
    cin >> c[i];
  }
  cin >> n3;
  vector<int> d(n3);
  for (int i = 0; i < n3; i++) {
    cin >> d[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  
  int j = 0, k = 0, l = 0;
  int f, s, t;
  f = s = t = INT_MAX;
  vector<int> ans;
  
  int maxin = INT_MAX;
  for (int i = 0; i < n0; i++) {
    int x = a[i];
    f = s = t = INT_MAX;
    while (j < n1 and abs(b[j] - x) <= f) {
      f = abs(b[j] - x);
      j++;
    }
    while (k < n2 and abs(c[k] - x) <= s) {
      s = abs(c[k] - x);
      k++;
    }
    while (l < n3 and abs(d[l] - x) <= t) {
      t = abs(d[l] - x);
      l++;
    }

    deb(j);
    deb(k);
    deb(l);
    vector<int> tmp = {x, b[j - 1], c[k - 1], d[l - 1]};

    sort (tmp.begin(), tmp.end());
    int maxi = tmp[3] - tmp[0];
    if (maxi < maxin) {
      ans = tmp;
      maxin = maxi;
    }
  }

  for (int i : ans) 
    cout << i << ' ';
  cout << '\n';

  return 0;
} //Hajimemashite
