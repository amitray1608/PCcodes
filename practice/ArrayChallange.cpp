#include<bits/stdc++.h>

using namespace std;

string ArrayChallenge(int arr[], int arrLength) {
  string ans = "";
  map<pair<int, int>, int> mp;
  for(int i = 0; i < arrLength; i += 2) {
    int x = arr[i], y = arr[i + 1];
    if(mp.find(make_pair(y, x)) != mp.end()) {
      if(mp[make_pair(y, x)] == 0) {
        mp[make_pair(x, y)] = 1;
      } else {
        mp[make_pair(y, x)] = 0;
      }
    } else {
        mp[make_pair(x, y)] = 1;
    }
  }
  for(auto i : mp) {
    if(i.second == 1) {
      ans += to_string(i.first.first);
      ans += ",";
      ans += to_string(i.first.second);
      ans += ",";
    }
  }
  if(ans.back() == ',')
    ans.pop_back();
  if(ans.size() == 0)
    return "yes";
  else
    return ans;
}

void solve() {
  int a[] = {5, 4, 6, 7, 7, 6, 4, 5};
  int n = 8;
  cout << ArrayChallenge(a, n);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
//  cin >> t;
  while(t--){
//    cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
