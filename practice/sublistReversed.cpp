
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int fpos = 0, lpos = 0;
  bool ok = false;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1] and !ok) {
      fpos = i;
      ok = true;
    }
    if (a[i] > a[i + 1])
      lpos = i + 1;
  }
  
  while (fpos <= lpos) {
    swap(a[fpos++], a[lpos--]);
  }
  
  for (const int i : a) {
    cout << i << ' ';
  }
  cout << endl;

  return 0;
} //Hajimemashite
