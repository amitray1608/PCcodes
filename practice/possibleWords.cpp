
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  string s; cin >> s;
  int n; cin >> n;
  set<string> st;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    st.insert(t);
  }

  vector<string> res;
  
  function<void(string, string)> recc = [&](string t, string ans) {
    if (t.length() == 0) {
      ans.pop_back();
      res.push_back(ans);
      return;
    }
    for (int i = 0; i < (int)t.length(); i++) {
      string pre = t.substr(0, i + 1);
      string suf = t.substr(i + 1);
      if (st.find(pre) != st.end()) {
        recc(suf, ans + pre + " ");
      }
    }
  };

  recc(s, "");
  for (auto i : res) {
    cout << i << ' ';
  }

  return 0;
}

