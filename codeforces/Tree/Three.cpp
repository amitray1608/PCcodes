#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n; cin >> n;
    string s, p;
    cin >> s >> p;
    int cf = 0, pf = 0, cz = 0, pz = 0;
    for(char c : s)
      if(c == '0') cf++; else cz++;
    for(char c : p) 
      if(c == '0') pf++; else pz++;
    
    if(pz != cz or cf != pf) {
      cout << "No" << '\n';
      continue;
    }
    
    int count = 1, z = 0, o = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] != p[i]) {
       if(s[i] == '0') o--;
       else o++;
      }

      if(z > o) count = 0;
    }
    if(count) {
      cout << "Yes" << '\n';
    } else
      cout << "No" << '\n';
  }
  return 0;
}

