
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  string s = "Hello World";
  string res = "";
  for (char c : s) {
    cout << (int)c;
    res += to_string((int)c);
  }
  cout << endl << res.size();
  return 0;
} //Hajimemashite

