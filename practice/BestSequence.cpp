#include<bits/stdc++.h>

using namespace std;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  string t;
  getline(cin, t);
  int n = 0, N = 1;
  for (char c : t) if (c == ' ') N++;
  vector<string> s;
  n = t.size();
  for (int i = 0; i < n; i++) {
    string x = "";
    while (i < n and t[i] != ' ') {
      x += t[i++];
    }
    s.push_back(x);
  }

  string p;
  getline(cin, p);
  string pat = "";
  for (char c : p)
    if (c != ' ') pat += c;

//  cout << pat << '\n';
//
//  for (string i : s) cout << i << '\n';
  
  do {
    
  } while (next_permutation(pat.begin(), pat.end()));

  return 0;
} //Hajimemashite
