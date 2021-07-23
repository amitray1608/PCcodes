
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  string a, b, c;
  cin >> a >> b >> c;
  set<char> st;
  for (char x : c) st.insert(x);
  for (char x : a) st.insert(x);
  for (char x : b) st.insert(x);
  vector<int> perm(10, 0);
  iota(perm.begin(), perm.end(), 0);
  int sz = st.size();
  if (sz >= 11) {
    cout << "UNSOLVABLE" << '\n';
    return 0;
  }
  int A = (int)a.size();
  int B = (int)b.size();
  int C = (int)c.size();
  do {
    map<char, int> mp;
    int j = 0;
    for (char x : st) {
      mp[x] = perm[j];
      j++;
    }
    if (a.size() >= 1 and mp[a[0]] == 0) continue;
    if (b.size() >= 1 and mp[b[0]] == 0) continue;
    if (c.size() >= 1 and mp[c[0]] == 0) continue;
    int suma = 0, sumb = 0, sumc = 0;
    j = 0;
    for (char x : a) {
      suma += mp[x] * pow(10, A - j - 1);
      j++;
    }
    j = 0;
    for (char x : b) {
      sumb += mp[x] * pow(10, B - j - 1);
      j++;
    }
    j = 0;
    for (char x : c) {
      sumc += mp[x] * pow(10, C - j - 1);
      j++;
    }
    if (suma + sumb == sumc) {
      cout << suma << '\n';
      cout << sumb << '\n';
      cout << sumc << '\n';
      return 0;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  cout << "UNSOLVABLE" << '\n';
  return 0;
} //Hajimemashite

