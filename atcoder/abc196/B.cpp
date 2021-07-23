
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  string s;
  cin >> s;
  for (char c : s) {
    if (c == '.') break;
    cout << c;
  }
  cout << '\n';
  return 0;
} //Hajimemashite

