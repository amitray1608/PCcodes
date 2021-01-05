#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int f[26] = {0};
    for(char c : s) 
      f[c - 'a']++;
    int two = 0, one = 0;
    for(int &i : f)  {
      one += i % 2;
      i /= 2;
    }
    int ans =  0;
    for(int &i : f) {
      if(i >= one) {
        i -= one;
        ans += one;
        one = 0;
      } else  {
        one -= i;
        ans += i;
        i = 0;
      }
      if(one == 0) break;
    }
    int sum = 0;
    for(int i : f) sum += i;
    ans += sum/3;
    cout << ans << '\n';
  }
  return 0;
}
