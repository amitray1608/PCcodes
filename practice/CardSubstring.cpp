
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
#define deb(x) cout << #x << " = " << x << endl;


signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  vector<int> fre(26, 0), have(26, 0);
  for (char c : t) {
    fre[c - 'a']++;
    have[c - 'a']++;
  }

  long long count = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    int x = s[i] - 'a';
    if (fre[x]) {
      count += i - j + 1;
      fre[x]--;
      continue;
    }
    while (j < i and fre[x] == 0) {
        fre[s[j] - 'a']++;
      j++;
    }
    
    if (fre[x]) {
      count += i - j + 1;
    } else j = i + 1; 
  }
  
  cout << count << '\n';

  return 0;
} //Hajimemashite
