//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  string s; 
  cin >> s;
  int count = 0, res = 0;
  for(int i = 0; i < n; i++) {
    int ii = (i - 1 + n) % n;
    if(s[i] == '<' and s[ii] == '>') count++;
    else if(s[i] == '>' and s[ii] == '<') count++;
  }
  for(int i = 0; i < n; i++) {
    int ii = (i - 1 + n) % n;
    if(s[i] == '-' or s[ii] == '-') res++;
    else if(s[i] == '>' and s[ii] == '>' and count == 0) res++;
    else if(s[i] == '<' and s[ii] == '<' and count == 0) res++;
  }
  cout << res << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
