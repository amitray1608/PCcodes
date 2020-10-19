#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  string s;
  cin >> s;
  int n = (int) s.size();
  if(n < 9) {
    cout << 0 << endl;
    return;
  }
  vector<int> freq(n, 0);
  for(int i = n - 5 + 1; i >= 0; i--) {
    string x = s.substr(i, 5);
   //deb(x);
    if(s.substr(i, 5) == "START") 
      freq[i] = freq[i+1] + 1;
    else
      freq[i] = freq[i + 1];
  }
  ll count = 0;
  for(int i = 0; i < n - 4; i++) {
    string x = s.substr(i, 4);
    //deb(x);
    if(s.substr(i, 4) == "KICK") count += freq[i]; 
  }
  //for(int i : freq) cout << i << ' ';
  //cout << endl;
  cout << count << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
