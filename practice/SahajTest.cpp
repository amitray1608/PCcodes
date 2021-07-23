
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    string p, e;
    cin >> p >> e;
    int freqP[26] = {0};
    int freqE[26] = {0};
    int sortP[26] = {0};
    int sortE[26] = {0};
    for (char c : p) {
      freqP[c - 'A']++;
      sortP[c - 'A']++;
    }
    for (char c : e) {
      freqE[c - 'A']++;
      sortE[c - 'A']++;
    }
    sort(sortE, sortE + 26);
    sort(sortP, sortP + 26);
    int ok = 0, count = 0, isThere = 0;
    for (int i = 0; i < 26; i++) {
      if (freqP[i] and !freqE[i]) {
        cout << "Spy" << '\n';
        continue;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (sortP[i] != sortE[i]) {
        cout << "Spy" << '\n';
        continue;
      }
    }
    
    
    cout << (ok == 3 ? "Agent" : "Spy") << '\n';
  }
  return 0;
}

