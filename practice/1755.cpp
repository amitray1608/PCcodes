#include<bits/stdc++.h>
fdafsfdfdfd
fdfdfdfd
fdusing namespace std;
fdafsfdfdfd
fdfdfdfdfdafsfdfdfd
fdfdfdfdfdafsfdfdfd
fdfdfdfdfdafsfdfdfd
fdfdfdfd
int main(fdafsfdfdfd
    fdfdfdfdfdafsfdfdfd
    fdfdfdfdfdafsfdfdfd
    fdfdfdfdfdafsfdfdfd
    fdfdfdfd) {
  string s;
  cin >> s;
  int n = s.size();
  int fre[26] = {0};
  for(char c : s)
    fre[c - 'a']++;
  char mid;
  int count = 0;
  for(int i = 0; i < 26; i++)
    if(fre[i]&1)
      count++, mid = (char)('A'+i);
  //cout << mid << endl;
  if(count > 1) cout << "NO SOLUTION";
  else {
    string ans = "";
    for(int i = 0; i < 26; i++) {
      if(fre[i]&1) continue;
      char x = (char)('A'+i);
      int c = 0;
      while(c < fre[i]/2)
        ans += to_string(x), c++;
    }
    if(n&1)
      ans += mid;
    string aa = ans;
    if(n&1)
      aa.pop_back();
    reverse(aa.begin(), aa.end());
    ans += aa;
    cout << ans;
  }
} //Hajimemashite

