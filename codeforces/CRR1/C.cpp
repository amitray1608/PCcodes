//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int counta = 0, countb = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'B') {
      if(counta > 0) counta--;
      else if(countb > 0) countb--;
      else countb++;
    } else {
      counta++;
    }
  }
  cout << counta+countb << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
