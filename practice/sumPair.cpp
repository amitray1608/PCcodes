
#include<bits/stdc++.h>

using namespace std;

int main() {
  
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int &i : a) cin >> i;
  int sum;
  cin >> sum;
  
  for (int i = 0; i < n; i++) {
    int x = sum - a[i];
    if (mp.find(x) != mp.end()) {
      int c = mp[x];
      for (int j = 0; j < c; j++)
        cout << " (" << a[i] << ", " << x << ")";
    }
    mp[x]++;
    mp[a[i]]++;
  }

  return 0;
} //Hajimemashite
